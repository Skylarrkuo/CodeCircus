##  APP.py -Demo代码的详细讲解-

使用 Gradio 框架创建 Web 应用，实现 YOLOv10 模型的推理，包括图像和视频的对象检测,

### 1. 导入必要的库

```python
import gradio as gr
import cv2
import tempfile
from ultralytics import YOLOv10
```

- `gradio`：用于创建 Web 界面。
- `cv2`：用于处理视频文件。
- `tempfile`：用于创建临时文件。
- `YOLOv10`：用于进行对象检测的 YOLOv10 模型。

### 2. YOLOv10 推理函数

```python
def yolov10_inference(image, video, model_id, image_size, conf_threshold):
    model = YOLOv10.from_pretrained(f'jameslahm/{model_id}')
    if image:
        results = model.predict(source=image, imgsz=image_size, conf=conf_threshold)
        annotated_image = results[0].plot()
        return annotated_image[:, :, ::-1], None
    else:
        video_path = tempfile.mktemp(suffix=".webm")
        with open(video_path, "wb") as f:
            with open(video, "rb") as g:
                f.write(g.read())

        cap = cv2.VideoCapture(video_path)
        fps = cap.get(cv2.CAP_PROP_FPS)
        frame_width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
        frame_height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

        output_video_path = tempfile.mktemp(suffix=".webm")
        out = cv2.VideoWriter(output_video_path, cv2.VideoWriter_fourcc(*'vp80'), fps, (frame_width, frame_height))

        while cap.isOpened():
            ret, frame = cap.read()
            if not ret:
                break

            results = model.predict(source=frame, imgsz=image_size, conf=conf_threshold)
            annotated_frame = results[0].plot()
            out.write(annotated_frame)

        cap.release()
        out.release()

        return None, output_video_path
```

- 这个函数根据输入的图像或视频进行对象检测。
- 加载预训练的 YOLOv10 模型。
- 如果输入是图像，则返回标注后的图像。
- 如果输入是视频，则处理每一帧并返回标注后的视频路径。

### 3. YOLOv10 示例推理函数

```python
def yolov10_inference_for_examples(image, model_path, image_size, conf_threshold):
    annotated_image, _ = yolov10_inference(image, None, model_path, image_size, conf_threshold)
    return annotated_image
```

- 这个函数用于处理示例图像，返回标注后的图像。

### 4. 应用程序界面

```python
def app():
    with gr.Blocks():
        with gr.Row():
            with gr.Column():
                image = gr.Image(type="pil", label="Image", visible=True)
                video = gr.Video(label="Video", visible=False)
                input_type = gr.Radio(
                    choices=["Image", "Video"],
                    value="Image",
                    label="Input Type",
                )
                model_id = gr.Dropdown(
                    label="Model",
                    choices=[
                        "yolov10n",
                        "yolov10s",
                        "yolov10m",
                        "yolov10b",
                        "yolov10l",
                        "yolov10x",
                    ],
                    value="yolov10m",
                )
                image_size = gr.Slider(
                    label="Image Size",
                    minimum=320,
                    maximum=1280,
                    step=32,
                    value=640,
                )
                conf_threshold = gr.Slider(
                    label="Confidence Threshold",
                    minimum=0.0,
                    maximum=1.0,
                    step=0.05,
                    value=0.25,
                )
                yolov10_infer = gr.Button(value="Detect Objects")

            with gr.Column():
                output_image = gr.Image(type="numpy", label="Annotated Image", visible=True)
                output_video = gr.Video(label="Annotated Video", visible=False)
```

- 创建一个包含图像、视频输入、模型选择、图像尺寸和置信度阈值的界面。
- 包含一个按钮用于触发对象检测。

### 5. 更新可见性函数

```python
        def update_visibility(input_type):
            image = gr.update(visible=True) if input_type == "Image" else gr.update(visible=False)
            video = gr.update(visible=False) if input_type == "Image" else gr.update(visible=True)
            output_image = gr.update(visible=True) if input_type == "Image" else gr.update(visible(False)
            output_video = gr.update(visible=False) if input_type == "Image" else gr.update(visible=True)

            return image, video, output_image, output_video

        input_type.change(
            fn=update_visibility,
            inputs=[input_type],
            outputs=[image, video, output_image, output_video],
        )
```

- 根据用户选择的输入类型（图像或视频）更新相应的控件的可见性。

### 6. 运行推理函数

```python
        def run_inference(image, video, model_id, image_size, conf_threshold, input_type):
            if input_type == "Image":
                return yolov10_inference(image, None, model_id, image_size, conf_threshold)
            else:
                return yolov10_inference(None, video, model_id, image_size, conf_threshold)

        yolov10_infer.click(
            fn=run_inference,
            inputs=[image, video, model_id, image_size, conf_threshold, input_type],
            outputs=[output_image, output_video],
        )
```

