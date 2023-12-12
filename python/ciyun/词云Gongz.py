# 引入用于分词的 jieba 库
import jieba
# 引入用于生成词云的 wordcloud 库
import wordcloud
# 引入 Python Imaging Library (PIL) 中的 Image 模块
from PIL import Image
# 引入用于处理多维数组的 numpy 库
import numpy

# 读取用于生成词云的图片
BColor = numpy.array(Image.open("gz.png"))

# 打开并读取文本文件
fi = open("hamlet.txt", encoding="utf-8")
t = fi.read()
# 对文本进行分词
ls = jieba.lcut(t)
txt = " ".join(ls)
# 设置停用词,停用无用的词汇
#//stopwords = wordcloud.STOPWORDS
#//stopwords.update({"的", "和", "对", "要", "等","曰","矣","也","乃","了","又","去","为","在"})

# 配置词云生成器
w = wordcloud.WordCloud(
    background_color="white",  # 设置背景颜色为白色
    max_words=1750,  # 设置最大词数
    mask=BColor,  # 设置词云形状的遮罩图片
    max_font_size=225,  # 设置最大字体大小
    random_state=42,  # 设置随机种子,保证每次运行生成的词云相同
    font_path="sarasa-ui-sc-lightitalic.ttf",  # 设置中文字体
    #//stopwords=stopwords,
)
# 生成词云
w.generate(txt)
# 生成颜色映射器
image_colors = wordcloud.ImageColorGenerator(BColor)
# 颜色映射器image_colors对词云图进行重新着色
w.recolor(color_func=image_colors)
# 将词云保存为图片文件
w.to_file("wcloud.png")

