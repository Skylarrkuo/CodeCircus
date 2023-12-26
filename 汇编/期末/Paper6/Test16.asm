;************************************************************************
;请把下一行注释中的XXX、YYYYYY改成你的姓名和学号
;姓名:XXX, 学号:YYYYYY
;【程序填空题】每空4分，共20分
;以下程序完成的功能是: 从键盘输入一个以回车符结束的字符串，然后按
;字母、数字及其它字符分类计数, 并把结果依次保存于变量Latter、 
;Figure和Other字变量中。处理完毕显示'Processing Completed!'信息。
;要求补全源程序中缺少的指令。
;注意:每空只能填写一条指令；填写指令时不要破坏备注中的填空示意线。
;************************************************************************
DATAS SEGMENT		
	Completed	DB 'Processing Completed!',0dh,0ah,'$'
	Latter	DW ?
	Figure	DW ?
	Other	DW ?
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
	MOV	Latter,0
	;____________________
	MOV Other,0
Next:
	MOV AH,1
	INT 21H
	CMP AL,0dh
	JE Exit     ;等于回车符，则结束
	CMP AL,'0'  ;判断是否是数字字符
	;_____________________
	CMP AL,'9'
	JA NoFigure
	INC Figure  ;是,则数字字符计数器加1
	JMP Next
NoFigure:
	CMP AL,'A'  ;判断是否是大写字母
	JB OtherChar
	;_____________________
	JA NoUpperCase
	INC Latter  ;是，则字母个数加1	
	;_____________________
NoUpperCase:
	CMP AL,'a'  ;判断是否是小写字母
	JB OtherChar
	CMP AL,'z'
	JA OtherChar
	INC Latter  ;是，则字母个数加1	
	JMP Next	
OtherChar:
	INC Other ;其它字符个数加1
	;_____________________	
Exit:
;其它处理（代码略）
	MOV AH,9
	MOV DX,OFFSET Completed
	INT 21H  
    MOV AX,4C00H
    INT 21H
CODES ENDS
    END START