- 根据用户输入的图像或视频运行对象检测，并显示结果。

### 7. 示例部分

```python
        gr.Examples(
            examples=[
                [
                    "ultralytics/assets/bus.jpg",
                    "yolov10s",
                    640,
                    0.25,
                ],
                [
                    "ultralytics/assets/zidane.jpg",
                    "yolov10s",
                    640,
                    0.25,
                ],
            ],
            fn=yolov10_inference_for_examples,
            inputs=[
                image,
                model_id,
                image_size,
                conf_threshold,
            ],
            outputs=[output_image],
            cache_examples='lazy',
        )
```

- 添加一些示例图像，用户可以直接点击这些示例进行测试。

### 8. 启动应用

```python
gradio_app = gr.Blocks()
with gradio_app:
    gr.HTML(
        """
    <h1 style='text-align: center'>
    YOLOv10: Real-Time End-to-End Object Detection
    </h1>
    """)
    gr.HTML(
        """
        <h3 style='text-align: center'>
        <a href='https://arxiv.org/abs/2405.14458' target='_blank'>arXiv</a> | <a href='https://github.com/THU-MIG/yolov10' target='_blank'>github</a>
        </h3>
        """)
    with gr.Row():
        with gr.Column():
            app()
if __name__ == '__main__':
    gradio_app.launch()
```

- 创建 Gradio 应用并启动。
- 显示应用标题和链接。

这段代码通过 Gradio 提供了一个简单易用的 Web 界面，用于实现 YOLOv10 模型的图像和视频对象检测。用户可以通过上传图像或视频，选择模型和参数，点击按钮即可进行检测并查看结果。







这段代码实现了使用YOLOv10模型进行实时视频检测，并在视频帧上绘制检测结果的功能。下面是对代码的详细讲解：

### 1. 导入必要的库
```python
import cv2
from ultralytics import YOLOv10
```
- `cv2` 是 OpenCV 库，用于图像处理和计算机视觉任务。
- `YOLOv10` 是从 `ultralytics` 库中导入的 YOLOv10 模型类。

### 2. 定义一个生成颜色的函数
```python
def generate_color():
    import random
    return (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
```
- 这个函数用于生成一个随机颜色，返回一个包含 RGB 三个分量的元组。

### 3. 初始化颜色字典
```python
colors = {}
```
- `colors` 字典用于存储每个类别对应的颜色，以便在绘制检测结果时保持颜色一致。

### 4. 加载模型和初始化摄像头
```python
model = YOLOv10("yolov10n.pt")
cap = cv2.VideoCapture(0)
```
- `model` 是 YOLOv10 模型实例，用于进行目标检测。
- `cap` 是视频捕获对象，通过摄像头实时获取视频流。

### 5. 实时视频处理循环
```python
while True:
    ret, frame = cap.read()
    if not ret:
        break  # 如果没有读取到帧，退出循环
```
- 使用 `cap.read()` 读取帧，如果没有读取到帧（如摄像头断开），则退出循环。

### 6. 进行目标检测
```python
    results = model.predict(frame)
```
- 使用模型对当前帧进行预测，返回检测结果。

### 7. 遍历每个预测结果
```python
    for result in results:
        boxes = result.boxes  # 获取边界框信息
        for box in boxes:
            x1, y1, x2, y2 = map(int, box.xyxy[0])
            cls = int(box.cls[0])
            conf = float(box.conf[0])
            
            # 如果类别还没有分配颜色，则生成一个新的颜色
            if cls not in colors:
                colors[cls] = generate_color()
            
            color = colors[cls]  # 获取类别对应的颜色
            cv2.rectangle(frame, (x1, y1), (x2, y2), color, 2)
            cv2.putText(frame, f'{model.names[cls]} {conf:.2f}', (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)
```
- 遍历每个检测结果，获取边界框、类别和置信度。
- 如果该类别尚未分配颜色，则生成一个新的颜色并存储在 `colors` 字典中。
- 使用 OpenCV 绘制边界框和类别标签。

### 8. 显示带有检测结果的帧
```python
    cv2.imshow('YOLOv10实时检测', frame)
    # 按'q'键退出
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
```
- 使用 `cv2.imshow` 显示当前帧。
- 按下 'q' 键退出循环。

### 9. 释放资源
```python
# 释放资源
cap.release()
cv2.destroyAllWindows()
```
- 释放摄像头资源并关闭所有 OpenCV 窗口。

这段代码的主要功能是通过 YOLOv10 模型对实时视频流进行目标检测，并将检测结果绘制在视频帧上显示出来。