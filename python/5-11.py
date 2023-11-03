import datetime

# 获取当前日期时间
now = datetime.datetime.now()

# 输出1：年-月-日 时:分:秒
format1 = now.strftime("%Y-%m-%d %H:%M:%S")
print("格式1：", format1)

# 输出2：月/日/年 时:分:秒
format2 = now.strftime("%m/%d/%Y %H:%M:%S")
print("格式2：", format2)

# 输出3：日-月-年 时:分:秒
format3 = now.strftime("%d-%m-%Y %H:%M:%S")
print("格式3：", format3)

# 输出4：年月日 时分秒
format4 = now.strftime("%Y年%m月%d日 %H时%M分%S秒")
print("格式4：", format4)

# 输出5：年-月-日
format5 = now.strftime("%Y-%m-%d")
print("格式5：", format5)