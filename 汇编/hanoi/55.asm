DATAS SEGMENT
    ;�˴��������ݶδ���
    tower db 'A', 'B', 'C'
    disks db 3                ; ��ŵ����������
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
             ASSUME CS:CODES,DS:DATAS,SS:STACKS
    START:   
             MOV    AX,DATAS
             MOV    DS,AX
    ;�˴��������δ���
             mov    ax, 0                          ; ��ʼ�ƶ������ӱ��
             mov    bx, 1                          ; Ŀ���ƶ������ӱ��
             mov    cx, 2                          ; �м丨�������ӱ��
            
             mov    dx, 3                      ; ��������
             call   hanoi                          ; ���õݹ麯��

    ; �������
             int    20h

    hanoi:   
             push   ax
             push   bx
             push   cx
             push   dx

    ; ���������Ϊ1��ֱ���ƶ�
             cmp    dx, 1
             je     moveDisk

    ; �ݹ���ã��������n-1�����Ӵ�A�ƶ���C��ʹ��B��Ϊ����
             mov    ax, dx
             dec    ax
             push   ax
             call   hanoi

    ; �ƶ����µ�����
    moveDisk:
             pop    dx
             mov    ah, 2                          ; ����ַ���ϵͳ����
             mov    dl, [tower + bx]
             int    21h

             mov    ah, 2
             mov    dl, '>'
             int    21h

             mov    ah, 2
             mov    dl, [tower + AX]
             int    21h

             mov    ah, 2
             mov    dl, ' '
             int    21h

    ; �ݹ���ã��������n-1�����Ӵ�C�ƶ���B��ʹ��A��Ϊ����
             mov    ax, dx
             dec    ax
             push   ax
             call   hanoi

             pop    dx
             pop    cx
             pop    bx
             pop    ax
             ret

             MOV    AH,4CH
             INT    21H
CODES ENDS
    END START

