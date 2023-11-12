# e7.1DrawSevenSegDisplay.py
import turtle, datetime


def drawLine(draw):  # 绘制单段数码管
    turtle.pendown() if draw else turtle.penup()
    turtle.fd(20)
    turtle.right(90)


def drawDigit(d):  # 根据数字绘制七段数码管
    drawLine(True) if d in [2, 3, 4, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if d in [0, 1, 3, 4, 5, 6, 7, 8, 9] else drawLine(False)
    drawLine(True) if d in [0, 2, 3, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if d in [0, 2, 6, 8] else drawLine(False)
    turtle.left(90)
    drawLine(True) if d in [0, 4, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if d in [0, 2, 3, 5, 6, 7, 8, 9] else drawLine(False)
    drawLine(True) if d in [0, 1, 2, 3, 4, 7, 8, 9] else drawLine(False)
    turtle.left(180)
    turtle.penup()
    turtle.fd(20)


def drawDate(date):  # 获得要输出的数字
    for i in date:
        drawDigit(eval(i))  # 注意: 通过eval()函数将数字变为整数


def main():
    turtle.setup(800, 350, 200, 200)
    turtle.speed(20)
    turtle.penup()
    turtle.fd(-300)
    turtle.pensize(3)
    drawDate(datetime.datetime.now().strftime("%Y%m%d%H%M%S"))
    turtle.penup()
    while(1):
        for i in range(1,132):
            turtle.undo()
        turtle.speed(200)
        drawDate(datetime.datetime.now().strftime("%H%M%S"))
    turtle.exitonclick()


main()
