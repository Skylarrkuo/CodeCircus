a=input('����n:')

def fun(n):
    for i in range(1,n):
        for j in range(1,i):
            x = x + 1 / j
        s=s+x

    return s

print("���Ϊ��",fun(a))