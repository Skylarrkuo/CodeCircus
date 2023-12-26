;************************************************************************
;请把下一行注释中的XXX、YYYYYY改成你的姓名和学号
;姓名:XXX, 学号:YYYYYY
;【程序填空题】每空4分，共20分
;以下程序完成的功能是: 先利用1号DOS功能调用输入一个字符串，然后
;再利用0AH号功能输入一个字符串，最后比较两个字符串是否相等(如果
;串1与串2左部相等就认为两串相等)。如果相等显示‘Yes’，否则显示‘No’。
;要求补全源程序中缺少的指令。
;注意:每空只能填写一条指令；填写指令时不要破坏备注中的填空示意线。
;************************************************************************
DATAS SEGMENT
	;以下两数组中，首字节为串的总字节数，次字节为串中实际字符数
	;串的内容从第3个字节开始存放		
	String1   db 100, ?, 100 dup(?)
	String2   db 100, ?, 100 dup(?)
	DisplayYes        db 0dh,0ah, 'Yes', 0dh, 0ah, '$'
	DisplayNo         db 0dh,0ah, 'No', 0dh, 0ah, '$'
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
    
	;循环用1号DOS功能调用输入字符串存于String1
	MOV SI, 2
Next: 
	MOV AH, 1
    INT 21H
	CMP AL, 0dh
	;__________________
	MOV String1[SI], AL
	;______________________
	;______________________
	
InputOver: 
	MOV AX,SI
	SUB AX,2
	MOV String1[1], AL ;保存输入字符个数
	;用0aH号DOS功能调用输入字符串存于String2
	MOV AH, 0aH
	LEA DX, String2
	INT 21H
	
;比较两字符串
	MOV  CL, String1[1] 
	AND  CX, 00FFH
	MOV  SI, 2
NextCMP:
	MOV AL,String1[SI]
	CMP AL,String2[SI] 
	JNE NoEqual  ;如果字符不相等，则转显示'No'信息
	;_______________________
	LOOP NextCMP
	MOV AH,9     
	LEA DX, DisplayYes
	INT 21H   ;显示'Yes'信息
	;______________________
NoEqual:
	MOV AH,9
	LEA DX, DisplayNo
	INT 21H ;显示'No'信息
CompOver:
    MOV AX,4C00H
    INT 21H
CODES ENDS
    END START