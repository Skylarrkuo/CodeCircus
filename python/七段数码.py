# e7.1DrawSevenSegDisplay.py
import turtle, datetime  # 导入turtle和datetime模块

def drawLine(draw):  # 定义函数，绘制单段数码管
    turtle.pendown() if draw else turtle.penup()  # 如果draw为True，则pen down；否则，pen up
    turtle.fd(20)  # 向前移动20个像素
    turtle.right(90)  # 向右转90度

def drawDigit(d):  # 定义函数，根据数字绘制七段数码管
    # 根据数字d的不同情况，选择是否绘制每个数码管的一部分
    drawLine(True) if d in [2, 3, 4, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if d in [0, 1, 3, 4, 5, 6, 7, 8, 9] else drawLine(False)
    drawLine(True) if d in [0, 2, 3, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if d in [0, 2, 6, 8] else drawLine(False)
    turtle.left(90)  # 向左转90度
    drawLine(True) if d in [0, 4, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if d in [0, 2, 3, 5, 6, 7, 8, 9] else drawLine(False)
    drawLine(True) if d in [0, 1, 2, 3, 4, 7, 8, 9] else drawLine(False)
    turtle.left(180)  # 向左转180度
    turtle.penup()  # 抬起画笔
    turtle.fd(20)  # 向前移动20个像素

def drawDate(date):  # 定义函数，获得要输出的数字
    for i in date:
        drawDigit(eval(i))  # 注意: 通过eval()函数将数字变为整数

def drawClear(num):
    turtle.color("white")  # 设置画笔颜色为白色
    turtle.pendown()  # 落下画笔
    turtle.fd(-40)  # 向后移动40个像素
    for i in range(1, num):
        drawDigit(8)  # 绘制数字8，相当于清空一个数码管
        turtle.fd(-80)  # 向后移动80个像素
    turtle.fd(40)  # 向前移动40个像素
    turtle.penup()  # 抬起画笔

def main():
    turtle.setup(800, 350, 200, 200)  # 设置窗口大小和位置
    turtle.speed(0)  # 设置绘制速度为最快
    turtle.penup()  # 抬起画笔
    turtle.fd(-300)  # 向前移动300个像素
    turtle.pensize(3)  # 设置画笔宽度为3个像素
    drawDate(datetime.datetime.now().strftime("%Y%m%d%H%M%S"))  # 绘制当前日期的数字
    while 1:  # 无限循环
        drawClear(7)  # 清空前7个数码管
        turtle.color("black")  # 设置画笔颜色为黑色
        drawDate(datetime.datetime.now().strftime("%H%M%S"))  # 绘制当前时间的数字
    turtle.exitonclick()  # 点击窗口关闭

main()  # 调用主函数
