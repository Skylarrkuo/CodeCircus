# YOLOv10 极简使用指南

## 环境配置
```bash
conda create -n yolov10 python=3.9
conda activate yolov10
pip install -r requirements.txt
pip install -e .
```

## 快速使用
### 模型训练
```bash
# 基础命令
yolo detect train data=数据集.yaml model=yolov10n.yaml epochs=300 batch=64 imgsz=640 device=0

# 示例（VOC数据集）
yolo detect train data=ultralytics/cfg/datasets/VOC.yaml model=yolov10n.yaml epochs=300 batch=64 imgsz=640 device=0
```

### 模型验证
```bash
yolo val model=yolov10n.pt data=数据集.yaml batch=64 device=0
```

### 实时预测
```python
from ultralytics import YOLOv10

model = YOLOv10.from_pretrained('jameslahm/yolov10n')
results = model.predict(source='输入路径', conf=0.25)  # 调低conf检测小物体
```

### 模型导出
```bash
# 导出ONNX
yolo export model=yolov10n.pt format=onnx opset=13

# 导出TensorRT
yolo export model=yolov10n.pt format=engine half=True
```

## 显存优化小贴士
```bash
yolo detect train \
  data=数据集.yaml \
  model=yolov10n.yaml \
  batch=4 \          # 减小batch size
  imgsz=320 \        # 降低分辨率
  device=0 \
  workers=4 \        # 减少数据加载线程
  mosaic=0           # 禁用Mosaic增强
```

## 高级功能
```python
# 模型部署到HuggingFace Hub
model.push_to_hub("用户名/模型名称")

# 可视化训练结果
from ultralytics.utils.plots import plot_results
plot_results('runs/detect/train/results.csv')
```

> 完整文档参考：[YOLOv10官方仓库](https://github.com/THU-MIG/yolov10)  
> 常见问题解决：调整`batch/imgsz`参数 → 使用CPU训练 → 检查CUDA安装