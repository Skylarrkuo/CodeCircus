# 引入用于生成词云的 wordcloud 库
import wordcloud
# 引入 Python Imaging Library (PIL) 中的 Image 模块
from PIL import Image
# 引入用于处理多维数组的 numpy 库
import numpy as np
# 引入用于绘图的 matplotlib 库的 pyplot 模块
import matplotlib.pyplot as plt
# 读取用于生成词云的图片
alice_coloring = np.array(Image.open("gz.png"))

# 打开并读取文本文件
fi = open("hamlet.txt")
txt = fi.read()

# 配置词云生成器
w = wordcloud.WordCloud(
    background_color="white",    # 设置背景颜色为白色
    max_words=1750,              # 设置最大词数
    mask=alice_coloring,         # 设置词云形状的遮罩图片
    max_font_size=175,           # 设置最大字体大小
    random_state=42,             # 设置随机种子，保证每次运行生成的词云相同
)

# 生成词云
w.generate(txt)

# 生成颜色映射器
image_colors = wordcloud.ImageColorGenerator(alice_coloring)

# 显示原始词云图
plt.imshow(w, interpolation="bilinear")
plt.axis("off")
plt.figure()

# 用颜色映射器着色后的词云图
plt.imshow(w.recolor(color_func=image_colors), interpolation="bilinear")
plt.axis("off")
plt.figure()

# 显示词云形状的遮罩图片
plt.imshow(alice_coloring, cmap=plt.cm.gray, interpolation="bilinear")
plt.axis("off")

# 将词云保存为图片文件
w.to_file("wcloud.png")
