# 计算小明需要多少天才能存够5000元
import datetime
天数 = 0
金额 = 0
起始日期 = datetime.date(2022,9,5)
while 金额 < 5000:
    
    天数 += 1
    金额 += 80
    if (起始日期+datetime.timedelta(天数)).isoweekday()== 7:
        金额 -= 220
    if 天数%21 == 0:
         金额 -= 80

print("经过%d天,小明存到了%.2f元钱,可以购买电脑." % (天数, 金额))