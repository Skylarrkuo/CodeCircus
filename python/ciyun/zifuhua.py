from PIL import Image
import easygui as eg
import os

pth = eg.fileopenbox(title="请打开要转换的图片")  # 打开图片
dir = os.path.dirname(pth)  # 返回图片所在的路径
name = os.path.basename(pth)  # 返回图片名称及扩展名
name = os.path.splitext(name)[0]  # 返回图片名称
out_name = os.path.join(dir, name + ".txt")  # 输出的名字及路径
img = Image.open(pth)
out_img = img.convert("L")  # 图片转换为灰度模式
w, h = out_img.size  # 返回图片大小
n = 600 / max(w, h)  # 图像缩小倍数，不然图片转换后会很大
if n < 1:
    out_img = out_img.resize((int(w * n), int(h * n * 0.5)))  # 因字符的宽度一般大于2倍的高度
else:
    out_img = out_img.resize((int(w), int(h)))
w, h = out_img.size
# asciis='$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,"^\ '
asciis = "秦q玮y艺w_+~<>i!lI;:,^\ "  # 灰度表
texts = ""
for row in range(h):
    for col in range(w):
        gray = out_img.getpixel((col, row))
        texts += asciis[int(gray / 255 * (len(asciis) - 1))]  # 根据灰度值选择不同复杂度的 ASCII 字符
    texts += "\n"
with open(out_name, "w") as file:
    file.write(texts)
    file.close()
