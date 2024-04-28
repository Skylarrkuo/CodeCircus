
# 引入词频统计库
import collections
# 引入用于分词的 jieba 库
import jieba # type: ignore
# 引入用于生成词云的 wordcloud 库
import wordcloud # type: ignore
# 引入 Python Imaging Library (PIL) 中的 Image, ImageDraw 和 ImageFont 模块
from PIL import Image, ImageDraw, ImageFont # type: ignore
# 引入用于处理多维数组的 numpy 库
import numpy # type: ignore

# 读取用于生成词云的图片
BColor = numpy.array(Image.open("xyu.jpg"))
# 打开并读取文本文件
fi = open("ydh.txt", encoding="utf-8")
t = fi.read()
fi.close()
# 打开并读取停用词文本文件
fi = open("stopwords.txt", encoding="utf-8")
stop = fi.read()
fi.close()
# 对文本进行分词
ls = jieba.lcut(t)
txt = " ".join(ls)
# 去掉长度为1的词,包括标点
newls = []
for i in ls:
    if len(i) > 1:
        newls.append(i)
# 统计词频
counts = collections.Counter(newls)
for word in stop:  # 去掉停用词
    counts.pop(word, 0)
print(counts.most_common(20))
# 设置停用词,停用无用的词汇
stopwords = wordcloud.STOPWORDS
stopwords.update(stop)
# 配置词云生成器
w = wordcloud.WordCloud(
    background_color="white",  # 设置背景颜色为白色
    max_words=5000,  # 设置最大词数
    mask=BColor,  # 设置词云形状的遮罩图片
    max_font_size=400,  # 设置最大字体大小
    random_state=47,  # 设置随机种子,保证每次运行生成的词云相同
    font_path="sarasa-ui-sc-semibold.ttf",  # 设置中文字体
    stopwords=stopwords,
)

# 生成词云
w.generate(txt)
# 生成颜色映射器
image_colors = wordcloud.ImageColorGenerator(BColor)
# 颜色映射器image_colors对词云图进行重新着色
w.recolor(color_func=image_colors)
# 将词云保存为图片文件
w.to_file("YDH.png")

# 打开生成的词云图片
img = Image.open("YDH.png")
# 创建一个可以在给定图像上绘图的对象
word = "数领先驱" 
# 设置字体和大小
SimHei = "sarasa-ui-sc-bolditalic.ttf"    # 一个字体文件
font = ImageFont.truetype(SimHei, 300)  # 设置字体和大小
# 计算出要写入的文字占用的像素
# 计算文字的宽度和高度
wh = font.getbbox(word)
d = ImageDraw.Draw(img)

# 计算图片的中心位置
W, H = img.size
x = (W - wh[2])/2 - 500
y = (H - wh[3])/2 - 700
# 在图片的中心位置打印文字s
d.text((x, y), word, font=font, fill=(0,61, 53, 255))

# 创建一个可以在给定图像上绘图的对象
word = "智创未来" 
# 计算文字的宽度和高度
wh = font.getbbox(word)

# 计算图片的中心位置
W, H = img.size
x = (W - wh[2]) / 2 + 400
y = (H - wh[3]) / 2 - 100
d.text((x, y), word, font=font, fill=(0,61, 53, 255))

# 创建一个可以在给定图像上绘图的对象
word = "大数据与人工智能学院" 
# 计算文字的宽度和高度

font = ImageFont.truetype(SimHei, 230)  # 设置字体和大小
wh = font.getbbox(word)
d = ImageDraw.Draw(img)
# 计算图片的中心位置
W, H = img.size
x = (W - wh[2]) / 2
y = (H - wh[3]) / 2 +500
d.text((x, y), word, font=font, fill=(0,61, 53, 255))
# 保存修改后的图片
img.save("YDH.png")


