; 汇编语言程序：计算BMI值

assume cs:code
data segment
    weight dw 0  ; 体重，单位：kg
    height dw 0  ; 身高，单位：cm
    bmi dw 0     ; 存储计算结果的变量
data ends

code segment
start:
    ; 初始化数据段寄存器
    mov bx, data
    mov ds, bx

    ; 从用户输入获取体重和身高
    call GetInput

    ; 将身高转换为米，计算BMI
    mov ax, height
    mov bx, 100  ; 将身高转换为米
    div bx      ; AX = height / 100
    mov height, ax

    ; 计算BMI：weight / (height * height)
    mov ax, weight
    imul ax, height
    imul ax, height
    mov bx, ax  ; 存储 height * height 的结果
    idiv bx     ; AX = weight / (height * height)
    mov bmi, ax

    ; 在此可添加显示BMI的代码，将结果显示在屏幕上

    ; 退出程序
    mov ax, 4c00h
    int 21h

GetInput:
    ; 从用户输入获取体重和身高
    ; 在实际应用中，需要更复杂的输入处理
    ; 这里简化为直接赋予固定值
    mov weight, 7000  ; 70 kg
    mov height, 175   ; 175 cm
    ret

code ends
end start
