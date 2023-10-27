# BMI计算.py
import math

bmi = 0.0
height = eval(input("输入身高："))
weight = eval(input("输入体重："))
bmi = height / math.pow(weight, 2)
