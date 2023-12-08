DATAS SEGMENT
    ; �˴��������ݶδ���
    DISK_COUNT DB 3          ; ��ŵ������������
    SOURCE_TOWER DB 'A'      ; ��ʼ��
    TARGET_TOWER DB 'C'      ; Ŀ����
    AUX_TOWER DB 'B'         ; ������
    MSG_MOVE DB 'Move disk from ', 0
DATAS ENDS

STACKS SEGMENT STACK
    DW 100H DUP (?)  ; ����ջ�δ�С
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATAS, SS:STACKS
START:
    MOV AX, DATAS
    MOV DS, AX

    ; ��ʼ��
    MOV CX, OFFSET DISK_COUNT
    MOV SI, OFFSET SOURCE_TOWER
    MOV DI, OFFSET TARGET_TOWER
    MOV BX, OFFSET AUX_TOWER

    ; ���õݹ����
    CALL HANOI

    ; �������
    MOV AH, 4CH
    INT 21H

HANOI PROC
    ; ������CX = ���������� SI = ��ʼ���� DI = Ŀ������ BX = ������

    CMP CX, 1      ; ���ֻ��һ�����ӣ�ֱ���ƶ�
    JE  MOVE_DISK

    ; �����Ƚ������ CX-1 �����Ӵ���ʼ���ƶ���������
    MOV DX, CX
    DEC DX
    PUSH DX       ; ���� CX-1

    PUSH BX       ; ��������ΪĿ����
    PUSH DI       ; Ŀ������Ϊ������
    POP DI
    POP BX
    MOV DX, CX
    DEC DX
    PUSH DX
    CALL HANOI    ; �ݹ����

    ; Ȼ���ƶ�����µ����ӵ�Ŀ����
    POP DX        ; �ָ� CX-1
    POP DI        ; �ָ�Ŀ����
    POP BX        ; �ָ�������
    MOV CX, 1
    CALL HANOI    ; �ƶ�����

    ; ��󣬽��������ϵ� CX-1 �������ƶ���Ŀ����
    POP DX        ; �ָ� CX-1
    PUSH SI       ; ��ʼ����Ϊ������
    PUSH BX       ; ��������Ϊ��ʼ��
    POP SI
    POP BX
    MOV CX, DX
    CALL HANOI    ; �ݹ����

    RET

MOVE_DISK:
    ; �ƶ����ӵĹ���
    MOV AH, 09H
    LEA DX, MSG_MOVE
    INT 21H

    MOV DL, [SI]
    INT 21H

    MOV AH, 09H
    MOV DL, ' '    ; ���һ���ո�
    INT 21H

    MOV AH, 09H
    LEA DX, TARGET_TOWER
    INT 21H

    MOV DL, [DI]
    INT 21H

    MOV AH, 09H
    INT 21H

    MOV AH, 09H
    MOV DL, 0AH    ; ����
    INT 21H

    RET
HANOI ENDP

CODES ENDS
    END START

