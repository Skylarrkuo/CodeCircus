"""
有一个文本文件file.txt,其中每行包含一段英文.试用python读出文件的全部内容,并判断:
(1)该文本文件共有多少行?
(2)文件中以大写字母P开头的有多少行?
(3)一行中包含字符最多的和包含字符最少的分别在第几行?

"""

# 读取文件内容
f = open("python\\结课实验\\file.txt", "r", encoding="utf-8")
lines = f.readlines()  # 读取文件中的所有行到一个列表中
f.seek(0)  # 将文件指针重新移动到文本的起始位置
r = f.read()  # 读取整个文件的内容
print(r)  # 打印文件的内容
f.close()  # 关闭文件

# 统计文件总行数
total = len(lines)
print(f"总行数: {total}")

# 统计以大写字母P开头的行数
plines = []
for line in lines:
    if line.strip().startswith("P"):
        plines.append(line)
pcount = len(plines)
print(f"以大写字母P开头的行数: {pcount}")

# 找出一行中包含字符最多和最少的行数
maxline = max(lines, key=lambda x: len(x))
minline = min(lines, key=lambda x: len(x))

maxnumber = lines.index(maxline) + 1  # 行数从1开始
minnumber = lines.index(minline) + 1  # 行数从1开始

print(f"包含字符最多的行数: {maxnumber}, 字符数: {len(maxline)}")
print(f"包含字符最少的行数: {minnumber}, 字符数: {len(minline)}")
