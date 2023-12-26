;************************************************************************
;请把下一行注释中的XXX、YYYYYY改成你的姓名和学号
;姓名:XXX, 学号:YYYYYY
;【程序填空题】每空4分，共20分
;以下程序完成的功能是: 从键盘上输入一个数字字符（1，2或3）。如果是‘1’，
;则显示字符R;如果是‘2’，则显示字符G；如果是‘3’，则显示字符B；否则结束。
;要求补全源程序中缺少的指令。
;注意:每空只能填写一条指令；填写指令时不要破坏备注中的填空示意线。
;************************************************************************
DATAS SEGMENT
	Prompt DB 'Please Enter a digit(1,2 or 3) :$'
	Ok	DB 0dh,0ah,'OK',0dh,0ah,'$'
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
    ;___________________
    MOV DX,OFFSET Prompt
    INT 21H        ;显示提示信息
    mov ah,1
	int 21h        ;从键盘输入一个字符
	cmp al,'1'
	je LR          ;如果等于’1’, 则转移至LR
	cmp al,'2'
	je LG          ;如果等于’2’, 则转移至LG
	cmp al,'3' 
	je LB          ;如果等于’3’, 则转移至LB
	jmp ENDL        ;否则，转移至结束
LR:	
	;_____________________
	JMP Load
LG:	
	;_____________________
	JMP Load
LB:	
	;_____________________
Load:
	CALL BX  ; 调用BX指向的过程
ENDL:
	MOV AH,9
	MOV DX, OFFSET OK
	INT 21h
	MOV ax,4c00h
	INT 21H ;返回DOS
	
PR:	mov ah,2
	mov dl,'R'
	int 21h ;显示字符R
	ret
PG:	mov ah,2
	mov dl,'G'
	int 21h ;显示字符R
	;___________________
PB: 
	mov ah,2
	mov dl,'B'
	int 21h ;显示字符R
	ret		
CODES ENDS
    END START