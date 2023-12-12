'''
编写一个程序,实现如下功能:判断一个数字是否同时能被2和3整除,若能,输出"YES",若不能,输出"NO",
测试样例:1
输出:NO
测试样例:12
输出:YES
测试样例:五
输出:请输入有效的阿拉伯数字
'''

# 用户输入数字
shu = input("请输入一个数字:")

# 判断输入是否为数字
if shu.isdigit():
    num = int(shu)
    if num % 2 == 0 and num % 3 == 0:
        print("YES")
    else:
        print("NO")
else:
    print("请输入有效的阿拉伯数字")
