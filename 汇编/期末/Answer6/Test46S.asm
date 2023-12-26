;************************************************************************
;请把下一行注释中的XXX、YYYYYY改成你的姓名和学号
;姓名:XXX, 学号:YYYYYY
;【综合应用程序设计】本题共40分
;已知字数组A中保存着10个无符号整数,依次为:
;23, 56, 83, 52, 100, 88, 78, 25, 34, 123。
;编写程序，先以十进制形式显示数组A，然后计算这10个数的和(假设和
;不超过16位无符号数的表示范围)，最后把和以十进制形式显示出来。
;并满足下列要求:
;（1）必须使用子程序结构；
;（2）要求程序运行时有友好的提示信息;
;（3）要求源程序中包含完善的注释信息。
;注意：做题时不要损坏题中原有的注释线。
;******************************评分标准*********************************
;（1）有完善的注释信息(特别是子程序入口参数说明) 6分
;（2）有友好的提示信息 4分
;（3）定义了所需变量 4分
;（4）主程序和子程序结构定义正确6分（其中，主程序2分，每个子程序2分）
;（5）主程序算法正确 7分（其中循环结构正确4分,其它3分）
;（6）显示相关的两个子程序算法正确 7分（其中循环结构正确4分,其它3分）
;（7）指令书写正确，能编译成EXE文件且执行时不死机 6分
;************************************************************************
DATAS SEGMENT
	Prompt1 DB 'Array Elements: ',0dh,0ah,'$'
	Prompt2 DB 0dh,0ah,'The sum of array elements is : $'
;-------------------------所需变量定义于两横线之间-------------------
	A      DW 23, 56, 83, 52, 100, 88, 78, 25, 34, 123
	DECIMAL  DB 6 DUP(20H),'$' ;保存十进制数
;------------------------------------------------------------------------
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
;--------------------------程序代码写于两横线之间---------------------
;主程序
Main PROC Far
	MOV AX, DATAS
	MOV DS, AX
	MOV ES, AX
	MOV AH, 9
	MOV DX, OFFSET Prompt1
	INT 21H
	CALL DisplayDec10 ;显示数组元素
	MOV AH,9
	MOV DX, OFFSET Prompt2
	INT 21H
	;计算数组A的和于BX
	MOV CX,10
	MOV BX,0
	MOV SI,0
Next:
	ADD BX, A[SI]
	ADD SI,2
	LOOP Next
	CALL DisplayDec ;显示BX中和
	MOV AH,2
	MOV DL, 0dh
	INT 21H
	MOV DL,0ah
	INT 21H	
	MOV AX, 4c00H
	INT 21H
Main ENDP
;.........................................................................
;子程序:以十进制形式显示字数组A
DisplayDec10 PROC Near
	MOV CX,10
	MOV SI,0
Next:
	PUSH CX 
	PUSH SI 
	MOV BX,A[SI]
	CALL DisplayDec ;显示BX的值	
	POP SI
	POP CX
	ADD SI,2
	LOOP Next
	RET
DisplayDec10 ENDP
;.........................................................................
;子程序：把BX中的数以十进制形式显示于屏幕
;不保护寄存器的值
DisplayDec PROC Near
	MOV CX, 6
	MOV AL, 20H
	LEA DI,DECIMAL
	REP STOSB 
	MOV DI, 5      ;余数存储初始位
	MOV AX, BX  ;因为被除数必须放在AX中
NextDig:
	MOV DX, 0
	MOV BX,10
	DIV BX       ;(DX,AX)/10, 余DX、商AX
	OR DL, 30H  ;转换成ASCII字符
	MOV DECIMAL[DI], DL
	DEC DI
	CMP AX,0
	JNZ NextDig
	MOV AH, 9    ;显示转换后的结果
	LEA DX, DECIMAL
	INT 21H
	RET
DisplayDec ENDP
;-------------------------------------------------------------------------- 
CODES ENDS
    END Main