;************************************************************************
;�����һ��ע���е�XXX��YYYYYY�ĳ����������ѧ��
;����:XXX, ѧ��:YYYYYY
;���ۺ�Ӧ�ó�����ơ����⹲40��
;��д���򣬴Ӽ�������һ��ʮ����������0-65535����Ȼ�������ʮ������
;��ʽ��ʾ����������������Ҫ��:
;��1������ʹ���ӳ���ṹ��
;��2��Ҫ���������ʱ���Ѻõ���ʾ��Ϣ;
;��3��Ҫ��Դ�����а������Ƶ�ע����Ϣ��
;ע�⣺����ʱ��Ҫ������ԭ�е�ע���ߡ�
;******************************���ֱ�׼*********************************
;��1�������Ƶ�ע����Ϣ(�ر����ӳ�����ڲ���˵��) 6��
;��2�����Ѻõ���ʾ��Ϣ 4��
;��3��������������� 4��
;��4����������ӳ���ṹ������ȷ6�֣����У�������2�֣�ÿ���ӳ���2�֣�
;��5�������ӳ����㷨��ȷ 7�֣�����ѭ���ṹ��ȷ4��,����3�֣�
;��6����ʾ�ӳ����㷨��ȷ 7�֣�����ѭ���ṹ��ȷ4��,����3�֣�
;��7��ָ����д��ȷ���ܱ����EXE�ļ���ִ��ʱ������ 6��
;************************************************************************
DATAS SEGMENT
	Prompt1 DB 'Please Enter 1 Number(0-65535): $';������10����
	Prompt2 DB 0dh,0ah,'Its Hexadecimal Representation is: $'
	ErrMsg  DB 0dh,0ah,'Overflow error for data! Try Again: $' ;�����������
;-------------------------�������������������֮��-------------------
	HexCode  DB '0123456789ABCDEF' ;ʮ������ת����
;------------------------------------------------------------------------
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
;--------------------------�������д��������֮��---------------------
;������
Main PROC Far
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
    MOV AH,9
    MOV DX, OFFSET Prompt1
    INT 21H       ;��ʾ��ʾ��Ϣ
    CALL GetDecimal ;����1��������BX
    MOV AH,9
    MOV DX, OFFSET Prompt2
    INT 21H       ;��ʾ��ʾ��Ϣ
    CALL DisplayHex ;��ʾBX�е���
    MOV AH, 2
    MOV DL, 0dh
    INT 21H
    MOV DL,0ah
    INT 21H
	MOV AX, 4c00h
	INT 21H
Main ENDP
;.......................................................................
;�ӳ��� ��BX�ж���������ʮ��������ʽ��ʾ����Ļ
DisplayHex PROC Near
	MOV CX, 4    ;����ѭ������
AGAIN:
    PUSH CX       ;����ѭ������
	MOV CL, 4     ;��ѭ����λ����
	ROL BX, CL
	PUSH BX       ;����BX��ֵ
	MOV AL, BL
	AND AL, 0FH
	MOV BX, OFFSET HexCode
	XLAT           ;ת����16��������
	MOV DL,AL
	MOV AH,02
	INT 21H        ;��ʾ������
	POP BX         ;�ָ�BX��ֵ
	POP CX         ;�ָ�CX��ֵ
	LOOP AGAIN
	RET
DisplayHex ENDP
;.......................................................................
;�ӳ��򣺴Ӽ�������һ��ʮ��������ת���ɶ�����������BX
GetDecimal PROC Near
Again:
	MOV BX, 0
NextChar:
	MOV AH, 1      ;����1�ַ�
	INT 21H           ;�ַ�ASCII��AL 
	CMP  AL, '0'
	JB Return    ;�������
	CMP  AL, '9'
	JA Return    ;�������
	PUSH AX         ; ������ַ��ݴ��ջ
	MOV AX, BX 
	MOV BX, 10
	MUL BX           ;����(DX,AX)��
	POP BX            ;�ָ�������ַ���BL
	AND BX,000FH; �����ַ�ת����
	ADD AX, BX 
	ADC DX, 0 
	CMP DX, 0
	JA NumOver    ;�����ת��ʾ����
	MOV BX, AX    ;�������������BX
	JMP NextChar
NumOver:
	MOV AH,9
	MOV DX,OFFSET ErrMsg
	INT 21H       ;��ʾ���������Ϣ
	JMP Again
Return:
	RET
GetDecimal ENDP
;-------------------------------------------------------------------------- 
CODES ENDS
    END Main