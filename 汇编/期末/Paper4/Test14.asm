;************************************************************************
;�����һ��ע���е�XXX��YYYYYY�ĳ����������ѧ��
;����:XXX, ѧ��:YYYYYY
;����������⡿ÿ��4�֣���20��
;���³�����ɵĹ�����: ������1��DOS���ܵ�������һ���ַ�����Ȼ��
;������0AH�Ź�������һ���ַ��������Ƚ������ַ����Ƿ����(���
;��1�봮2����Ⱦ���Ϊ�������)����������ʾ��Yes����������ʾ��No����
;Ҫ��ȫԴ������ȱ�ٵ�ָ�
;ע��:ÿ��ֻ����дһ��ָ���дָ��ʱ��Ҫ�ƻ���ע�е����ʾ���ߡ�
;************************************************************************
DATAS SEGMENT
	;�����������У����ֽ�Ϊ�������ֽ��������ֽ�Ϊ����ʵ���ַ���
	;�������ݴӵ�3���ֽڿ�ʼ���		
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
    
	;ѭ����1��DOS���ܵ��������ַ�������String1
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
	MOV String1[1], AL ;���������ַ�����
	;��0aH��DOS���ܵ��������ַ�������String2
	MOV AH, 0aH
	LEA DX, String2
	INT 21H
	
;�Ƚ����ַ���
	MOV  CL, String1[1] 
	AND  CX, 00FFH
	MOV  SI, 2
NextCMP:
	MOV AL,String1[SI]
	CMP AL,String2[SI] 
	JNE NoEqual  ;����ַ�����ȣ���ת��ʾ'No'��Ϣ
	;_______________________
	LOOP NextCMP
	MOV AH,9     
	LEA DX, DisplayYes
	INT 21H   ;��ʾ'Yes'��Ϣ
	;______________________
NoEqual:
	MOV AH,9
	LEA DX, DisplayNo
	INT 21H ;��ʾ'No'��Ϣ
CompOver:
    MOV AX,4C00H
    INT 21H
CODES ENDS
    END START