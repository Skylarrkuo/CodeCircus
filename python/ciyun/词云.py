"""
算法:生成政府工作报告词云
输入:政府工作报告文本(gov.txt),词云形状遮罩图片(guohui.jpg),中文字体文件路径
输出:保存的词云图像文件(wcloudzf.png)

1. 引入分词库jieba,词云库wordcloud,图像处理库PIL,多维数组库numpy.
2. 读取用于生成词云的背景图片,存储为BColor数组.
3. 打开文本文件gov.txt,读取其中的文本内容.
4. 使用jieba进行中文分词,生成词列表ls.
5. 将分词结果拼接为字符串txt.
6. 设置停用词stopwords,过滤无用词汇
7. 配置词云生成器w,设置背景颜色,最大词数,词云形状,最大字体大小,随机种子,中文字体和停用词.
8. 生成词云w,使用generate方法.
9. 生成颜色映射器image_colors,用BColor进行初始化.
10. 对词云图进行重新着色,使用recolor方法和颜色映射器image_colors.
11. 将生成的词云保存为图片文件wcloudzf.png.
"""
# 引入词频统计库
import collections

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
fi = open("三国演义.txt", encoding="utf-8")
t = fi.read()
fi.close()

fi = open("stopwords.txt", encoding="utf-8")
stop = fi.read()
fi.close()
# 对文本进行分词
ls = jieba.lcut(t)
txt = " ".join(ls)

# 去掉长度为1的词，包括标点
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
    max_words=1750,  # 设置最大词数
    mask=BColor,  # 设置词云形状的遮罩图片
    max_font_size=225,  # 设置最大字体大小
    random_state=42,  # 设置随机种子,保证每次运行生成的词云相同
    font_path="sarasa-ui-sc-lightitalic.ttf",  # 设置中文字体
    stopwords=stopwords,
)
# 生成词云
w.generate(txt)
# 生成颜色映射器
image_colors = wordcloud.ImageColorGenerator(BColor)
# 颜色映射器image_colors对词云图进行重新着色
w.recolor(color_func=image_colors)
# 将词云保存为图片文件
w.to_file("wcloudzf.png")

"""
实验使用Python中的jieba,wordcloud,PIL和numpy等库,
展示了文本分词和词云生成的过程.通过处理政府工作报告文本,
呈现了词云的形状,颜色,并保存为图片.
通过本次实验学会了如何利用Python进行文本处理和可视化的实际应用.
"""
