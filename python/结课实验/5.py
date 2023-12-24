"""
上大家使用每一种网络服务都会遇到验证码,验证码一般是网站为了防止恶意注册,
发帖而设置的验证手段,其生成原理是将一串随机产生的数字或符号生成一幅图片,
图片中加上一些干扰像素.请使用Python生成验证码图片.
"""
# 导入所需的库
from PIL import Image, ImageDraw, ImageFont
import random

# 定义数字、小写字母和大写字母的列表
number = ['0','1','2','3','4','5','6','7','8','9']
alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
ALPHABET = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']

# 生成一个随机的4位验证码，包括数字和字母
def generate_code():
    code = ""
    for _ in range(4):
        code += random.choice(number + alphabet + ALPHABET)
    return code

# 创建背景颜色为随机颜色的图片对象
image = Image.new("RGB",(200, 100),color=(random.randint(100, 255), random.randint(100, 255), random.randint(100, 255)),)

# 设置绘图属性
draw = ImageDraw.Draw(image)
font = ImageFont.truetype("arial.ttf", size=random.randint(45, 55))

# 生成一个随机验证码并将其绘制在图片上
code = generate_code()
draw.text((40, 25), code, fill=(random.randint(0, 100), random.randint(0, 100), random.randint(0, 100)), font=font)

# 在图片上添加一些随机噪点
for _ in range(20):
    x = random.randint(0, 200)
    y = random.randint(0, 100)
    x1 = random.randint(0, 200)
    y1 = random.randint(0, 100)
    draw.point((x, y), fill=(0, 0, 0))
    draw.line([(x1, y1), (random.randint(100, 200), random.randint(50, 100))], fill=(random.randint(0, 100), random.randint(0, 100), random.randint(0, 100)), width=1)
    
# 将图片保存为文件
image.save("captcha.png")
