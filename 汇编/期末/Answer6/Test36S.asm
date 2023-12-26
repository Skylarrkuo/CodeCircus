;************************************************************************
;请把下一行注释中的XXX、YYYYYY改成你的姓名和学号
;姓名:XXX, 学号:YYYYYY
;【循环分支程序设计】本题共20分
;试编写一程序，比较两个以'$'结尾的字符串STRING1和STRING2所含字符是
;否相同(假设两个字符串的长度相等)。若相同则显示'MATCH'，若不相同则
;显示'NO MATCH'。
;要求源程序中包含完善的注释信息。做题时不要损坏题中原有的注释线。
;************************（评分标准）************************************
;（1）有完善的注释信息2分；
;（2）变量定义正确2分；
;(3)算法正确12分(其中，循环结构正确6分，其它6分)；
;(4)指令无语法错误，能编译成EXE文件4分。
;************************************************************************
DATAS SEGMENT
    STRING1 DB 'abcdefghijklmnouqrstuvwxyz$'
    STRING2 DB 'abcdefghijklmnouqrstuvwxyz$'
;---------------------所需变量定义于两横线之间(参考答案)------------
	Msg_Match	DB 'MATCH',0dh,0ah,'$'      
	Msg_NoMatch	DB 'NO Match', 0dh,0ah,'$' 
;------------------------------------------------------------------------ 
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
;---------------------程序代码写于两横线之间(参考答案)---------------
	MOV SI,0
Next:
	MOV AL, STRING1[SI]
	CMP AL,'$'
	JE Match
	CMP AL, STRING2[SI]
	JNE NoMatch
	INC SI
	JMP Next
Match:
	MOV AH,9
	MOV DX,OFFSET Msg_Match
	INT 21H
	JMP Exit
NoMatch:
	MOV AH,9
	MOV DX,OFFSET Msg_NoMatch
	INT 21H		
Exit:
;------------------------------------------------------------------------------------- 
    MOV AX,4C00H
    INT 21H
CODES ENDS
    END START