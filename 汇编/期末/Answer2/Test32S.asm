;************************************************************************
;请把下一行注释中的XXX、YYYYYY改成你的姓名和学号
;姓名:XXX, 学号:YYYYYY
;【循环分支程序设计】本题共20分
;试编写一程序，求出首地址为DATA的100D字数组中的最小偶数，并把它
;存放在变量MINEVEN中,处理完毕显示'Processing Completed!'信息。（假设
;偶数肯定存在）
;要求源程序中包含完善的注释信息。做题时不要损坏题中原有的注释线。
;**************************（评分标准）***********************************
;（1）有完善的注释信息2分；
;（2）变量定义正确2分；
;(3)算法正确,12分(其中，循环结构正确6分，其它6分)；
;(4)指令无语法错误，能编译成EXE文件4分。
;***********************************************************************
DATAS SEGMENT
    DATA	DW 100 DUP(?)
;--------------------------所需变量定义于两横线之间------------------
	MINEVEN DW ?
	Completed DB 'Processing Completed!',0dh,0ah,'$'
;------------------------------------------------------------------------ 
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
    ;输入100个数存于字数组DATA（代码略）
;--------------------------程序代码写于两横线之间---------------------
	MOV CX,100
	MOV SI,0
NextSeek:
	MOV AX,DATA[SI]	;找第1个偶数
	SHR AX,1
	JNC FoundEven
	ADD SI,2
	LOOP NextSeek
	JMP Exit
FoundEven:			;找到第1个偶数
	MOV AX,DATA[SI]	;将其放入AX中,AX存放目前找到的最小偶数
	DEC CX			;剩余元素数见1，SI指向下一个数
	ADD SI,2
NextCmp:
	MOV BX,DATA[SI]	;判断SI所指的数是否偶数
	SHR BX,1
	JC Continue
	CMP AX,DATA[SI]	;已确定SI所指的数是偶数,如果它比AX小
	JNG Continue
	MOV AX,DATA[SI]	;用该数替换AX中的数
Continue:
	ADD SI,2
LOOP NextCmp	 
	MOV MINEVEN,AX	;将找到的最小偶数放入指定变量中	
Exit:
;--------------------------------------------------------------------------
	;显示最小的偶数（代码略）
	MOV AH,9
	MOV DX,OFFSET Completed
	INT 21H 
    MOV AX,4C00H
    INT 21H
CODES ENDS
    END START
