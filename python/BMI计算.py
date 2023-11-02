# BMI计算.py
import math

bmi = 0.0
who = 0
whoch = 0
Leib = ["偏瘦", "正常", "肥胖", "偏胖"]

height = eval(input("输入身高："))  # 输入身高
weight = eval(input("输入体重："))  # 输入体重
bmi = weight / math.pow(height, 2)  # 计算BMI值
print("Your BMI={:.2f}".format(bmi))  # 输出BMI值

# 根据BMI值判断身体状态
if bmi < 18.5:
    who = whocn = 0
elif 18.5 <= bmi <= 25:
    who = 1
    if bmi >= 24:
        whoch = 2
    else:
        whoch = 1
elif 25 < bmi < 30:
    who = 2
    if bmi >= 28:
        whoch = 3
    else:
        whoch = 2
elif bmi >= 30:
    who = whocn = 3

# 输出身体状态
print("你的身体：")
print("国际：{}; 国内：{}".format(Leib[who], Leib[whoch]))
