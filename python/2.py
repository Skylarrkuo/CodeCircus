a=input('�б�:').split(",")
list1=[float(a[i]) for i in range(len(a))]
print("������б�Ϊ:",list1)

def fun(x):
    s = 0
    for i in range(0, len(list1)-1):
        j=i+1
        s +=(x[i] **0.5) +(x[j] **0.5)
    return s 
   
print("ʵ���б�����Ԫ��ƽ����֮��Ϊ:",fun(list1))    
