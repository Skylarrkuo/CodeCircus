;************************************************************************
;请把下一行注释中的XXX、YYYYYY改成你的姓名和学号
;姓名:XXX, 学号:YYYYYY
;【程序填空题】每空4分，共20分
;以下程序完成的功能是: 从键盘输入若干个（最多100D）十进制数字字符，
;输入回车符则停止输入。如果输入的是数字字符，则按0->7、1->5、2->9 
;3->1、4->3、5->6、6->8、7->0、8->2、9->4的对应关系进行加密；如果输入的是
;其它字符，则不加密。结果存入内存变量BUFFER。
;要求补全源程序中缺少的指令。
;注意:每空只能填写一条指令；填写指令时不要破坏备注中的填空示意线。
;************************************************************************
DATAS SEGMENT
    XCode DB '7591368024'
    Buffer DB 101 DUP(?) ;第一个字节为密文的长度
    Prompt1 DB 'Please enter a string of digits',0dh,0ah,'$'
    Prompt2 DB 0dh,0ah,'The ciphertext is :',0dh,0ah,'$'   
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
    MOV AH,9
    MOV DX, OFFSET Prompt1
    INT 21H ;显示提示信息 1   
    MOV CL,0 ;密文字符个数
    ;_____________________________
Next:;循环输入明文
	MOV AH,1
	INT 21H
	CMP AL, 0dh
	;______________________________
	CMP AL,'0' ;判断是否是数字字符
	JB Continue
	CMP AL,'9'
	JA Continue ;如果不是，则不加密
	;______________________________
	MOV BX, OFFSET XCode ;换码表地址	
	XLAT XCode ;查表转换(即加密)
Continue:
	MOV Buffer[SI],AL
	INC CL
	INC SI
	;______________________________
Display	:
    MOV Buffer[0],CL ;保存输入的字符个数
    AND CX,00FFH 
    MOV SI,1
    MOV AH,9
    MOV DX, OFFSET Prompt1
    INT 21H ;显示提示信息 2
Again: ;循环显示密文
	MOV AH,2
	MOV DL,Buffer[SI]
	INT 21H
	INC SI
	;______________________________
	MOV AH,2
	MOV DL,0ah
	INT 21H  ;显示换行
	MOV DL,0ah
	INT 21H  ;显示回车
    MOV AX,4C00H
    INT 21H
CODES ENDS
    END START