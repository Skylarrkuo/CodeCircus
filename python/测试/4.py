"""
4.月球上物体的体重是在地球上的16.5%,假如你在地球上每年增长0.5kg
编写python程序,输入你的体重,输出未来10年你在地球上和月球上的体重.
测试样例:50
输入:地球上每年的体重:[50.0, 50.5, 51.0, 51.5, 52.0, 52.5, 53.0, 53.5, 54.0, 54.5]
输出:月球上每年的体重  [8.25, 8.33, 8.42, 8.5, 8.58, 8.66, 8.75, 8.83, 8.91, 8.99]

"""

earth_weight = float(input("请输入你的体重:"))
earth_weight_list = [earth_weight]
moon_weight_list = [earth_weight * 0.165]
for i in range(9):
    earth_weight += 0.5
    earth_weight_list.append(earth_weight)
    moon_weight_list.append(round(earth_weight_list[i + 1] * 0.165, 2))  # 保留了两位小数

# 50.0, 50.5, 51.0, 51.5, 52.0, 52.5, 53.0, 53.5, 54.0, 54.5
print("地球上每年的体重:" + str(earth_weight_list))
print("月球上每年的体重:" + str(moon_weight_list))
