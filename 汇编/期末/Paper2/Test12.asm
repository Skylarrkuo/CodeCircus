;************************************************************************
;�����һ��ע���е�XXX��YYYYYY�ĳ����������ѧ��
;����:XXX, ѧ��:YYYYYY
;����������⡿ÿ��4�֣���20��
;���³�����ɵĹ�����: �Ӽ����������ɸ������100D��ʮ���������ַ���
;����س�����ֹͣ���롣���������������ַ�����0->7��1->5��2->9 
;3->1��4->3��5->6��6->8��7->0��8->2��9->4�Ķ�Ӧ��ϵ���м��ܣ�����������
;�����ַ����򲻼��ܡ���������ڴ����BUFFER��
;Ҫ��ȫԴ������ȱ�ٵ�ָ�
;ע��:ÿ��ֻ����дһ��ָ���дָ��ʱ��Ҫ�ƻ���ע�е����ʾ���ߡ�
;************************************************************************
DATAS SEGMENT
    XCode DB '7591368024'
    Buffer DB 101 DUP(?) ;��һ���ֽ�Ϊ���ĵĳ���
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
    INT 21H ;��ʾ��ʾ��Ϣ 1   
    MOV CL,0 ;�����ַ�����
    ;_____________________________
Next:;ѭ����������
	MOV AH,1
	INT 21H
	CMP AL, 0dh
	;______________________________
	CMP AL,'0' ;�ж��Ƿ��������ַ�
	JB Continue
	CMP AL,'9'
	JA Continue ;������ǣ��򲻼���
	;______________________________
	MOV BX, OFFSET XCode ;������ַ	
	XLAT XCode ;���ת��(������)
Continue:
	MOV Buffer[SI],AL
	INC CL
	INC SI
	;______________________________
Display	:
    MOV Buffer[0],CL ;����������ַ�����
    AND CX,00FFH 
    MOV SI,1
    MOV AH,9
    MOV DX, OFFSET Prompt1
    INT 21H ;��ʾ��ʾ��Ϣ 2
Again: ;ѭ����ʾ����
	MOV AH,2
	MOV DL,Buffer[SI]
	INT 21H
	INC SI
	;______________________________
	MOV AH,2
	MOV DL,0ah
	INT 21H  ;��ʾ����
	MOV DL,0ah
	INT 21H  ;��ʾ�س�
    MOV AX,4C00H
    INT 21H
CODES ENDS
    END START