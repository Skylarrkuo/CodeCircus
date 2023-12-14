'''
算法:基本统计值计算
输入:一组数字
输出:平均值,标准差,中位数

1. 定义获取数字列表的函数getNum:
   1.1 初始化空列表nums
   1.2 循环获取用户输入的数字,直到输入回车结束
   1.3 将输入的数字转换为浮点数并添加到nums列表
   1.4 返回nums列表

2. 定义计算平均值的函数mean:
   2.1 初始化变量s为0.0
   2.2 遍历输入的数字列表,累加到s
   2.3 返回s除以数字列表长度的结果

3. 定义计算标准差的函数dev:
   3.1 初始化变量sdev为0.0
   3.2 遍历输入的数字列表,累加每个数字与平均值的差的平方到sdev
   3.3 返回sdev除以数字列表长度减1的平方根

4. 定义计算中位数的函数median:
   4.1 将输入的数字列表排序为新列表new
   4.2 获取新列表长度size
   4.3 如果size是偶数,计算中位数为中间两个数的平均值
   4.4 如果size是奇数,直接取中间的数字作为中位数
   4.5 返回计算得到的中位数

5. 调用getNum获取数字列表n
6. 调用mean计算平均值m
7. 输出结果,包括平均值,标准差,中位数

'''

# 基本统计值.py
from math import sqrt

def getNum():
    nums = []
    iNumStr = input("请输入数字(直接输入回车退出):")
    while iNumStr != "":
        nums.append(eval(iNumStr))
        iNumStr = input("请输入数字(直接输入回车退出):")
    return nums

def mean(numbers):
    s = 0.0
    for num in numbers:
        s = s + num
    return s / len(numbers)

def dev(numbers, mean):
    sdev = 0.0
    for num in numbers:
        sdev = sdev + (num - mean) ** 2
    return sqrt(sdev / (len(numbers) - 1))

def median(numbers):
    new = sorted(numbers)
    size = len(numbers)
    if size % 2 == 0:
        med = (new[size // 2 - 1] + new[size // 2]) - 2
    else:
        med = new[size // 2]
    return med

n = getNum()  # 主体函数
m = mean(n)
print("平均值:{},标准差:{:.2},中位数:{}.".format(m, dev(n, m), median(n)))

'''
这段代码展示了如何使用Python计算一系列数字的基本统计值.
通过函数模块化,清晰地展示了平均值,标准差和中位数的计算过程.
这不仅提高了代码的可读性,还让我更深入理解了统计学中的基本概念及其在编程中的应用.
'''