# YoloV10官方教程文档

**YOLOv10** 的官方 PyTorch 实现。

## 性能
COCO 数据集

| 模型 | 测试尺寸 | 参数数量 | FLOPs | AP<sup>val</sup> | 延迟 |
|:---------------|:----:|:---:|:--:|:--:|:--:|
| [YOLOv10-N](https://huggingface.co/jameslahm/yolov10n) |   640  |     2.3M    |   6.7G   |     38.5%     | 1.84ms |
| [YOLOv10-S](https://huggingface.co/jameslahm/yolov10s) |   640  |     7.2M    |   21.6G  |     46.3%     | 2.49ms |
| [YOLOv10-M](https://huggingface.co/jameslahm/yolov10m) |   640  |     15.4M   |   59.1G  |     51.1%     | 4.74ms |
| [YOLOv10-B](https://huggingface.co/jameslahm/yolov10b) |   640  |     19.1M   |  92.0G |     52.5%     | 5.74ms |
| [YOLOv10-L](https://huggingface.co/jameslahm/yolov10l) |   640  |     24.4M   |  120.3G   |     53.2%     | 7.28ms |
| [YOLOv10-X](https://huggingface.co/jameslahm/yolov10x) |   640  |     29.5M    |   160.4G   |     54.4%     | 10.70ms |

## 安装
建议使用 `conda` 虚拟环境。
```
conda create -n yolov10 python=3.9
conda activate yolov10
pip install -r requirements.txt
pip install -e .
```

## 演示
```
python app.py
# 请访问 http://127.0.0.1:7860
```

## 验证
[`yolov10n`](https://huggingface.co/jameslahm/yolov10n)  [`yolov10s`](https://huggingface.co/jameslahm/yolov10s)  [`yolov10m`](https://huggingface.co/jameslahm/yolov10m)  [`yolov10b`](https://huggingface.co/jameslahm/yolov10b)  [`yolov10l`](https://huggingface.co/jameslahm/yolov10l)  [`yolov10x`](https://huggingface.co/jameslahm/yolov10x)  
```
yolo val model=jameslahm/yolov10{n/s/m/b/l/x} data=coco.yaml batch=256
```

或者
```python
from ultralytics import YOLOv10

model = YOLOv10.from_pretrained('jameslahm/yolov10{n/s/m/b/l/x}')
# 或者
# wget https://github.com/THU-MIG/yolov10/releases/download/v1.1/yolov10{n/s/m/b/l/x}.pt
model = YOLOv10('yolov10{n/s/m/b/l/x}.pt')

model.val(data='coco.yaml', batch=256)
```

## 训练 
```
yolo detect train data=coco.yaml model=yolov10n/s/m/b/l/x.yaml epochs=500 batch=256 imgsz=640 device=0,1,2,3,4,5,6,7
```

或者
```python
from ultralytics import YOLOv10

model = YOLOv10()
# 如果你想要使用预训练权重微调模型，可以像下面这样加载预训练权重
# model = YOLOv10.from_pretrained('jameslahm/yolov10{n/s/m/b/l/x}')
# 或者
# wget https://github.com/THU-MIG/yolov10/releases/download/v1.1/yolov10{n/s/m/b/l/x}.pt
# model = YOLOv10('yolov10{n/s/m/b/l/x}.pt')

model.train(data='coco.yaml', epochs=500, batch=256, imgsz=640)
```

## 推送到 🤗 hub

可选地，你可以将微调后的模型推送到 [Hugging Face hub](https://huggingface.co/) 作为公共或私有模型：

```python
# 假设你已经微调了一个用于作物检测的模型
model.push_to_hub("<你的-hf-用户名或组织/yolov10-finetuned-crop-detection")

# 如果你不希望所有人都能看到你的模型，可以添加 `private=True`
model.push_to_hub("<你的-hf-用户名或组织/yolov10-finetuned-crop-detection", private=True)
```

## 预测
请注意，可以设置更低的置信度阈值以检测更小的物体或远距离的物体。详情请参阅 [这里](https://github.com/THU-MIG/yolov10/issues/136)。

```
yolo predict model=jameslahm/yolov10{n/s/m/b/l/x}
```

或者
```python
from ultralytics import YOLOv10

model = YOLOv10.from_pretrained('jameslahm/yolov10{n/s/m/b/l/x}')
# 或者
# wget https://github.com/THU-MIG/yolov10/releases/download/v1.1/yolov10{n/s/m/b/l/x}.pt
model = YOLOv10('yolov10{n/s/m/b/l/x}.pt')

model.predict()
```

## 导出
```
# 完整的端到端 ONNX
yolo export model=jameslahm/yolov10{n/s/m/b/l/x} format=onnx opset=13 simplify
# 使用 ONNX 进行预测
yolo predict model=yolov10n/s/m/b/l/x.onnx

# 完整的端到端 TensorRT
yolo export model=jameslahm/yolov10{n/s/m/b/l/x} format=engine half=True simplify opset=13 workspace=16
# 或者
trtexec --onnx=yolov10n/s/m/b/l/x.onnx --saveEngine=yolov10n/s/m/b/l/x.engine --fp16
# 使用 TensorRT 进行预测
yolo predict model=yolov10n/s/m/b/l/x.engine
```

或者
```python
from ultralytics import YOLOv10

model = YOLOv10.from_pretrained('jameslahm/yolov10{n/s/m/b/l/x}')
# 或者
# wget https://github.com/THU-MIG/yolov10/releases/download/v1.1/yolov10{n/s/m/b/l/x}.pt
model = YOLOv10('yolov10{n/s/m/b/l/x}.pt')

model.export(...)
```



# 简易 训练和验证教程

## 下载官方项目源代码

1. 在下面的项目地址中下载完整的源代码ZIP

    项目地址：[THU-MIG/yolov10: YOLOv10: Real-Time End-to-End Object Detection (github.com)](https://github.com/THU-MIG/yolov10/tree/main)

    或者在你想要的目录下使用Git克隆项目：

   `git clone https://github.com/THU-MIG/yolov10.git`

2. 在项目的Release页面下载你想要验证的模型文件

   页面地址：[Release Update checkpoints with other attributes. · THU-MIG/yolov10 (github.com)](https://github.com/THU-MIG/yolov10/releases/tag/v1.1)

   下载你想要的模型，例如[YoloV10n.pt](https://github.com/THU-MIG/yolov10/releases/download/v1.1/yolov10l.pt),在页面中点击此模型下载，并将模型文件放到项目文件夹根目录

3. 使用VSCode打开项目文件夹，或者使用终端命令行（PowerShell/CMD）进入项目目录

​	**注意项目路径不要有中文！**

***接下来的的操作均在项目文件夹根目录里执行***

## 安装及环境配置

建议使用 `conda` 虚拟环境。
```
conda create -n yolov10 python=3.9
conda activate yolov10
pip install -r requirements.txt
pip install -e .
```
## 训练 

命令格式：

```
yolo detect train data=[数据集配置文件路径及文件名] model=yolov10n/s/m/b/l/x.yaml epochs=[训练轮次，一般设置500次] batch=[数据量大小 32/64//128/256] imgsz=[图像大小，参考采用的训练数据集单个图像大小，一般设置640] device=[0/cpu]
```

示例：训练模型yolov10n,数据集采用VOC，显存大小6G，

yolo detect train data=ultralytics/cfg/datasets/VOC.yaml model=yolov10n.yaml epochs=500 batch=256 imgsz=640 device=0

```
yolo detect train data=D:\yolov10-main\ultralytics\cfg\datasets\det_tea_disease_yolo.yaml model=yolov10n-mobilenetv4.yaml epochs=300 batch=4 imgsz=640 device=0 workers=4
```

解释：

减少`batch size`，减少每个批次处理的数据量，降低内存需求。

禁用Mosaic数据增强：数据增强阶段可能导致内存不足

减少数据加载器的workers数量：数据加载器的workers数量过多可能导致内存不足

##### 执行效果：

执行验证命令结束后会在项目文件夹的run文件夹里生成train文件夹，进入可查看到训练出的模型的以及识别情况

## 验证
[`yolov10n`](https://huggingface.co/jameslahm/yolov10n)  [`yolov10s`](https://huggingface.co/jameslahm/yolov10s)  [`yolov10m`](https://huggingface.co/jameslahm/yolov10m)  [`yolov10b`](https://huggingface.co/jameslahm/yolov10b)  [`yolov10l`](https://huggingface.co/jameslahm/yolov10l)  [`yolov10x`](https://huggingface.co/jameslahm/yolov10x)  

命令格式：

```
yolo val model=[模型文件路径及文件名] data=[数据集配置文件路径] batch=[每个批次处理的数据量]
```

##### 示例：验证yolov10n.pt,数据集采用VOC，显存大小6G

```
yolo val model=yolov10n.pt data=D:\yolov10-main\ultralytics\cfg\datasets\VOC.yaml batch=64 device=0
```

命令解析：

val-验证 

model=‘模型文件名’ 

data=‘数据集配置文件’ 

batch=‘批次处理的数据量’ （和显存大小有关，设置的值越大需要的显存和内存容量越大）

device=‘指定用0号 显卡’（device=cpu 可以指定使用CPU来进行验证/训练）

##### 执行效果：

执行验证命令结束后会在项目文件夹的run文件夹里生成val文件夹，进入可查看到验证文件的详细情况

## 性能

### 按类别划分的指标

输出中的一个部分是按类划分的性能指标。当您想了解模型在每个特定类别中的表现时，尤其是在对象类别繁多的数据集中，这种细化信息非常有用。对于数据集中的每个类别，我们都会提供以下信息：

- **类**：表示对象类别的名称，如 "人"、"车 "或 "狗"。
- **图像**：该指标显示验证集中包含对象类别的图片数量。
- **实例**：这提供了该类在验证集所有图像中出现的次数。
- **Box（P、R、mAP50、mAP50-95）**：该指标可帮助我们深入了解模型在检测物体方面的性能：
  - **P（精确度）**：检测物体的精确度，表示有多少检测是正确的。
  - **R（召回率）**：模型识别图像中所有物体实例的能力。
  - **mAP50**：按 0.50 的交集大于联合（IoU）阈值计算的平均精度。这是仅考虑 "容易 "检测的模型精确度的衡量标准。
  - **mAP50-95**：在 0.50 至 0.95 之间的不同 IoU 门限下计算得出的平均精度的平均值。它全面反映了模型在不同检测难度下的表现。

### COCO 指标评估

对于在 COCO 数据集上进行验证的，还可使用 COCO 评估脚本计算其他指标。这些指标可帮助用户深入了解不同 IoU 临界值和不同大小对象的精确度和召回率。

### 视觉输出

model.val() 函数除了生成数字指标外，还能生成可视化输出，让人更直观地了解模型的性能。下面是可视化输出的细目：

- **F1 分数曲线 (`F1_curve.png`)**:该曲线表示不同阈值下的 F1 分数。通过解读这条曲线，可以深入了解模型在不同阈值下假阳性和假阴性之间的平衡。
- **精度-召回曲线 (`PR_curve.png`)**:对于任何分类问题来说，这条曲线都是不可或缺的可视化工具，它展示了在不同阈值下精确度和召回率之间的权衡。在处理不平衡类时，它显得尤为重要。
- **精度曲线 (`P_curve.png`)**:不同阈值下精度值的图形表示。该曲线有助于了解精度如何随着阈值的变化而变化。
- **召回曲线 (`R_curve.png`)**:相应地，该图说明了召回值在不同阈值下的变化情况。
- **混淆矩阵 (`confusion_matrix.png`)**:混淆矩阵提供了结果的详细视图，展示了每个类别的真阳性、真阴性、假阳性和假阴性的计数。
- **归一化混淆矩阵 (`confusion_matrix_normalized.png`)**:这种可视化是混淆矩阵的规范化版本。它以比例而非原始计数来表示数据。这种格式更便于比较不同类别的性能。
- **验证批次标签 (`val_batchX_labels.jpg`)**:这些图像描述了验证数据集中不同批次的基本真实标签。根据数据集，这些图像可以清楚地显示对象及其各自的位置。
- **验证批预测 (`val_batchX_pred.jpg`)**:与标签图像对比，这些视觉效果显示了YOLOv8 模型对相应批次的预测结果。通过将这些图像与标签图像进行对比，您可以轻松评估模型对物体的检测和分类效果。

## 演示

```
python app.py
# 请访问 http://127.0.0.1:7860
```



# 常见问题

## 报错-CUDA

```
(yolov10) PS D:\yolov10-main> yolo detect train data=VOC.yaml  model=yolov10n.yaml epochs=500 batch=64 imgsz=640 device=0
Ultralytics YOLOv8.2.66 🚀 Python-3.9.19 torch-2.0.1+cpu 
Traceback (most recent call last):
  File "F:\APP\Anaconda3\envs\yolov10\lib\runpy.py", line 197, in _run_module_as_main
    return _run_code(code, main_globals, None,
  File "F:\APP\Anaconda3\envs\yolov10\lib\runpy.py", line 87, in _run_code
    exec(code, run_globals)
  File "F:\APP\Anaconda3\envs\yolov10\Scripts\yolo.exe\__main__.py", line 7, in <module>
  File "F:\APP\Anaconda3\envs\yolov10\lib\site-packages\ultralytics\cfg\__init__.py", line 830, in entrypoint
    getattr(model, mode)(**overrides)  # default args from model
  File "F:\APP\Anaconda3\envs\yolov10\lib\site-packages\ultralytics\engine\model.py", line 805, in train
    self.trainer = (trainer or self._smart_load("trainer"))(overrides=args, _callbacks=self.callbacks)
  File "F:\APP\Anaconda3\envs\yolov10\lib\site-packages\ultralytics\engine\trainer.py", line 103, in __init__
    self.device = select_device(self.args.device, self.args.batch)
  File "F:\APP\Anaconda3\envs\yolov10\lib\site-packages\ultralytics\utils\torch_utils.py", line 170, in select_device
    raise ValueError(
ValueError: Invalid CUDA 'device=0' requested. Use 'device=cpu' or pass valid CUDA device(s) if available, i.e. 'device=0' or 'device=0,1,2,3' for Multi-GPU.

torch.cuda.is_available(): False
torch.cuda.device_count(): 0
os.environ['CUDA_VISIBLE_DEVICES']: None
See https://pytorch.org/get-started/locally/ for up-to-date torch install instructions if no CUDA devices are seen by torch.
```



### 解决：

根据错误信息，系统尝试使用CUDA设备（device=0），但未检测到可用的CUDA设备。这可能是由于以下几个原因：

1. **未安装CUDA**： 你的系统可能没有安装CUDA。
2. **没有兼容的NVIDIA GPU：** 你的系统可能没有兼容的NVIDIA GPU。
3. **CUDA工具包和驱动程序未正确安装或配置：** 即使你有NVIDIA GPU，如果CUDA工具包和驱动程序未正确安装或配置，也会导致这个问题。
4. **PyTorch版本不支持CUDA：** 你可能安装了不带CUDA支持的PyTorch版本。

以下是一些解决步骤：

### 1. 验证GPU和CUDA安装
首先，确保你的系统有兼容的NVIDIA GPU并安装了CUDA。你可以运行以下命令检查：

```bash
nvidia-smi
```

这个命令应该显示你的NVIDIA GPU的信息。如果没有显示，你可能需要安装适当的NVIDIA驱动程序。

### 2. 安装CUDA和cuDNN
如果没有安装CUDA，请按照[官方CUDA安装指南](https://developer.nvidia.com/cuda-downloads)安装CUDA和cuDNN。

### 3. 验证带CUDA的PyTorch安装
确保你安装了带CUDA支持的正确版本的PyTorch。你可以运行以下Python代码检查：

```python
import torch
print(torch.cuda.is_available())
print(torch.cuda.device_count())
```

如果`torch.cuda.is_available()`返回`False`，你需要安装正确版本的PyTorch。请按照[PyTorch安装指南](https://pytorch.org/get-started/locally/)选择适当的CUDA版本。

例如，要安装带CUDA 11.7的PyTorch，可以运行：

```bash
pip install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cu124
```

### 4. 修改命令
如果你想在不使用GPU的情况下继续，可以修改命令使用CPU：

```bash
yolo detect train data=VOC.yaml model=yolov10n.yaml epochs=500 batch=64 imgsz=640 device=cpu
```

### 5. 验证环境变量
确保环境变量`CUDA_VISIBLE_DEVICES`设置正确。你可以在环境中检查和设置这个变量：

在Windows命令提示符或PowerShell中：
```cmd
set CUDA_VISIBLE_DEVICES=0
```

在类Unix系统中：
```bash
export CUDA_VISIBLE_DEVICES=0
```

设置后，验证PyTorch是否能检测到GPU：

```python
import torch
print(torch.cuda.is_available())
print(torch.cuda.device_count())
```

### 总结
1. 确保你的系统有兼容的NVIDIA GPU。
2. 安装或更新NVIDIA驱动程序、CUDA和cuDNN。
3. 安装带CUDA支持的正确版本的PyTorch。
4. 如果没有GPU或者不想用GPU，修改命令使用`device=cpu`。
5. 如有必要，检查和设置`CUDA_VISIBLE_DEVICES`环境变量。

按照这些步骤应该能帮助你解决问题，并使用适当的设备进行YOLO训练。



## CUDA安装

要在Windows系统上安装CUDA，可以按照以下步骤进行：

### 1. 检查系统要求
确保你的系统满足以下要求：
- 这段代码通过 Gradio 提供了一个简单易用的 Web 界面，用于实现 YOLOv10 模型的图像和视频对象检测。用户可以通过上传图像或视频，选择模型和参数，点击按钮即可进行检测并查看结果。
- NVIDIA GPU
- 支持的驱动程序版本

### 2. 下载CUDA Toolkit
访问[NVIDIA CUDA Toolkit下载页面](https://developer.nvidia.com/cuda-downloads)并选择适合你的系统的版本。以下是具体步骤：

1. 选择操作系统、架构、分发版和版本。例如：
   - 操作系统：Windows
   - 架构：x86_64
   - 版本：10
   - Installer Type：exe (local)

2. 点击下载链接，下载CUDA安装程序。

### 3. 安装CUDA Toolkit
1. 运行下载的CUDA安装程序。
2. 在安装向导中，选择“Express”或“Custom”安装类型。建议选择“Express”以确保安装所有必需的组件。
3. 按照安装向导的指示完成安装。

### 4. 设置环境变量
安装完成后，需要设置系统环境变量以确保系统可以找到CUDA工具：

1. **打开系统属性**：
   - 右键点击“此电脑”或“我的电脑”图标，然后选择“属性”。
   - 点击“高级系统设置”。
   - 点击“环境变量”。

2. **编辑系统变量**：
   - 在“系统变量”部分，找到`Path`变量并编辑。
   - 添加CUDA的`bin`和`libnvvp`路径，例如：
     ```
     C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.2\bin
     C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.2\libnvvp
     ```

3. **添加CUDA相关变量**（如果不存在）：
   - `CUDA_HOME`：指向CUDA安装目录，例如`C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.2`

### 5. 验证安装
1. 打开命令提示符（cmd）并运行以下命令以验证CUDA是否正确安装：
   ```bash
   nvcc --version
   ```
   这应该会显示CUDA编译器的版本信息。

2. 运行`nvidia-smi`命令以确保NVIDIA驱动程序正确安装并检测到GPU：
   ```bash
   nvidia-smi
   ```

### 6. 安装cuDNN（可选但推荐）
cuDNN（CUDA Deep Neural Network library）是用于深度学习的高性能GPU加速库。以下是安装步骤：

1. 访问[NVIDIA cuDNN下载页面](https://developer.nvidia.com/rdp/cudnn-download)并下载适合你CUDA版本的cuDNN库。
2. 解压下载的文件。
3. 将解压后的文件复制到CUDA安装目录中。例如，将`bin`、`include`和`lib`文件夹的内容复制到`C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.2`中的对应文件夹。

### 7. 安装带CUDA支持的PyTorch
1. 激活你的conda环境：
   ```bash
   conda activate yolov10
   ```

2. 安装带CUDA支持的PyTorch：
   ```bash
   pip install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cu117
   ```

### 8. 验证PyTorch和CUDA的安装
打开Python解释器并运行以下代码：
```python
import torch
print(torch.cuda.is_available())
print(torch.cuda.device_count())
```

如果`torch.cuda.is_available()`返回`True`并且`torch.cuda.device_count()`返回你的GPU数量，则说明安装成功。

### 总结
1. 检查系统要求。
2. 下载并安装CUDA Toolkit。
3. 设置系统环境变量。
4. 验证CUDA安装。
5. 安装cuDNN（可选）。
6. 安装带CUDA支持的PyTorch。
7. 验证PyTorch和CUDA的安装。

## Yolo V10 6G显存求生指南(显存太小)

#### 报错提示：

```
(yolov10) PS D:\yolov10-main> yolo detect train data=D:\yolov10-main\ultralytics\cfg\datasets\VOC.yaml model=yolov10n.yaml epochs=500 batch=8 imgsz=320 device=0
New https://pypi.org/project/ultralytics/8.2.66 available 😃 Update with 'pip install -U ultralytics'
Ultralytics YOLOv8.1.34 🚀 Python-3.9.19 torch-2.4.0+cu124 CUDA:0 (NVIDIA GeForce RTX 3060 Laptop GPU, 6144MiB)
engine\trainer: task=detect, mode=train, model=yolov10n.yaml, data=D:\yolov10-main\ultralytics\cfg\datasets\VOC.yaml, epochs=500, time=None, patience=100, batch=8, imgsz=320, save=True, save_period=-1, val_period=1, cache=False, device=0, workers=8, project=None, name=train7, exist_ok=False, pretrained=True, optimizer=auto, verbose=True, seed=0, deterministic=True, single_cls=False, rect=False, cos_lr=False, close_mosaic=10, resume=False, amp=True, fraction=1.0, profile=False, freeze=None, multi_scale=False, overlap_mask=True, mask_ratio=4, dropout=0.0, val=True, split=val, save_json=False, save_hybrid=False, conf=None, iou=0.7, max_det=300, half=False, dnn=False, plots=True, source=None, vid_stride=1, stream_buffer=False, visualize=False, augment=False, agnostic_nms=False, classes=None, retina_masks=False, embed=None, show=False, save_frames=False, save_txt=False, save_conf=False, save_crop=False, show_labels=True, show_conf=True, show_boxes=True, line_width=None, format=torchscript, keras=False, optimize=False, int8=False, dynamic=False, simplify=False, opset=None, workspace=4, nms=False, lr0=0.01, lrf=0.01, momentum=0.937, weight_decay=0.0005, warmup_epochs=3.0, warmup_momentum=0.8, warmup_bias_lr=0.1, box=7.5, cls=0.5, dfl=1.5, pose=12.0, kobj=1.0, label_smoothing=0.0, nbs=64, hsv_h=0.015, hsv_s=0.7, hsv_v=0.4, degrees=0.0, translate=0.1, scale=0.5, shear=0.0, perspective=0.0, flipud=0.0, fliplr=0.5, bgr=0.0, mosaic=1.0, mixup=0.0, copy_paste=0.0, auto_augment=randaugment, erasing=0.4, crop_fraction=1.0, cfg=None, tracker=botsort.yaml, save_dir=runs\detect\train7
Overriding model.yaml nc=80 with nc=20

                   from  n    params  module                                       arguments
  0                  -1  1       464  ultralytics.nn.modules.conv.Conv             [3, 16, 3, 2]
  1                  -1  1      4672  ultralytics.nn.modules.conv.Conv             [16, 32, 3, 2]
  2                  -1  1      7360  ultralytics.nn.modules.block.C2f             [32, 32, 1, True]
  3                  -1  1     18560  ultralytics.nn.modules.conv.Conv             [32, 64, 3, 2]
  4                  -1  2     49664  ultralytics.nn.modules.block.C2f             [64, 64, 2, True]
  5                  -1  1      9856  ultralytics.nn.modules.block.SCDown          [64, 128, 3, 2]
  6                  -1  2    197632  ultralytics.nn.modules.block.C2f             [128, 128, 2, True]
  7                  -1  1     36096  ultralytics.nn.modules.block.SCDown          [128, 256, 3, 2]
  8                  -1  1    460288  ultralytics.nn.modules.block.C2f             [256, 256, 1, True]
  9                  -1  1    164608  ultralytics.nn.modules.block.SPPF            [256, 256, 5]
 10                  -1  1    249728  ultralytics.nn.modules.block.PSA             [256, 256]
 11                  -1  1         0  torch.nn.modules.upsampling.Upsample         [None, 2, 'nearest']
 12             [-1, 6]  1         0  ultralytics.nn.modules.conv.Concat           [1]
 13                  -1  1    148224  ultralytics.nn.modules.block.C2f             [384, 128, 1]
 14                  -1  1         0  torch.nn.modules.upsampling.Upsample         [None, 2, 'nearest']
 15             [-1, 4]  1         0  ultralytics.nn.modules.conv.Concat           [1]
 16                  -1  1     37248  ultralytics.nn.modules.block.C2f             [192, 64, 1]
 17                  -1  1     36992  ultralytics.nn.modules.conv.Conv             [64, 64, 3, 2]
 18            [-1, 13]  1         0  ultralytics.nn.modules.conv.Concat           [1]
 19                  -1  1    123648  ultralytics.nn.modules.block.C2f             [192, 128, 1]
 20                  -1  1     18048  ultralytics.nn.modules.block.SCDown          [128, 128, 3, 2]
 21            [-1, 10]  1         0  ultralytics.nn.modules.conv.Concat           [1]
 22                  -1  1    282624  ultralytics.nn.modules.block.C2fCIB          [384, 256, 1, True, True]     
 23        [16, 19, 22]  1    869128  ultralytics.nn.modules.head.v10Detect        [20, [64, 128, 256]]
YOLOv10n summary: 385 layers, 2714840 parameters, 2714824 gradients, 8.4 GFLOPs

Freezing layer 'model.23.dfl.conv.weight'
AMP: running Automatic Mixed Precision (AMP) checks with YOLOv8n...
D:\yolov10\ultralytics\nn\tasks.py:729: FutureWarning: You are using `torch.load` with `weights_only=False` (the current default value), which uses the default pickle module implicitly. It is possible to construct malicious pickle data which will execute arbitrary code during unpickling (See https://github.com/pytorch/pytorch/blob/main/SECURITY.md#untrusted-models for more details). In a future release, the default value for `weights_only` will be flipped to `True`. This limits the functions that could be executed during unpickling. Arbitrary objects will no longer be allowed to be loaded via this mode unless they are explicitly allowlisted by the user via `torch.serialization.add_safe_globals`. We recommend you start setting `weights_only=True` for any use case where you don't have full control of the loaded file. Please open an issue on GitHub for any issues related to this experimental feature.
  ckpt = torch.load(file, map_location="cpu")
D:\yolov10\ultralytics\utils\checks.py:641: FutureWarning: `torch.cuda.amp.autocast(args...)` is deprecated. Please use `torch.amp.autocast('cuda', args...)` instead.
  with torch.cuda.amp.autocast(True):
AMP: checks passed ✅
D:\yolov10\ultralytics\engine\trainer.py:276: FutureWarning: `torch.cuda.amp.GradScaler(args...)` is deprecated. Please use `torch.amp.GradScaler('cuda', args...)` instead.
  self.scaler = torch.cuda.amp.GradScaler(enabled=self.amp)
train: Scanning D:\yolov10-main\datasets\VOC\labels\train2007.cache... 16551 images, 0 backgrounds, 0 corrupt: 100%|██████████| 16551/16551 [00:00<?, ?it/s]
val: Scanning D:\yolov10-main\datasets\VOC\labels\test2007.cache... 4952 images, 0 backgrounds, 0 corrupt: 100%|██████████| 4952/4952 [00:00<?, ?it/s]
Plotting labels to runs\detect\train7\labels.jpg... 
optimizer: 'optimizer=auto' found, ignoring 'lr0=0.01' and 'momentum=0.937' and determining best 'optimizer', 'lr0' and 'momentum' automatically... 
optimizer: SGD(lr=0.01, momentum=0.9) with parameter groups 95 weight(decay=0.0), 108 weight(decay=0.0005), 107 bias(decay=0.0)
Image sizes 320 train, 320 val
Using 8 dataloader workers
Logging results to runs\detect\train7
Starting training for 500 epochs...

      Epoch    GPU_mem     box_om     cls_om     dfl_om     box_oo     cls_oo     dfl_oo  Instances       Size
      1/500     0.459G       3.63      5.061      4.275      3.446      6.023       4.34         26        320:   1%|▏         | 30/2069 [00:04<04:40,  7.28it/s]
Traceback (most recent call last):
  File "F:\APP\Anaconda3\envs\yolov10\lib\runpy.py", line 197, in _run_module_as_main
    return _run_code(code, main_globals, None,
  File "F:\APP\Anaconda3\envs\yolov10\lib\runpy.py", line 87, in _run_code
    exec(code, run_globals)
  File "F:\APP\Anaconda3\envs\yolov10\Scripts\yolo.exe\__main__.py", line 7, in <module>
  File "D:\yolov10\ultralytics\cfg\__init__.py", line 587, in entrypoint
    getattr(model, mode)(**overrides)  # default args from model
  File "D:\yolov10\ultralytics\engine\model.py", line 657, in train
    self.trainer.train()
  File "D:\yolov10\ultralytics\engine\trainer.py", line 213, in train
    self._do_train(world_size)
  File "D:\yolov10\ultralytics\engine\trainer.py", line 363, in _do_train
    for i, batch in pbar:
  File "F:\APP\Anaconda3\envs\yolov10\lib\site-packages\tqdm\std.py", line 1181, in __iter__
    for obj in iterable:
  File "D:\yolov10\ultralytics\data\build.py", line 49, in __iter__
    yield next(self.iterator)
  File "F:\APP\Anaconda3\envs\yolov10\lib\site-packages\torch\utils\data\dataloader.py", line 630, in __next__
    data = self._next_data()
  File "F:\APP\Anaconda3\envs\yolov10\lib\site-packages\torch\utils\data\dataloader.py", line 1344, in _next_data
    return self._process_data(data)
  File "F:\APP\Anaconda3\envs\yolov10\lib\site-packages\torch\utils\data\dataloader.py", line 1370, in _process_data
    data.reraise()
  File "F:\APP\Anaconda3\envs\yolov10\lib\site-packages\torch\_utils.py", line 705, in reraise
    raise RuntimeError(msg) from None
RuntimeError: Caught MemoryError in DataLoader worker process 6.
  File "F:\APP\Anaconda3\envs\yolov10\lib\site-packages\torch\utils\data\_utils\fetch.py", line 52, in <listcomp>
    data = [self.dataset[idx] for idx in possibly_batched_index]
  File "D:\yolov10\ultralytics\data\base.py", line 253, in __getitem__
    return self.transforms(self.get_image_and_label(index))
  File "D:\yolov10\ultralytics\data\augment.py", line 74, in __call__
    data = t(data)
  File "D:\yolov10\ultralytics\data\augment.py", line 74, in __call__
    data = t(data)
  File "D:\yolov10\ultralytics\data\augment.py", line 122, in __call__
    labels = self._mix_transform(labels)
  File "D:\yolov10\ultralytics\data\augment.py", line 171, in _mix_transform
    self._mosaic3(labels) if self.n == 3 else self._mosaic4(labels) if self.n == 4 else self._mosaic9(labels)
  File "D:\yolov10\ultralytics\data\augment.py", line 221, in _mosaic4
    img4 = np.full((s * 2, s * 2, img.shape[2]), 114, dtype=np.uint8)  # base image with 4 tiles
  File "F:\APP\Anaconda3\envs\yolov10\lib\site-packages\numpy\core\numeric.py", line 329, in full
    a = empty(shape, dtype, order)
numpy.core._exceptions._ArrayMemoryError: Unable to allocate 1.17 MiB for an array with shape (640, 640, 3) and data type uint8
```



根据新的错误信息，您遇到了NumPy内存不足（`numpy.core._exceptions._ArrayMemoryError`）的问题。这表明您的系统内存（RAM）在处理数据增强时也不足。这可能是由于数据增强操作（例如Mosaic）在处理大尺寸图像时消耗了大量内存。

### 解决办法

1. **进一步减少Batch Size**：
   - 尝试进一步减少`batch size`，这可以减少每个批次处理的数据量，降低内存需求。
   ```bash
   yolo detect train data=D:\yolov10-main\ultralytics\cfg\datasets\VOC.yaml model=yolov10n.yaml epochs=500 batch=4 imgsz=320 device=0
   ```

2. **禁用Mosaic数据增强**：
   - 如果内存问题主要出现在数据增强阶段，可以尝试禁用Mosaic数据增强。
   ```bash
   yolo detect train data=D:\yolov10-main\ultralytics\cfg\datasets\VOC.yaml model=yolov10n.yaml epochs=500 batch=8 imgsz=320 device=0 close_mosaic=0
   ```

3. **减少数据加载器的workers数量**：
   - 数据加载器的workers数量过多也可能导致内存不足，尝试减少workers数量。
   ```bash
   yolo detect train data=D:\yolov10-main\ultralytics\cfg\datasets\VOC.yaml model=yolov10n.yaml epochs=500 batch=8 imgsz=320 device=0 workers=4
   ```

4. **增加Swap空间**：
   - 如果您的物理内存不足，可以尝试增加系统的Swap空间，作为虚拟内存使用。
   - Windows系统可以通过调整虚拟内存设置来增加Swap空间。

### 示例命令
结合上述建议，您可以尝试如下命令：
```bash
yolo detect train data=D:\yolov10-main\ultralytics\cfg\datasets\VOC.yaml model=yolov10n.yaml epochs=500 batch=4 imgsz=320 device=0 close_mosaic=0 workers=4
```

### 检查系统内存使用情况
您可以使用任务管理器（Task Manager）来监控系统内存的使用情况，确保没有其他进程占用大量内存。

### 其他建议
- **重启系统**：有时候重启系统可以释放被占用的内存。
- **关闭其他不必要的应用程序**：确保在训练过程中没有其他不必要的应用程序占用内存。

通过这些方法，您应该能够有效减少内存的使用，避免内存不足的问题。

