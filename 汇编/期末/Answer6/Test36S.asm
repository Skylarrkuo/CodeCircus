;************************************************************************
;�����һ��ע���е�XXX��YYYYYY�ĳ����������ѧ��
;����:XXX, ѧ��:YYYYYY
;��ѭ����֧������ơ����⹲20��
;�Ա�дһ���򣬱Ƚ�������'$'��β���ַ���STRING1��STRING2�����ַ���
;����ͬ(���������ַ����ĳ������)������ͬ����ʾ'MATCH'��������ͬ��
;��ʾ'NO MATCH'��
;Ҫ��Դ�����а������Ƶ�ע����Ϣ������ʱ��Ҫ������ԭ�е�ע���ߡ�
;************************�����ֱ�׼��************************************
;��1�������Ƶ�ע����Ϣ2�֣�
;��2������������ȷ2�֣�
;(3)�㷨��ȷ12��(���У�ѭ���ṹ��ȷ6�֣�����6��)��
;(4)ָ�����﷨�����ܱ����EXE�ļ�4�֡�
;************************************************************************
DATAS SEGMENT
    STRING1 DB 'abcdefghijklmnouqrstuvwxyz$'
    STRING2 DB 'abcdefghijklmnouqrstuvwxyz$'
;---------------------�������������������֮��(�ο���)------------
	Msg_Match	DB 'MATCH',0dh,0ah,'$'      
	Msg_NoMatch	DB 'NO Match', 0dh,0ah,'$' 
;------------------------------------------------------------------------ 
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,ES:DATAS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV ES,AX
;---------------------�������д��������֮��(�ο���)---------------
	MOV SI,0
Next:
	MOV AL, STRING1[SI]
	CMP AL,'$'
	JE Match
	CMP AL, STRING2[SI]
	JNE NoMatch
	INC SI
	JMP Next
Match:
	MOV AH,9
	MOV DX,OFFSET Msg_Match
	INT 21H
	JMP Exit
NoMatch:
	MOV AH,9
	MOV DX,OFFSET Msg_NoMatch
	INT 21H		
Exit:
;------------------------------------------------------------------------------------- 
    MOV AX,4C00H
    INT 21H
CODES ENDS
    END START