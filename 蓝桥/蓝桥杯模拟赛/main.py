n=0
for dec in range(1,10000):
    b=bin(dec)[2:]
    sum1=0
    for i in b[0:]:
        sum1+=int(i)
    o=oct(dec)[2:]
    sum2=0
    for i in o[0:]:
        sum2+=int(i)
    if(sum1==sum2):
        n+=1
        print("{}:{} >> {} >> b={},o={}".format(n,dec,sum2,b,o))