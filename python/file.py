from PIL import Image
ascii_char = list("sgsdgsdfgsdfgsdgsdgsd")
fname=input("输入要打开的文件:")
fo=open(fname,"r")
for line in fo:
    print(line)
fo.close
