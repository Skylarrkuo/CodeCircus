;************************************************************************
;请把下一行注释中的XXX、YYYYYY改成你的姓名和学号
;姓名:XXX, 学号:YYYYYY
;【循环分支程序设计】本题共20分
;试编写一程序，求出首地址为DATA的100D字数组中的最小偶数，并把它
;存放在变量MINEVEN中,处理完毕显示'Processing Completed!'信息。（假设
;偶数肯定存在）
;要求源程序中包含完善的注释信息。做题时不要损坏题中原有的注释线。
;************************************************************************
DATAS SEGMENT
    DATA	DW 100 DUP(?)
;------------------------所需变量定义于两横线之间--------------------

;所需变量定义于此(做题时删除此行)

;------------------------------------------------------------------------ 
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
    ;输入100个数存于字数组DATA（代码略）
;-------------------------程序代码写于两横线之间---------------------

;程序代码写于此(做题时删除此行)

;------------------------------------------------------------------------
	MOV AH,9
	MOV DX,OFFSET Completed
	INT 21H  ;显示'Processing Completed!'
	;显示最小的偶数（代码略）
    MOV AX,4C00H
    INT 21H
CODES ENDS
    END START