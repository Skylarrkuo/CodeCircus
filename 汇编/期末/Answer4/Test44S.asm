;************************************************************************
;请把下一行注释中的XXX、YYYYYY改成你的姓名和学号
;姓名:XXX, 学号:YYYYYY
;【综合应用程序设计】本题共40分
;编写程序，从键盘输入一个十进制整数（0-65535），然后把它以十六进制
;形式显示出来。并满足下列要求:
;（1）必须使用子程序结构；
;（2）要求程序运行时有友好的提示信息;
;（3）要求源程序中包含完善的注释信息。
;注意：做题时不要损坏题中原有的注释线。
;******************************评分标准*********************************
;（1）有完善的注释信息(特别是子程序入口参数说明) 6分
;（2）有友好的提示信息 4分
;（3）定义了所需变量 4分
;（4）主程序和子程序结构定义正确6分（其中，主程序2分，每个子程序2分）
;（5）输入子程序算法正确 7分（其中循环结构正确4分,其它3分）
;（6）显示子程序算法正确 7分（其中循环结构正确4分,其它3分）
;（7）指令书写正确，能编译成EXE文件且执行时不死机 6分
;************************************************************************
DATAS SEGMENT
	Prompt1 DB 'Please Enter 1 Number(0-65535): $';请输入10个数
	Prompt2 DB 0dh,0ah,'Its Hexadecimal Representation is: $'
	ErrMsg  DB 0dh,0ah,'Overflow error for data! Try Again: $' ;数据溢出错误
;-------------------------所需变量定义于两横线之间-------------------
	HexCode  DB '0123456789ABCDEF' ;十六进制转码用
;------------------------------------------------------------------------
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
;--------------------------程序代码写于两横线之间---------------------
;主程序
Main PROC Far
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
    MOV AH,9
    MOV DX, OFFSET Prompt1
    INT 21H       ;显示提示信息
    CALL GetDecimal ;输入1个数存于BX
    MOV AH,9
    MOV DX, OFFSET Prompt2
    INT 21H       ;显示提示信息
    CALL DisplayHex ;显示BX中的数
    MOV AH, 2
    MOV DL, 0dh
    INT 21H
    MOV DL,0ah
    INT 21H
	MOV AX, 4c00h
	INT 21H
Main ENDP
;.......................................................................
;子程序： 把BX中二进制数以十六进制形式显示于屏幕
DisplayHex PROC Near
	MOV CX, 4    ;设置循环次数
AGAIN:
    PUSH CX       ;保护循环次数
	MOV CL, 4     ;置循环移位次数
	ROL BX, CL
	PUSH BX       ;保护BX的值
	MOV AL, BL
	AND AL, 0FH
	MOV BX, OFFSET HexCode
	XLAT           ;转换成16进制数码
	MOV DL,AL
	MOV AH,02
	INT 21H        ;显示该数码
	POP BX         ;恢复BX的值
	POP CX         ;恢复CX的值
	LOOP AGAIN
	RET
DisplayHex ENDP
;.......................................................................
;子程序：从键盘输入一个十进制数并转换成二进制数存入BX
GetDecimal PROC Near
Again:
	MOV BX, 0
NextChar:
	MOV AH, 1      ;输入1字符
	INT 21H           ;字符ASCII在AL 
	CMP  AL, '0'
	JB Return    ;输入结束
	CMP  AL, '9'
	JA Return    ;输入结束
	PUSH AX         ; 输入的字符暂存堆栈
	MOV AX, BX 
	MOV BX, 10
	MUL BX           ;积在(DX,AX)中
	POP BX            ;恢复输入的字符于BL
	AND BX,000FH; 数码字符转数字
	ADD AX, BX 
	ADC DX, 0 
	CMP DX, 0
	JA NumOver    ;溢出，转显示错误
	MOV BX, AX    ;已输入的数存于BX
	JMP NextChar
NumOver:
	MOV AH,9
	MOV DX,OFFSET ErrMsg
	INT 21H       ;显示输入错误信息
	JMP Again
Return:
	RET
GetDecimal ENDP
;-------------------------------------------------------------------------- 
CODES ENDS
    END Main