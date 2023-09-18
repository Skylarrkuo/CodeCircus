#温度转换.py
Temp=input("输入带符号的温度值:")
#对输入数据进行判断
if(Temp[-1] in ['C','c']):
    #使用转换公式进行温度转换
    print("转换后的温度表示为：{:.2}F".format(eval(Temp[0:-1])*1.8+32))
elif(Temp[-1] in ['F','f']):
    print("转换后的温度表示为：{:.2}C".format((eval(Temp[0:-1])-32)/1.8))
else:
    print("输入格式错误")