# 计算小明需要多少天才能存够5000元
total_money = 0
days = 0

while total_money < 5000:
    days += 1
    total_money += 80
    if days % 21 == 0:
        total_money -= 80
    if days % 7 == 0:
        total_money -= 220

print("经过%d天,小明存到了%.2f元钱,可以购买电脑." % (days, total_money))
