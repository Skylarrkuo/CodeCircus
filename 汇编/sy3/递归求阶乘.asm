CODES SEGMENT
    ASSUME CS:CODES,DS:CODES
    INPUT_MSG	DB 'INPUT A NUMBER:$'
    OUTPUT_MSG	DB '!=$'
    ERR_MSG		DB '!>65535$'
START:
	;使DS指向代码段
    PUSH CS
    POP DS
    
    ;显示输入提示信息
    MOV AH,9
    LEA DX,INPUT_MSG
    INT 21H
    
    ;接收一个十进制数到CX中
    CALL DECBIN
    
    ;将AX以十进制形式显示
    MOV AX,CX
    CALL DISP
    
    ;计算(CX)!,如果结果不大于65535,
    			;将结果放在AX中,置CF=0
    			;否则,置CF=1
    CALL FACT
    JC S1
    
    ;显示输出提示信息
	PUSH AX
    MOV AH,9
    LEA DX,OUTPUT_MSG
    INT 21H
    POP AX
    
    ;将AX中的数以十进制的方式显示在显示器上
    CALL DISP
    JMP S2
    
    ;结果太大,显示错误信息
S1: MOV AH,9
    LEA DX,ERR_MSG
    INT 21H

    
S2: MOV AH,4CH
    INT 21H
    
    
;十化二子程序,结果在CX中
DECBIN	PROC
	PUSH AX
	PUSH BX
	PUSH DX
	XOR CX,CX
D0:	MOV AH,1
	INT 21H
	CMP AL,'0'
	JB D1
	CMP AL,'9'
	JA D1
	SUB AL,30H
	MOV AH,0
	XCHG AX,CX
	MOV BX,10
	MUL BX
	XCHG AX,CX
	ADD CX,AX
	JMP D0
D1:
	POP DX
	POP BX
	POP AX
	RET
DECBIN	ENDP

;计算(CX)!递归子程序,结果在AX中,结果超过65535时置进位返回
FACT	PROC
	PUSH DX
	CMP CX,1	;0和1的阶乘均为1,直接给结果,不需计算
	JA F1
	MOV AX,1
	CLC
	JMP F2
	
F1:	
	PUSH CX
	DEC CX		;递归计算(CX-1)!,结果在AX中
	CALL FACT
	POP CX
	JC F2
	MUL CX		;计算(CX)*(CX-1)!
				;结果大于65535时CF=1,否则CF=0
	
F2:	
	POP DX
	RET
FACT	ENDP

;二化十递归子程序,将AX中的数以十进制的方式显示在显示器上
DISP	PROC
	PUSH AX
	PUSH CX
	PUSH DX
	XOR DX,DX   ;将DX清零,用于存储余数.
	MOV CX,10  ;将CX寄存器的值设置为10,用于进行除法操作.
	DIV CX  ;使用DIV指令将AX中的值除以CX,商存入AX,余数存入DX.
	
	CMP AX,0 ;比较商是否为零
	JZ D1
	CALL DISP	;如果高位不位0,则递归显示高位数字

D1:
	ADD DL,30H
	MOV AH,2
	INT 21H
	POP DX
	POP CX
	POP AX
	RET
DISP	ENDP

;二化十非递归子程序,将AX中的数以十进制的方式显示在显示器上
STRING	DB 5 DUP(?),'$'
DISP1	PROC
	PUSH AX
	PUSH CX
	PUSH DX
	PUSH SI
	
	;将AX中的二进制数转化为十进制字符串存入STRING
	LEA SI,STRING+5	;使SI为STRING字符串结束符$的地址
	MOV CX,10
L0:	
	XOR DX,DX
	DIV CX			;(DX:AX)/10,商在AX中,余数在DX中
	ADD DL,30H
	DEC SI
	MOV [SI],DL
	CMP AX,0
	JNZ L0
	
	;显示转化为十进制的字符串
	MOV AH,9
	MOV DX,SI
	INT 21H
	
	POP SI
	POP DX
	POP CX
	POP AX
	RET
DISP1	ENDP

CODES ENDS
    END START




