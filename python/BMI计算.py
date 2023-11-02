# BMI计算.py
import math

bmi = 0.0
who=0
Leib=["偏瘦","正常","肥胖","偏胖"]

height = eval(input("输入身高："))
weight = eval(input("输入体重："))
bmi = height / math.pow(weight, 2)

if(bmi<18.5):
    who=0
elif(18.5 <= bmi<=25):
    who=1
elif(25<bmi<30):
    who=2
elif()