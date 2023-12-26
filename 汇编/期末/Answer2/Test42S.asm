;************************************************************************
;请把下一行注释中的XXX、YYYYYY改成你的姓名和学号
;姓名:XXX, 学号:YYYYYY
;【综合应用程序设计】本题共40分
;编写一程序，从键盘输入一系列字符(以回车符结束)，并按字母、数字及其
;他字符分类计数，最后以十进制形式显示出这三类的计数结果。并满足下列要求:
;（1）必须使用子程序结构；
;（2）要求程序运行时有友好的提示信息;
;（3）要求源程序中包含完善的注释信息。
;注意：做题时不要损坏题中原有的注释线。
;******************************评分标准*********************************
;（1）有完善的注释信息 4分
;（2）有友好的提示信息 6分
;（3）定义了所需变量 4分
;（4）主程序和子程序结构定义正确6分（其中，主程序2分，每子程序2分）
;（5）主程序算法正确 7分（其中循环结构正确4分，其它3分）
;（6）子程序算法正确 7分（其中循环结构正确4分，其它3分）
;（7）指令书写正确，能编译成EXE文件且执行时不死机 6分
;************************************************************************
DATAS SEGMENT
	LettNumber    DB  0dh,0ah,'Number of letters is :$'
	DigiNumber    DB  0dh,0ah,'Number of digits is :$'
	OtherNumber   DB  0dh,0ah,'Number of other characters is :$'
	PromptMsg	  DB 'Plase Enter a String:',0dh,0ah,'$'
;-------------------------所需变量定义于两横线之间-------------------
	DECIMAL DB 6 DUP (?),'$'    ;保存十进制数码    
;------------------------------------------------------------------------
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
;--------------------------程序代码写于两横线之间---------------------
;主程序
Main   PROC  Far
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
        
	MOV AH,9
	MOV DX, OFFSET PromptMsg 
	INT 21H ;显示提示信息
	   
;循环从键盘输入字符，边输入边统计，直至遇到回车符(0dH)时循环结束
	MOV BX,0  ;数字个数
	MOV CX,0  ;字母个数
	MOV DX,0  ; 其他字符个数
NextEnter:	
    MOV AH, 1
	INT 21H
	CMP AL, 0dh  ;是回车符否?
	JE Display      ;跳出循环，显示结果
	CMP AL, '0'   ; ASCII比’0’小 ?
	jB OtherChar    ;是，则转其他字符
	CMP AL,'9' ;    ACII比’9’大?
	JA UpperCase  ;是，则转大写字母
	INC BX               ;数字个数加1
	JMP NextEnter  ;继续循环
UpperCase:	
	CMP AL, 'A'   ; ASCII比’A’小 ?
	JB OtherChar   ;是，则转其他字符
	CMP AL, 'Z'  ; ASCII比’Z’大 ?
	JA LowerCase   ;是，则转小写字母
	INC  CX  ;字母个数加1
	JMP NextEnter  ;继续循环
LowerCase:
	CMP AL, 'a'  ; ASCII比’a’小 ?
	JB OtherChar  ;是，则转其他字符
	CMP AL, 'z'  ; ASCII比’z’大 ?
	JA OtherChar  ;是，则转其他字符
	INC  CX  ;字母个数加1
	JMP NextEnter  ;继续循环
OtherChar:
	INC DX   ;其他字符加1
	JMP NextEnter ; 继续循环
	
;显示三类统计结果…… 	
Display:   
	PUSH DX ;保护其他字符个数
	PUSH CX ;保护字母个数
	
	MOV AH,9
	LEA DX,DigiNumber
	INT 21H
	;把BX值（即数字个数）以十进制形式显示于屏幕
	CALL DIsplayDec
	
	POP BX
	MOV AH,9
	LEA DX,LettNumber
	INT 21H	
	;把BX值（即字母个数）以十进制形式显示于屏幕
	CALL DIsplayDec

	POP BX
	MOV AH,9
	LEA DX,OtherNumber
	INT 21H		
    ;把BX值（即其他字符个数）以十进制形式显示于屏幕
    CALL DIsplayDec

	MOV AH,2
	MOV DL,0dh ;换行
	INT 21H
	MOV DL,0ah ;回车
	INT 21H

    MOV AX,4C00H
    INT 21H
Main   ENDP
;........................................................................
;以十进制形式显示BX中数的子程序
;不保护寄存器的值
;........................................................................
DisplayDec  PROC  Near
	MOV CX, 6
	MOV AL, 20H
	LEA DI,DECIMAL
	REP STOSB 
	MOV DI, 5   ;余数存储初始位
	MOV AX, BX  ;因为被除数必须放在AX中
NextDig:
	MOV DX, 0
	MOV BX,10
	DIV BX    ;(DX,AX)/10, 余DX、商AX
	OR DL, 30H  ;转换成ASCII字符
	MOV DECIMAL[DI], DL
	DEC DI
	CMP AX,0
	JNZ NextDig
	MOV AH, 9    ;显示转换后的结果
	LEA DX, DECIMAL
	INT 21H
	RET
DisplayDec	ENDP
;------------------------------------------------------------------------- 
CODES ENDS
    END Main