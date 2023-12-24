assume cs:code
data segment
    db 9,8,7,4,2,0  ; 初始化数据段，存放BCD码的数组
data ends

code segment
start:
    ; 设置数据段寄存器
    mov bx, data
    mov ds, bx
    mov si, 0

    ; 设置显示缓冲区的地址
    mov bx, 0b800h
    mov es, bx
    mov di, 160 * 12 + 30 * 2  ; 在屏幕上选择一个位置显示日期和时间

    ; 循环显示日期时间
    mov cx, 6  ; 日期时间总共有6个部分
s0:
    push cx  ; 保存循环计数器
    mov al, ds:[si]  ; 从BCD数组中加载一个数字
    push ax  ; 保存数字

    inc si  ; 移动到下一个数字

    ; 从CMOS获取时间
    out 70h, al
    in al, 71h

    ; 处理BCD码转换为ASCII码
    mov ah, al
    mov cl, 4
    shr ah, cl
    and al, 00001111b

    add ah, 30h
    add al, 30h

    ; 显示年/月/日 时:分:秒
    mov byte ptr es:[di], ah
    add di, 2
    mov byte ptr es:[di], al
    add di, 2

    pop ax  ; 恢复数字
    cmp al, 0  ; 判断是否为最后一个数字
    je over

    cmp al, 7h  ; 判断是否是星期，星期不显示
    je kongge
    
    ja fanxiegang  ; 处理数字后的斜杠显示

    jb maohao  ; 处理数字后的冒号显示

fanxiegang:
    mov ax, '/'  ; 显示斜杠
    jmp next

maohao:
    mov ax, ':'  ; 显示冒号
    jmp next

kongge:
    mov ax, ' '  ; 显示空格
    jmp next

next:
    mov byte ptr es:[di], al  ; 显示处理后的字符
    add di, 2
over:
    pop cx  ; 恢复循环计数器
    loop s0  ; 继续循环

    ; 产生死循环，再从头开始执行程序
    jmp start

mov ax, 4c00h
int 21h
code ends
end start

