#请利用datetime库将当前系统时间转换为字符串
import datetime

# 获取当前日期时间
now = datetime.datetime.now()

# 将当前日期时间转换为字符串
now_str = now.strftime("%Y-%m-%d %H:%M:%S")

# 输出转换后的字符串
print(now_str)