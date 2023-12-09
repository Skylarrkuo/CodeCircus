import jieba
# 引入用于生成词云的 wordcloud 库
import wordcloud
# 设置词云文本
fi = open("gov.txt",encoding='utf-8')
t = fi.read()
ls=jieba.lcut(t)
txt=" ".join(ls)
# 配置词云生成器
w = wordcloud.WordCloud(
    background_color="white",    # 设置背景颜色为白色
    width=800,
    height=800,
    font_path="msyh.ttc",
    random_state=42,             # 设置随机种子，保证每次运行生成的词云相同
)
# 生成词云
w.generate(txt)
w.to_file("wcloudsm.png")
