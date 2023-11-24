CODES SEGMENT
    ASSUME CS:CODES,DS:CODES
    INPUT_MSG	DB 'INPUT A NUMBER:$'
    OUTPUT_MSG	DB '!=$'
    ERR_MSG		DB '!>65535$'
START:
	;ʹDSָ������
    PUSH CS
    POP DS
    
    ;��ʾ������ʾ��Ϣ
    MOV AH,9
    LEA DX,INPUT_MSG
    INT 21H
    
    ;����һ��ʮ��������CX��
    CALL DECBIN
    
    ;��AX��ʮ������ʽ��ʾ
    MOV AX,CX
    CALL DISP
    
    ;����(CX)!,������������65535,
    			;���������AX��,��CF=0
    			;����,��CF=1
    CALL FACT
    JC S1
    
    ;��ʾ�����ʾ��Ϣ
	PUSH AX
    MOV AH,9
    LEA DX,OUTPUT_MSG
    INT 21H
    POP AX
    
    ;��AX�е�����ʮ���Ƶķ�ʽ��ʾ����ʾ����
    CALL DISP
    JMP S2
    
    ;���̫��,��ʾ������Ϣ
S1: MOV AH,9
    LEA DX,ERR_MSG
    INT 21H

    
S2: MOV AH,4CH
    INT 21H
    
    
;ʮ�����ӳ���,�����CX��
DECBIN	PROC
	PUSH AX
	PUSH BX
	PUSH DX
	XOR CX,CX
D0:	MOV AH,1
	INT 21H
	CMP AL,'0'
	JB D1
	CMP AL,'9'
	JA D1
	SUB AL,30H
	MOV AH,0
	XCHG AX,CX
	MOV BX,10
	MUL BX
	XCHG AX,CX
	ADD CX,AX
	JMP D0
D1:
	POP DX
	POP BX
	POP AX
	RET
DECBIN	ENDP

;����(CX)!�ݹ��ӳ���,�����AX��,�������65535ʱ�ý�λ����
FACT	PROC
	PUSH DX
	CMP CX,1	;0��1�Ľ׳˾�Ϊ1,ֱ�Ӹ����,�������
	JA F1
	MOV AX,1
	CLC
	JMP F2
	
F1:	
	PUSH CX
	DEC CX		;�ݹ����(CX-1)!,�����AX��
	CALL FACT
	POP CX
	JC F2
	MUL CX		;����(CX)*(CX-1)!
				;�������65535ʱCF=1,����CF=0
	
F2:	
	POP DX
	RET
FACT	ENDP

;����ʮ�ݹ��ӳ���,��AX�е�����ʮ���Ƶķ�ʽ��ʾ����ʾ����
DISP	PROC
	PUSH AX
	PUSH CX
	PUSH DX
	XOR DX,DX   ;��DX����,���ڴ洢����.
	MOV CX,10  ;��CX�Ĵ�����ֵ����Ϊ10,���ڽ��г�������.
	DIV CX  ;ʹ��DIVָ�AX�е�ֵ����CX,�̴���AX,��������DX.
	
	CMP AX,0 ;�Ƚ����Ƿ�Ϊ��
	JZ D1
	CALL DISP	;�����λ��λ0,��ݹ���ʾ��λ����

D1:
	ADD DL,30H
	MOV AH,2
	INT 21H
	POP DX
	POP CX
	POP AX
	RET
DISP	ENDP

;����ʮ�ǵݹ��ӳ���,��AX�е�����ʮ���Ƶķ�ʽ��ʾ����ʾ����
STRING	DB 5 DUP(?),'$'
DISP1	PROC
	PUSH AX
	PUSH CX
	PUSH DX
	PUSH SI
	
	;��AX�еĶ�������ת��Ϊʮ�����ַ�������STRING
	LEA SI,STRING+5	;ʹSIΪSTRING�ַ���������$�ĵ�ַ
	MOV CX,10
L0:	
	XOR DX,DX
	DIV CX			;(DX:AX)/10,����AX��,������DX��
	ADD DL,30H
	DEC SI
	MOV [SI],DL
	CMP AX,0
	JNZ L0
	
	;��ʾת��Ϊʮ���Ƶ��ַ���
	MOV AH,9
	MOV DX,SI
	INT 21H
	
	POP SI
	POP DX
	POP CX
	POP AX
	RET
DISP1	ENDP

CODES ENDS
    END START




