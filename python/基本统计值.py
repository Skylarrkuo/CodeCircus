'''
算法:基本统计值计算
输入:一系列数字
输出:平均值,标准差和中位数

1. 定义getNum函数:
   1.1 初始化空列表nums
   1.2 读取用户输入iNumStr,直到输入回车为止:
       1.2.1 将eval(iNumStr)添加到nums中
       1.2.2 重新读取用户输入iNumStr
   1.3 返回nums

2. 定义mean函数:
   2.1 初始化变量s为0.0
   2.2 对于numbers中的每个num:
       2.2.1 将s加上num
   2.3 返回s除以numbers的长度

3. 定义dev函数:
   3.1 初始化变量sdev为0.0
   3.2 对于numbers中的每个num:
       3.2.1 将sdev加上(num - mean)的平方
   3.3 返回sdev除以(numbers的长度-1)的平方根

4. 定义median函数:
   4.1 对numbers进行排序,得到新列表new
   4.2 计算numbers的长度,存储为size
   4.3 如果size是偶数:
       4.3.1 计算中位数med为(new[size // 2 - 1] + new[size // 2]) / 2
   4.4 否则:
       4.4.1 计算中位数med为new[size // 2]
   4.5 返回med

5. 调用getNum得到数字列表n
6. 计算平均值m为mean(n)
7. 输出结果,包括平均值,标准差和中位数
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