from turtle import *
setup(650,350,200,200)
for i in range(0,1000):
    if(i%2==0):
        circle (i,1)
    else:
        circle(-i,10)