'''
算法:BMI计算
输入:身高和体重
输出:BMI值和身体状态

1. 输入身高和体重
2. 计算BMI值:BMI = 体重 / 身高的平方
3. 输出BMI值
4. 根据BMI值判断身体状态:
   - 如果BMI值小于18.5,身体状态为偏瘦
   - 如果BMI值在18.5到25之间,身体状态为正常
   - 如果BMI值在25到30之间,身体状态为肥胖
   - 如果BMI值大于等于30,身体状态为偏胖
5. 输出身体状态
'''
# BMI计算.py
import math

bmi = 0.0
who = 0 #国际标准的身体状态
whoch = 0#国内标准的身体状态
Leib = ["偏瘦", "正常", "肥胖", "偏胖"]

height = eval(input("输入身高:"))  # 输入身高
weight = eval(input("输入体重:"))  # 输入体重
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
print("你的身体:")
print("国际:{}; 国内:{}".format(Leib[who], Leib[whoch]))

'''
在编写这段代码的过程中,我学到了如何计算BMI值并根据BMI值判断身体状态.
通过输入身高和体重,我能够通过简单的计算得到BMI值,
并根据国际和国内的标准判断身体状态.
这个代码让我更加了解了BMI的概念和使用方法.
此外,编写代码的过程中,我也学到了一些Python的基本语法和数学运算的使用方法.
我学会了使用math库中的pow函数计算身高的平方
,并使用format函数控制输出结果的格式.
'''