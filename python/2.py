a=input('列表:').split(",")
list1=[float(a[i]) for i in range(len(a))]
print("输入的列表为:",list1)

def fun(x):
    s = 0
    for i in range(0, len(list1)-1):
        j=i+1
        s +=(x[i] **0.5) +(x[j] **0.5)
    return s 
   
print("实数列表相邻元素平方根之和为:",fun(list1))    
