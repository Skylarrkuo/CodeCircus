;************************************************************************
;�����һ��ע���е�XXX��YYYYYY�ĳ����������ѧ��
;����:XXX, ѧ��:YYYYYY
;����������⡿ÿ��4�֣���20��
;���³�����ɵĹ�����: �Ӽ�������һ���Իس����������ַ�����Ȼ��
;��ĸ�����ּ������ַ��������, ���ѽ�����α����ڱ���Latter�� 
;Figure��Other�ֱ����С����������ʾ'Processing Completed!'��Ϣ��
;Ҫ��ȫԴ������ȱ�ٵ�ָ�
;ע��:ÿ��ֻ����дһ��ָ���дָ��ʱ��Ҫ�ƻ���ע�е����ʾ���ߡ�
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
	JE Exit     ;���ڻس����������
	CMP AL,'0'  ;�ж��Ƿ��������ַ�
	;_____________________
	CMP AL,'9'
	JA NoFigure
	INC Figure  ;��,�������ַ���������1
	JMP Next
NoFigure:
	CMP AL,'A'  ;�ж��Ƿ��Ǵ�д��ĸ
	JB OtherChar
	;_____________________
	JA NoUpperCase
	INC Latter  ;�ǣ�����ĸ������1	
	;_____________________
NoUpperCase:
	CMP AL,'a'  ;�ж��Ƿ���Сд��ĸ
	JB OtherChar
	CMP AL,'z'
	JA OtherChar
	INC Latter  ;�ǣ�����ĸ������1	
	JMP Next	
OtherChar:
	INC Other ;�����ַ�������1
	;_____________________	
Exit:
;�������������ԣ�
	MOV AH,9
	MOV DX,OFFSET Completed
	INT 21H  
    MOV AX,4C00H
    INT 21H
CODES ENDS
    END START