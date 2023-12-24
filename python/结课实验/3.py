'''
统计考试成绩中优秀,良好,中等,及格,不及格的人数.
[输入描述]
一组数.
[输出描述]
五级制人数统计结果.
[输入样例]
[89,70,49,87,92,84,73,71,78,81,90,37]
[输出样例]
{'优秀':2,'良好':4,'中等':4,'及格':0,'不及格':2}

'''
scores = []
scores=list(eval(input()))

# 初始化统计字典
result = {'优秀': 0, '良好': 0, '中等': 0, '及格': 0, '不及格': 0}

# 统计各个级别的人数
for score in scores:
    if score >= 90:
        result['优秀'] += 1
    elif 80 <= score < 90:
        result['良好'] += 1
    elif 70 <= score < 80:
        result['中等'] += 1
    elif 60 <= score < 70:
        result['及格'] += 1
    else:
        result['不及格'] += 1

print(result)
