;************************************************************************
;�����һ��ע���е�XXX��YYYYYY�ĳ����������ѧ��
;����:XXX, ѧ��:YYYYYY
;���ۺ�Ӧ�ó�����ơ����⹲40��
;��дһ���򣬴Ӽ�������һϵ���ַ�(�Իس�������)��������ĸ�����ּ���
;���ַ���������������ʮ������ʽ��ʾ��������ļ������������������Ҫ��:
;��1������ʹ���ӳ���ṹ��
;��2��Ҫ���������ʱ���Ѻõ���ʾ��Ϣ;
;��3��Ҫ��Դ�����а������Ƶ�ע����Ϣ��
;ע�⣺����ʱ��Ҫ������ԭ�е�ע���ߡ�
;******************************���ֱ�׼*********************************
;��1�������Ƶ�ע����Ϣ 4��
;��2�����Ѻõ���ʾ��Ϣ 6��
;��3��������������� 4��
;��4����������ӳ���ṹ������ȷ6�֣����У�������2�֣�ÿ�ӳ���2�֣�
;��5���������㷨��ȷ 7�֣�����ѭ���ṹ��ȷ4�֣�����3�֣�
;��6���ӳ����㷨��ȷ 7�֣�����ѭ���ṹ��ȷ4�֣�����3�֣�
;��7��ָ����д��ȷ���ܱ����EXE�ļ���ִ��ʱ������ 6��
;************************************************************************
DATAS SEGMENT
	LettNumber    DB  0dh,0ah,'Number of letters is :$'
	DigiNumber    DB  0dh,0ah,'Number of digits is :$'
	OtherNumber   DB  0dh,0ah,'Number of other characters is :$'
	PromptMsg	  DB 'Plase Enter a String:',0dh,0ah,'$'
;-------------------------�������������������֮��-------------------
	DECIMAL DB 6 DUP (?),'$'    ;����ʮ��������    
;------------------------------------------------------------------------
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
;--------------------------�������д��������֮��---------------------
;������
Main   PROC  Far
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
        
	MOV AH,9
	MOV DX, OFFSET PromptMsg 
	INT 21H ;��ʾ��ʾ��Ϣ
	   
;ѭ���Ӽ��������ַ����������ͳ�ƣ�ֱ�������س���(0dH)ʱѭ������
	MOV BX,0  ;���ָ���
	MOV CX,0  ;��ĸ����
	MOV DX,0  ; �����ַ�����
NextEnter:	
    MOV AH, 1
	INT 21H
	CMP AL, 0dh  ;�ǻس�����?
	JE Display      ;����ѭ������ʾ���
	CMP AL, '0'   ; ASCII�ȡ�0��С ?
	jB OtherChar    ;�ǣ���ת�����ַ�
	CMP AL,'9' ;    ACII�ȡ�9����?
	JA UpperCase  ;�ǣ���ת��д��ĸ
	INC BX               ;���ָ�����1
	JMP NextEnter  ;����ѭ��
UpperCase:	
	CMP AL, 'A'   ; ASCII�ȡ�A��С ?
	JB OtherChar   ;�ǣ���ת�����ַ�
	CMP AL, 'Z'  ; ASCII�ȡ�Z���� ?
	JA LowerCase   ;�ǣ���תСд��ĸ
	INC  CX  ;��ĸ������1
	JMP NextEnter  ;����ѭ��
LowerCase:
	CMP AL, 'a'  ; ASCII�ȡ�a��С ?
	JB OtherChar  ;�ǣ���ת�����ַ�
	CMP AL, 'z'  ; ASCII�ȡ�z���� ?
	JA OtherChar  ;�ǣ���ת�����ַ�
	INC  CX  ;��ĸ������1
	JMP NextEnter  ;����ѭ��
OtherChar:
	INC DX   ;�����ַ���1
	JMP NextEnter ; ����ѭ��
	
;��ʾ����ͳ�ƽ������ 	
Display:   
	PUSH DX ;���������ַ�����
	PUSH CX ;������ĸ����
	
	MOV AH,9
	LEA DX,DigiNumber
	INT 21H
	;��BXֵ�������ָ�������ʮ������ʽ��ʾ����Ļ
	CALL DIsplayDec
	
	POP BX
	MOV AH,9
	LEA DX,LettNumber
	INT 21H	
	;��BXֵ������ĸ��������ʮ������ʽ��ʾ����Ļ
	CALL DIsplayDec

	POP BX
	MOV AH,9
	LEA DX,OtherNumber
	INT 21H		
    ;��BXֵ���������ַ���������ʮ������ʽ��ʾ����Ļ
    CALL DIsplayDec

	MOV AH,2
	MOV DL,0dh ;����
	INT 21H
	MOV DL,0ah ;�س�
	INT 21H

    MOV AX,4C00H
    INT 21H
Main   ENDP
;........................................................................
;��ʮ������ʽ��ʾBX�������ӳ���
;�������Ĵ�����ֵ
;........................................................................
DisplayDec  PROC  Near
	MOV CX, 6
	MOV AL, 20H
	LEA DI,DECIMAL
	REP STOSB 
	MOV DI, 5   ;�����洢��ʼλ
	MOV AX, BX  ;��Ϊ�������������AX��
NextDig:
	MOV DX, 0
	MOV BX,10
	DIV BX    ;(DX,AX)/10, ��DX����AX
	OR DL, 30H  ;ת����ASCII�ַ�
	MOV DECIMAL[DI], DL
	DEC DI
	CMP AX,0
	JNZ NextDig
	MOV AH, 9    ;��ʾת����Ľ��
	LEA DX, DECIMAL
	INT 21H
	RET
DisplayDec	ENDP
;------------------------------------------------------------------------- 
CODES ENDS
    END Main