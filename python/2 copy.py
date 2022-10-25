a=int(input('输入n:'))

def fun(n):
    s=0
    i=1
    while i<=n:
        x=0
        j=1
        while j<=i:
            x += j
            j+=1
        s=s+1/x
        i+=1

    return s

print("结果为：",fun(a))
