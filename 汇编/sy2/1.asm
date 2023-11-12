DATAS SEGMENT
	; 数据段声明
	in_msg  db 'input hex: $'    ; 输入提示消息
	out_msg db 10,13,'output: $'  ; 输出提示消息
	inv     db 10,13,'invalid  $' ; 无效输入消息
DATAS ENDS

STACKS SEGMENT
	; 堆栈段声明（此代码中没有堆栈操作）
STACKS ENDS

CODES SEGMENT
	ASSUME CS:CODES,DS:DATAS,SS:STACKS  ; 设置段寄存器

START:
	MOV AX,DATAS    ; 将数据段地址加载到AX寄存器
	MOV DS,AX       ; 将数据段寄存器DS设置为AX的值

	; 输入代码段
	lea    dx,in_msg  ; 将输入消息的有效地址加载到DX寄存器
	mov    ah,09       ; 设置中断功能为打印字符串
	int    21h         ; 调用中断21h以打印输入消息
    
	xor    bx,bx       ; 清除BX寄存器以进行计算

	l0:   
	mov    ah,1        ; 设置中断功能为读取字符
	int    21h         ; 调用中断21h以读取字符
	cmp    al,0dh      ; 检查输入的字符是否为回车（Enter）
	je     l4          ; 如果是，跳转到标签l4（输入结束）
	cmp    al,'0'       ; 将输入的字符与'0'比较
	jb     l5          ; 如果小于，跳转到标签l5（无效输入）
	cmp    al,'9'       ; 将输入的字符与'9'比较
	ja     l1          ; 如果大于，跳转到标签l1
	sub    al,30h      ; 将ASCII字符转换为相应的数值
	jmp    l3          ; 跳转到标签l3

	l1:   cmp    al,'A'       ; 将输入的字符与'A'比较
	jb     l5          ; 如果小于，跳转到标签l5（无效输入）
	cmp    al,'F'       ; 将输入的字符与'F'比较
	ja     l2          ; 如果大于，跳转到标签l2
	sub    al,37h      ; 将ASCII字符转换为相应的数值
	jmp    l3          ; 跳转到标签l3

	l2:   cmp    al,'a'       ; 将输入的字符与'a'比较
	jb     l5          ; 如果小于，跳转到标签l5（无效输入）
	cmp    al,'f'       ; 将输入的字符与'f'比较
	ja     l5          ; 如果大于，跳转到标签l5（无效输入）
	sub    al,57h      ; 将ASCII字符转换为相应的数值

	l3:   mov    ah,0        ; 清除AH寄存器
	push   cx            ; 将CX寄存器的值保存到堆栈上
	mov    cl,4          ; 将CL寄存器设置为4，用于位操作
	shl    bx,cl         ; 将BX寄存器左移4位
	add    bx,ax         ; 将转换后的数值加到BX寄存器
	pop    cx            ; 从堆栈上恢复CX寄存器的值
	loop   l0            ; 循环回到标签l0，以读取下一个字符

	l4:   
	mov    dx,offset out_msg  ; 将输出消息的有效地址加载到DX寄存器
	mov    ah,9            ; 设置中断功能为打印字符串
	int    21h             ; 调用中断21h以打印输出消息
	mov    cx,16           ; 将CX寄存器设置为16（位数）
	mov    ax,8000h        ; 将AX寄存器设置为8000h（二进制：1000000000000000）

	l8:   
	push   ax               ; 将AX寄存器的值保存到堆栈上
	test   bx,ax            ; 测试BX的最左边的位是否设置
	jnz    l9               ; 如果是，跳转到标签l9
	mov    dl,'0'           ; 如果不是，将DL寄存器设置为'0'
	jmp    l10              ; 跳转到标签l10

	l9:   
	mov    dl,'1'           ; 将DL寄存器设置为'1'

	l10:  
	mov    ah,2            ; 设置中断功能为打印字符
	int    21h             ; 调用中断21h以打印字符
	pop    ax               ; 从堆栈上恢复AX寄存器的值
	shr    ax,1            ; 将AX寄存器右移1位
	loop   l8              ; 循环回到标签l8，以打印下一个位

	jmp    l6              ; 跳转到标签l6（程序结束）

	l5:   
	mov    ah,9            ; 设置中断功能为打印字符串
	mov    dx,offset inv   ; 将无效输入消息的有效地址加载到DX寄存器
	int    21h             ; 调用中断21h以打印无效输入消息

	l6:   
	MOV    AH,4CH          ; 设置中断功能为终止程序
	INT    21H             ; 调用中断21h以终止程序

CODES ENDS
END START
