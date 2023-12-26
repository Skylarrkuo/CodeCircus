;************************************************************************
;请把下一行注释中的XXX、YYYYYY改成你的姓名和学号
;姓名:XXX, 学号:YYYYYY
;【综合应用程序设计】本题共40分
;编写一个有主程序和子程序结构的程序模块。子程序的参数是一个
;N字节数组的首地址TABLE，数N及字符CHAR。要求在N字节数组中查找字
;符CHAR，并记录该字符的出现次数。主程序则要求从键盘接收一串字符
;(回车结束)以建立字节数组TABLE，并逐个显示从键盘输入的每个字符
;CHAR(回车结束)以及它在TABLE数组中出现的次数（为简化起见，假设出
;现次数≤15，可以用十六进制形式把它显示出来）。并满足下列要求:
;（1）必须使用子程序结构；
;（2）要求程序运行时有友好的提示信息;
;（3）要求源程序中包含完善的注释信息。
;注意：做题时不要损坏题中原有的注释线。
;******************************评分标准*********************************
;（1）有完善的注释信息 6分(特别是子程序入口参数说明) 6分
;（2）有友好的提示信息 4分
;（3）定义了所需变量 4分
;（4）主程序和子程序结构定义正确6分（其中，主程序3分，子程序3分）
;（5）主程序算法正确 7分（其中循环结构正确4分,其它3分）
;（6）子程序算法正确 7分（其中循环结构正确4分,其它3分）
;（7）指令书写正确，能编译成EXE文件且执行时不死机 6分
;************************************************************************
DATAS SEGMENT
	InputTip DB 'Please enter a String:',0dh,0ah,'$'
	CharTip  DB 0dh,0ah, 'Please enter a char: $'
;-------------------------所需变量定义于两横线之间-------------------
	TABLE DB  100 DUP (?) 
	N DW ?
	CHAR DB ?
;------------------------------------------------------------------------
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
;--------------------------程序代码写于两横线之间---------------------
;主程序
Main 	PROC Far
	MOV AX,DATAS
	MOV DS, AX
	MOV ES, AX
	MOV AH,9
	LEA DX, InputTip ;显示提示信息
	INT 21H
	MOV SI, 0
Next:
	MOV AH,1
	INT 21H
	CMP AL, 0dh
	JE Again
	MOV TABLE[SI],AL
	INC SI
	JMP Next	
Again:
	MOV N, SI
	MOV AH, 9
	LEA DX,  CharTip 
	INT 21H
	MOV AH,1
	INT 21H
 	CMP AL, 0dh
	JE Exit
	MOV CHAR, AL
	CALL CharCount

Exit:
	MOV AX,4c00h
	INT 21H
Main 	ENDP
;.........................................................................
;子程序: 统计CHAR在字符串TABLE中出现的次数并显示
CharCount 	PROC  
	MOV CX, N
	MOV SI, 0
	MOV DL, 0  ;次数初值0
	MOV AL, CHAR	
Next:
	CMP AL, TABLE[SI]
	JNE Continue
	INC DL
Continue:
	INC SI
	LOOP Next
	
	CMP DL,10
	JNB G10
	ADD DL,30H
	JMP DisplayCount
G10:
	ADD DL,37H
DisplayCount: 
	MOV AH,2
	INT 21H
		
	RET
CharCount 	ENDP
;-------------------------------------------------------------------------- 
CODES ENDS
    END Main
