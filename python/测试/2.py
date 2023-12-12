# 定义一个字典,存储月份和对应的单词
months = {
    1: "January",
    2: "February",
    3: "March",
    4: "April",
    5: "May",
    6: "June",
    7: "July",
    8: "August",
    9: "September",
    10: "October",
    11: "November",
    12: "December",
}
# 定义列表存储月份
monthx = [
    "无效月份",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
    "请输入有效的数字",
]

# 用户输入月份
month_input = input("请输入月份(1-12):")

# 判断输入是否为数字
# isdigit()用于检查字符串是否只包含数字字符
if month_input.isdigit():
    month = int(month_input)
    # if month in range(1, 13):
    #    print(monthx[month])
    if month in months:
        print(months[month])
    else:
        # print(monthx[0])
        print("无效月份")
else:
    # print(monthx[13])
    print("请输入有效的数字")
