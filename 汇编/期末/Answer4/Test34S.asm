;************************************************************************
;请把下一行注释中的XXX、YYYYYY改成你的姓名和学号
;姓名:XXX, 学号:YYYYYY
;【循环分支程序设计】本题共20分
;已知数组A包含15个互不相等的整数，数组B包含20个互不相等的整数。
;试编制一程序，把即在A中又在B中出现的整数存放于数组C中。处理完毕
;显示'Processing Completed!'信息。
;要求源程序中包含完善的注释信息。做题时不要损坏题中原有的注释线。
;****************************（评分标准）********************************
;（1）有完善的注释信息2分；
;（2）变量定义正确2分；
;(3)算法正确,12分(其中，正确地写出双重循环6分，其它6分)；
;(4)指令无语法错误，能编译成EXE文件4分。
;************************************************************************
DATAS SEGMENT
    A DW 15 DUP(?)
    B DW 20 DUP(?)
;--------------------------所需变量定义于两横线之间------------------
	D DW 15 DUP(?)
	Completed	DB 'Processing Completed!',0dh,0ah,'$'
;------------------------------------------------------------------------
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
;初始化数组A和B（代码略）
;---------------------------程序代码写于两横线之间-------------------
	MOV CX,15
	MOV SI,0
	MOV BX,0
Next:
	PUSH CX
	MOV AX,A[SI]
	MOV CX,20
	MOV DI,0
Again:
	CMP AX,B[DI]
	JNE Continue
	MOV D[BX],AX
	ADD	BX,2
	JMP Break
Continue:
	ADD DI,2
	LOOP Again
Break:	
	ADD SI,2
	POP CX
	LOOP Next 
;------------------------------------------------------------------------
;其它处理（代码略）
	MOV AH,9
	MOV DX,OFFSET Completed
	INT 21H
    MOV AX,4C00H
    INT 21H
CODES ENDS
    END START
    