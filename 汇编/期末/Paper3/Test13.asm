;************************************************************************
;�����һ��ע���е�XXX��YYYYYY�ĳ����������ѧ��
;����:XXX, ѧ��:YYYYYY
;����������⡿ÿ��4�֣���20��
;���³�����ɵĹ�����: �Ӽ���������һ�������ַ���1��2��3��������ǡ�1����
;����ʾ�ַ�R;����ǡ�2��������ʾ�ַ�G������ǡ�3��������ʾ�ַ�B�����������
;Ҫ��ȫԴ������ȱ�ٵ�ָ�
;ע��:ÿ��ֻ����дһ��ָ���дָ��ʱ��Ҫ�ƻ���ע�е����ʾ���ߡ�
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
    INT 21H        ;��ʾ��ʾ��Ϣ
    mov ah,1
	int 21h        ;�Ӽ�������һ���ַ�
	cmp al,'1'
	je LR          ;������ڡ�1��, ��ת����LR
	cmp al,'2'
	je LG          ;������ڡ�2��, ��ת����LG
	cmp al,'3' 
	je LB          ;������ڡ�3��, ��ת����LB
	jmp ENDL        ;����ת��������
LR:	
	;_____________________
	JMP Load
LG:	
	;_____________________
	JMP Load
LB:	
	;_____________________
Load:
	CALL BX  ; ����BXָ��Ĺ���
ENDL:
	MOV AH,9
	MOV DX, OFFSET OK
	INT 21h
	MOV ax,4c00h
	INT 21H ;����DOS
	
PR:	mov ah,2
	mov dl,'R'
	int 21h ;��ʾ�ַ�R
	ret
PG:	mov ah,2
	mov dl,'G'
	int 21h ;��ʾ�ַ�R
	;___________________
PB: 
	mov ah,2
	mov dl,'B'
	int 21h ;��ʾ�ַ�R
	ret		
CODES ENDS
    END START