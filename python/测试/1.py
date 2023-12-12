scores = [8.5, 9.0, 7.5, 8.0, 9.5, 9.5, 9.5, 7.5, 8.8, 8.9]
# 去掉一个最高分
max_score = max(scores)
scores.remove(max_score)
# 去掉一个最低分
min_score = min(scores)
scores.remove(min_score)
# 计算其余评委分数的平均值
average_score = round(sum(scores) / len(scores), 2)
print(average_score)
