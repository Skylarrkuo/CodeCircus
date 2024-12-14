## 一、YOLOv10前言

![img](https://i-blog.csdnimg.cn/direct/784db76741b241e6bf4b4e8de125a0ce.png)

**论文地址：**https://arxiv.org/abs/2405.14458

**代码地址：**https://github.com/THU-MIG/yolov10

**摘要：****在过去的几年里，YOLO 已成为实时目标检测领域的主要范式，因为它们在计算成本和检测性能之间取得了有效的平衡。研究人员探索了 YOLO 的架构设计、优化目标、数据增强策略等，取得了显著进展。但是，对非极大值抑制 （NMS） 进行后处理的依赖阻碍了 YOLO 的端到端部署，并对推理延迟产生了不利影响。此外，YOLO 中各种组件的设计缺乏全面彻底的检查，导致明显的计算冗余并限制了模型的能力。它使效率不理想，并且具有相当大的性能改进潜力。在这项工作中，我们的目标是从后处理和模型架构进一步推进 YOLO 的性能-效率边界。为此，我们首先提出了 YOLO 的无 NMS 训练的一致双分配，它同时带来了有竞争力的性能和低推理延迟。此外，我们还引入了 YOLO 的整体效率-精度驱动的模型设计策略。我们从效率和准确率两个角度对 YOLO 的各个组件进行了全面优化，大大降低了计算开销，增强了能力。我们努力的成果是用于实时端到端对象检测的新一代 YOLO 系列，称为 YOLOv10。大量实验表明，YOLOv10 在各种模型规模上实现了最先进的性能和效率。例如，我们的 YOLOv10-S 比 COCO 上同类 AP 下的 RT-DETR-R18 快 1.8×同时参数和 FLOP 数量减少了 2.8×。与 YOLOv9-C 相比，YOLOv10-B 在同等性能下延迟降低了 46%，参数减少了 25%。**

### **1.1 YOLOv10模型整体网络结构图**

![img](https://i-blog.csdnimg.cn/direct/f1ad03cddb9f423fa7e1202df7ffd812.png)

### 1.2 环境搭建

```python
conda create -n yolov10 python=3.9
conda activate yolov10
```

### 1.3数据集获取

[免费获取yolo数据集的网站 ：https://universe.roboflow.com/](https://universe.roboflow.com/)

**数据集的目录结构：**

![img](https://i-blog.csdnimg.cn/direct/d792581df7864ce4b3fcaeff09062bfe.png)



**修改数据集配置文件data.yaml：**

```python
# Train/val/test sets as 1) dir: path/to/imgs, 2) file: path/to/imgs.txt, or 3) list: [path/to/imgs1, path/to/imgs2, ..]
path: data_name  # dataset root dir 自己数据集的文件夹名称

train: images/train  # train images (relative to 'path') 4 images
val: images/val # val images (relative to 'path') 4 images
test: images/test  # test images (optional)

# number of classes
nc: 1
# Classes
names:
  0: A
```

###  1.4 yolov10项目代码获取

![img](https://i-blog.csdnimg.cn/direct/f80b34fdcbce44b78b56c5b733fa24c9.png)

 **yolov10项目下载好了，使用pycharm软件打开项目，然后在终端j执行以下命名：**

```python
conda activate yolov10 #先激活自己的虚拟环境
pip install -r requirements.txt
pip install ultralytics
```

## **二、`yolov10.yaml`配置文件进行详细讲解**



**看过我之前那个yolov8详解博客，yolov10与yolov8相似，配置文件主要分为三个部分: `参数部分【Parameters】，主干部分【backone】，头部部分【head】`。下面分别对这几个部分进行详细说明。**

**关于YOLOv10网络的配置文件`yolov10n.yaml`的详细内容如下：**

```python
# Parameters
nc: 80 # number of classes
scales: # model compound scaling constants, i.e. 'model=yolov8n.yaml' will call yolov8.yaml with scale 'n'
  # [depth, width, max_channels]
  n: [0.33, 0.25, 1024] 

# YOLOv8.0n backbone
backbone:
  # [from, repeats, module, args]
  - [-1, 1, Conv, [64, 3, 2]] # 0-P1/2
  - [-1, 1, Conv, [128, 3, 2]] # 1-P2/4
  - [-1, 3, C2f, [128, True]]
  - [-1, 1, Conv, [256, 3, 2]] # 3-P3/8
  - [-1, 6, C2f, [256, True]]
  - [-1, 1, SCDown, [512, 3, 2]] # 5-P4/16
  - [-1, 6, C2f, [512, True]]
  - [-1, 1, SCDown, [1024, 3, 2]] # 7-P5/32
  - [-1, 3, C2f, [1024, True]]
  - [-1, 1, SPPF, [1024, 5]] # 9
  - [-1, 1, PSA, [1024]] # 10

# YOLOv8.0n head

head:
  - [-1, 1, nn.Upsample, [None, 2, "nearest"]]
  - [[-1, 6], 1, Concat, [1]] # cat backbone P4
  - [-1, 3, C2f, [512]] # 13
  - [-1, 1, nn.Upsample, [None, 2, "nearest"]]
  - [[-1, 4], 1, Concat, [1]] # cat backbone P3
  - [-1, 3, C2f, [256]] # 16 (P3/8-small)
  - [-1, 1, Conv, [256, 3, 2]]
  - [[-1, 13], 1, Concat, [1]] # cat head P4
  - [-1, 3, C2f, [512]] # 19 (P4/16-medium)
  - [-1, 1, SCDown, [512, 3, 2]]
  - [[-1, 10], 1, Concat, [1]] # cat head P5
  - [-1, 3, C2fCIB, [1024, True, True]] # 22 (P5/32-large)
  - [[16, 19, 22], 1, v10Detect, [nc]] # Detect(P3, P4, P5)
```

### 2.1 参数部分【Parameters】

```python
# Parameters
nc: 80 # number of classes

scales: # model compound scaling constants, i.e. 'model=yolov8n.yaml' will call yolov8.yaml with scale 'n'
  # [depth, width, max_channels]
  n: [0.33, 0.25, 1024] 
```

- **`nc: 80 `指的是数据集中的类别数量。**
- **`scales: `代表模型尺寸，分了n,s,m,l,x这5个不同大小的尺寸，参数量依次从小到大。**
- **`[depth, width, max_channels]:`分别表示`网络模型的深度因子`、`网络模型的宽度因子`、`最大通道数`。**
- **`depth深度因子的作用`：表示模型中`重复模块的数量或层数的缩放比例`。这里主要用来调整`C2f`模块中的子模块`Bottelneck`重复次数。比如主干中第一个`C2f`模块的`number`系数是`3`，我们使用`0.33x3`并且向上取整就等于`1`了，这就代表第一个`C2f`模块中`Bottelneck`只重复一次；**
- **`width宽度因子的作用`：表示模型中`通道数（即特征图的深度）的缩放比例`,如果某个层原本有64个通道，而width设置为0.5，则该层的通道数变为32。比如使用`yolov8n.yaml`文件，参数为`[0.33, 0.25, 1024]`。第一个`Conv`模块的输出通道数写的是`64`，但是实际上这个通道数并不是`64`，而是使用宽度因子 `0.25x64`得到的最终结果`16`；同理，`C2f`模块的输出通道虽然在`yaml`文件上写的是`128`，但是在实际使用时依然要乘上宽度因子`0.25`，那么第一个`C2f`模块最终的到实际通道数就是`0.25x128 = 32`。如下图所示，其他的依次类推。**
- **`max-channels: `表示每层最大通道数。每层的通道数会与这个参数进行一个对比，如果特征图通道数大于这个数，那就取 `max_channels`的值。**

### 2.2 主干部分【backbone】 

```python
backbone:

  # [from, repeats, module, args]
  - [-1, 1, Conv, [64, 3, 2]] # 0-P1/2
  - [-1, 1, Conv, [128, 3, 2]] # 1-P2/4
  - [-1, 3, C2f, [128, True]]
  - [-1, 1, Conv, [256, 3, 2]] # 3-P3/8
  - [-1, 6, C2f, [256, True]]
  - [-1, 1, SCDown, [512, 3, 2]] # 5-P4/16
  - [-1, 6, C2f, [512, True]]
  - [-1, 1, SCDown, [1024, 3, 2]] # 7-P5/32
  - [-1, 3, C2f, [1024, True]]
  - [-1, 1, SPPF, [1024, 5]] # 9
  - [-1, 1, PSA, [1024]] # 10
```

**主干部分有四个参数`[from, number, module, args] `，解释如下：**

- **`from`：这个参数代表从哪一层获得输入，`-1`就表示从上一层获得输入，`[-1, 6]`就表示从上一层和第`6`层这两层获得输入。第一层比较特殊，这里第一层上一层 没有输入，`from`默认`-1`就好了。**
- **`number`：这个参数表示模块重复的次数，如果为`3`则表示该模块重复`3`次，这里并不一定是这个模块的重复次数，也有可能是这个模块中的子模块重复的次数。对于`C2f`模块来说，这个`number`就代表`C2f`中`Bottelneck`模块重复的次数。**
- **`module`：这个就代表你这层使用的模块的名称，比如你第一层使用了`Conv`模块，第二层使用了`C2f`模块。**
- **`args`：表示这个模块需要传入的参数，`第一个参数均表示该层的输出通道数`。对于第一层conv参数`【64,3，2】`：64代表输出通道数，3代表卷积核大小k，2代表stride步长。`每层输入通道数，默认是上一层的输出通道数。`**

***其他说明：各层注释中的`P1/2`表示该层特征图缩放为输入图像尺寸的`1/2`，是第`1`特征层；`P2/4`表示该层特征图缩放为输入图像尺寸的`1/4`，是第2特征层；其他的依次类推。*** 

###  **2.3 头部【`head`】**

```python
head:
  - [-1, 1, nn.Upsample, [None, 2, "nearest"]]
  - [[-1, 6], 1, Concat, [1]] # cat backbone P4
  - [-1, 3, C2f, [512]] # 13

  - [-1, 1, nn.Upsample, [None, 2, "nearest"]]
  - [[-1, 4], 1, Concat, [1]] # cat backbone P3
  - [-1, 3, C2f, [256]] # 16 (P3/8-small)


  - [-1, 1, Conv, [256, 3, 2]]
  - [[-1, 13], 1, Concat, [1]] # cat head P4
  - [-1, 3, C2f, [512]] # 19 (P4/16-medium)

  - [-1, 1, SCDown, [512, 3, 2]]
  - [[-1, 10], 1, Concat, [1]] # cat head P5
  - [-1, 3, C2fCIB, [1024, True, True]] # 22 (P5/32-large)
  - [[16, 19, 22], 1, v10Detect, [nc]] # Detect(P3, P4, P5)
```

**头部分有四个参数`[from, number, module, args] `，解释如下：**

- **`from`：这个参数代表从哪一层获得输入，`-1`就表示从上一层获得输入，`[-1, 6]`就表示从上一层和第`6`层这两层获得输入。第一层比较特殊，这里第一层上一层 没有输入，`from`默认`-1`就好了。**
- **`number`：这个参数表示模块重复的次数，如果为`3`则表示该模块重复`3`次，这里并不一定是这个模块的重复次数，也有可能是这个模块中的子模块重复的次数。对于`C2f`模块来说，这个`number`就代表`C2f`中`Bottelneck`模块重复的次数。**
- **`module`：这个就代表你这层使用的模块的名称，比如你第一层使用了`Conv`模块，第二层使用了`C2f`模块。**
- **`args`：表示这个模块需要传入的参数，`第一个参数均表示该层的输出通道数`。`每层输入通道数，默认是上一层的输出通道数。`**

**这部分主要多出3个操作`nn.Upsample`、`Concat`、`Detect`,解释如下：**

***\*`nn.Upsample`:\**表示上采样，将特征图大小进行翻倍操作。比如将大小为20X20的特征图，变为40X40的特征图大小。**

***\*`Concat`：\**代表拼接操作，将相同大小的特征图，通道进行拼接，要求是特征图大小一致，通道数可以不相同。例如[-1, 6]：`-1`代表上一层，`6`代表第六层（从第`0`层开始数），将上一层与第6层进行concat拼接操作。**

***\*`v10Detect`\**的`from`有三个数： `16`，`18`，`22`，这三个就是最终网络的输出特征图，分别对应`P3`，`P4`，`P5`。**



**模型训练时打印出的结构参数如下，下图为`yolov10n.yaml`打印信息：**

![img](https://i-blog.csdnimg.cn/direct/9605114f00374cc8a9b7d984197735a9.png)



##  三、YOLOv10模型训练参数详细解析 

**关于yolov10的训练参数该如何设置。接下来对yolov10的相关训练参数和使用方法进行了详细说明。希望对大家有所帮助！** 

### 3.1 YOLOv10模型训练代码

**YOLOv10模型训练时使用的代码如下：**

```python
from ultralytics import YOLOv10
import warnings

warnings.filterwarnings('ignore')
# 模型配置文件
model_yaml_path = r"E:\yolo\yolov10\ultralytics\cfg\models\v10\yolov10n.yaml"
#数据集配置文件
data_yaml_path = r'E:\yolo\yolov10\datasets\data.yaml'

#预训练模型
pre_model_name = 'yolov10n.pt'

if __name__ == '__main__':
    # #加载预训练模型
    # model = YOLOv10(model_yaml_path).load(pre_model_name)
    # 不加载预训练模型
    model = YOLOv10(model_yaml_path)
    #训练模型
    results = model.train(data=data_yaml_path,
                          imgsz=640,
                          epochs=200,
                          batch=4,
                          workers=0,
                          optimizer='SGD',  # using SGD
                          amp=False,  # 如果出现训练损失为Nan可以关闭amp
                          project='runs/V10train',
                          name='exp',
                          )
```

### 3.2 模型大小选择

**`model = YOLOv10("yolov10n.pt") `表示使用的是v10n模型来训练。如果想使用其他大小的模型，只需要把n改为其他大小的对应字母即可。例如：** 

```python
model = YOLOv10("yolov10n.pt")

model = YOLOv10("yolov10s.pt")

model = YOLOv10("yolov10m.pt")

model = YOLOv10("yolov10b.pt")

model = YOLOv10("yolov10l.pt")

model = YOLOv10("yolov10x.pt")
```

**不同模型参数大小如下，v10n是参数量最小的模型。`一般情况下，模型越大，最终模型的性能效果也会越好。`可根据自己实际需求选择相应的模型大小进行训练。**

![img](https://i-blog.csdnimg.cn/direct/a252ee4d51454473a332eff0d2447bc9.png)

![img](https://i-blog.csdnimg.cn/direct/35947118839946c3967f5d90f137c20c.png)

### 3.3 训练参数设置

**通过运行\**`model.train(data="data.yaml", epochs=100, batch=4)`训练v8模型，其中`(data="data.yaml", epochs=100, batch=4)`\**是训练设置的参数,`没有添加的训练参数都是使用的默认值`。官方其实给出了很多其他相关参数，详细说明见下文。**

**如果我们需要自己修改其他训练参数，只需要在`train`后面的括号中加入相应的参数和具体值即可。**

**例如加上模型训练优化器参数`optimizer`,其默认值是`auto`。**

**可设置的值为：\**SGD, Adam, Adamax, AdamW, NAdam, RAdam, RMSProp, auto\**。常用`SGD`或者`AdamW`。**

**我们可以直接将其设置为`SGD`，写法如下：**

```python
# 模型训练，添加模型优化器设置
results = model.train(data="data.yaml", epochs=100, batch=4, optimizer='SGD')
```

### **3.4 训练参数说明**

**`YOLOv10 模型的训练设置包括训练过程中使用的各种超参数和配置`。这些设置会影响模型的性能、速度和准确性。关键的训练设置包括批量大小、学习率、动量和权重衰减。此外，优化器、损失函数和训练数据集组成的选择也会影响训练过程。对这些设置进行仔细的调整和实验对于优化性能至关重要。以下是官方给出了训练可设置参数和说明:**

|     **参数**      | **默认值** |                           **说明**                           |
| :---------------: | :--------: | :----------------------------------------------------------: |
|      `model`      |   `None`   | 指定用于训练的模型文件。接受指向 `.pt` 预训练模型或 `.yaml` 配置文件。对于定义模型结构或初始化权重至关重要。 |
|      `data`       |   `None`   | 数据集配置文件的路径（例如 `coco8.yaml`).该文件包含特定于数据集的参数，包括训练数据和验证数据的路径、类名和类数。 |
|     `epochs`      |   `100`    | 训练总轮数。每个epoch代表对整个数据集进行一次完整的训练。调整该值会影响训练时间和模型性能。 |
|      `time`       |   `None`   | 最长训练时间（小时）。如果设置了该值，则会覆盖 `epochs` 参数，允许训练在指定的持续时间后自动停止。对于时间有限的训练场景非常有用。 |
|    `patience`     |   `100`    | 在验证指标没有改善的情况下，提前停止训练所需的epoch数。当性能趋于平稳时停止训练，有助于防止过度拟合。 |
|      `batch`      |    `16`    | 批量大小，有三种模式:设置为整数(例如，' Batch =16 ')， 60% GPU内存利用率的自动模式(' Batch =-1 ')，或指定利用率分数的自动模式(' Batch =0.70 ')。 |
|      `imgsz`      |   `640`    | 用于训练的目标图像尺寸。所有图像在输入模型前都会被调整到这一尺寸。影响模型精度和计算复杂度。 |
|      `save`       |   `True`   | 可保存训练检查点和最终模型权重。这对恢复训练或模型部署非常有用。 |
|   `save_period`   |    `-1`    | 保存模型检查点的频率，以 epochs 为单位。值为-1 时将禁用此功能。该功能适用于在长时间训练过程中保存临时模型。 |
|      `cache`      |  `False`   | 在内存中缓存数据集图像 (`True`/`ram`）、磁盘 (`disk`），或禁用它 (`False`).通过减少磁盘 I/O 提高训练速度，但代价是增加内存使用量。 |
|     `device`      |   `None`   | 指定用于训练的计算设备：单个 GPU (`device=0`）、多个 GPU (`device=0,1`)、CPU (`device=cpu`)，或苹果芯片的 MPS (`device=mps`). |
|     `workers`     |    `8`     | 加载数据的工作线程数（每 `RANK` 多 GPU 训练）。影响数据预处理和输入模型的速度，尤其适用于多 GPU 设置。 |
|     `project`     |   `None`   |   保存训练结果的项目目录名称。允许有组织地存储不同的实验。   |
|      `name`       |   `None`   | 训练运行的名称。用于在项目文件夹内创建一个子目录，用于存储训练日志和输出结果。 |
|    `exist_ok`     |  `False`   | 如果为 True，则允许覆盖现有的项目/名称目录。这对迭代实验非常有用，无需手动清除之前的输出。 |
|   `pretrained`    |   `True`   | 决定是否从预处理模型开始训练。可以是布尔值，也可以是加载权重的特定模型的字符串路径。提高训练效率和模型性能。 |
|    `optimizer`    |  `'auto'`  | 为训练模型选择优化器。选项包括 `SGD`, `Adam`, `AdamW`, `NAdam`, `RAdam`, `RMSProp` 等，或 `auto` 用于根据模型配置进行自动选择。影响收敛速度和稳定性 |
|     `verbose`     |  `False`   | 在训练过程中启用冗长输出，提供详细日志和进度更新。有助于调试和密切监控培训过程。 |
|      `seed`       |    `0`     | 为训练设置随机种子，确保在相同配置下运行的结果具有可重复性。 |
|  `deterministic`  |   `True`   | 强制使用确定性算法，确保可重复性，但由于对非确定性算法的限制，可能会影响性能和速度。 |
|   `single_cls`    |  `False`   | 在训练过程中将多类数据集中的所有类别视为单一类别。适用于二元分类任务，或侧重于对象的存在而非分类。 |
|      `rect`       |  `False`   | 可进行矩形训练，优化批次组成以减少填充。这可以提高效率和速度，但可能会影响模型的准确性。 |
|     `cos_lr`      |  `False`   | 利用余弦学习率调度器，根据历时的余弦曲线调整学习率。这有助于管理学习率，实现更好的收敛。 |
|  `close_mosaic`   |    `10`    | 在训练完成前禁用最后 N 个epoch的马赛克数据增强以稳定训练。设置为 0 则禁用此功能。 |
|     `resume`      |  `False`   | 从上次保存的检查点恢复训练。自动加载模型权重、优化器状态和历时计数，无缝继续训练。 |
|       `amp`       |   `True`   | 启用自动混合精度 (AMP) 训练，可减少内存使用量并加快训练速度，同时将对精度的影响降至最低。 |
|    `fraction`     |   `1.0`    | 指定用于训练的数据集的部分。允许在完整数据集的子集上进行训练，这对实验或资源有限的情况非常有用。 |
|     `profile`     |  `False`   | 在训练过程中，可对ONNX 和TensorRT 速度进行剖析，有助于优化模型部署。 |
|     `freeze`      |   `None`   | 冻结模型的前 N 层或按索引指定的层，从而减少可训练参数的数量。这对微调或迁移学习非常有用。 |
|       `lr0`       |   `0.01`   | 初始学习率（即 `SGD=1E-2`, `Adam=1E-3`) .调整这个值对优化过程至关重要，会影响模型权重的更新速度。 |
|       `lrf`       |   `0.01`   | 最终学习率占初始学习率的百分比 = (`lr0 * lrf`)，与调度程序结合使用，随着时间的推移调整学习率。 |
|    `momentum`     |  `0.937`   | 用于 SGD 的动量因子，或用于 Adam 优化器的 beta1，用于将过去的梯度纳入当前更新。 |
|  `weight_decay`   |  `0.0005`  |       L2 正则化项，对大权重进行惩罚，以防止过度拟合。        |
|  `warmup_epochs`  |   `3.0`    | 学习率预热的历元数，学习率从低值逐渐增加到初始学习率，以在早期稳定训练。 |
| `warmup_momentum` |   `0.8`    |      热身阶段的初始动力，在热身期间逐渐调整到设定动力。      |
| `warmup_bias_lr`  |   `0.1`    |   热身阶段的偏置参数学习率，有助于稳定初始历元的模型训练。   |
|       `box`       |   `7.5`    | 损失函数中边框损失部分的权重，影响对准确预测边框坐标的重视程度。 |
|       `cls`       |   `0.5`    | 分类损失在总损失函数中的权重，影响正确分类预测相对于其他部分的重要性。 |
|       `dfl`       |   `1.5`    |      分布焦点损失权重，在某些YOLO 版本中用于精细分类。       |
|      `pose`       |   `12.0`   | 姿态损失在姿态估计模型中的权重，影响着准确预测姿态关键点的重点。 |
|      `kobj`       |   `2.0`    | 姿态估计模型中关键点对象性损失的权重，平衡检测可信度与姿态精度。 |
| `label_smoothing` |   `0.0`    | 应用标签平滑，将硬标签软化为目标标签和标签均匀分布的混合标签，可以提高泛化效果。 |
|       `nbs`       |    `64`    |                用于损耗正常化的标称批量大小。                |
|  `overlap_mask`   |   `True`   |  决定在训练过程中分割掩码是否应该重叠，适用于实例分割任务。  |
|   `mask_ratio`    |    `4`     |       分割掩码的下采样率，影响训练时使用的掩码分辨率。       |
|     `dropout`     |   `0.0`    | 分类任务中正则化的丢弃率，通过在训练过程中随机省略单元来防止过拟合。 |
|       `val`       |   `True`   | 可在训练过程中进行验证，以便在单独的数据集上对模型性能进行定期评估。 |
|      `plots`      |  `False`   | 生成并保存训练和验证指标图以及预测示例图，以便直观地了解模型性能和学习进度。 |

**常用的几个训练参数是: \**`数据集配置文件data`、`训练轮数epochs`、`训练批次大小batch`、`训练使用的设备device`,`模型优化器optimizer`、`初始学习率lr0`。\*