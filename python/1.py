a=input('输入n:')

def fun(n):
    for i in range(1,n):
        for j in range(1,i):
            x = x + 1 / j
        s=s+x

    return s

print("结果为：",fun(a))