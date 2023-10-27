#Π的计算
import time
time.process_time()

#BBP公式求解法
PI=0.0
for k in range(0,10000):
    PI+=(1/(16**k))*((4/(8*k+1)) - (2/(8*k+4)) - (1/(8*k+5)) - (1/(8*k+6)))

'''
#掷点数求解法
import random
import math
n=a=0.0
#random.seed(9999)  #定义一个随机种子使生成结果一致
for i in range(1,100000):
    x=random.random()
    y=random.random()
    r=math.sqrt(math.pow(x,2)+math.pow(y,2))
    if(r<=1.0):
        n=n+1.0#圆内点数++
    a=a+1.0#总点数++
PI=4*(n/a)
'''
print("Π的值是：{:.10f}".format(PI))
print("运行时间是{:.5}s".format(time.process_time()))