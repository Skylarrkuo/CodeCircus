assume cs:code
data segment
    db 9,8,7,4,2,0  ; ��ʼ�����ݶΣ����BCD�������
data ends

code segment
start:
    ; �������ݶμĴ���
    mov bx, data
    mov ds, bx
    mov si, 0

    ; ������ʾ�������ĵ�ַ
    mov bx, 0b800h
    mov es, bx
    mov di, 160 * 12 + 30 * 2  ; ����Ļ��ѡ��һ��λ����ʾ���ں�ʱ��

    ; ѭ����ʾ����ʱ��
    mov cx, 6  ; ����ʱ���ܹ���6������
s0:
    push cx  ; ����ѭ��������
    mov al, ds:[si]  ; ��BCD�����м���һ������
    push ax  ; ��������

    inc si  ; �ƶ�����һ������

    ; ��CMOS��ȡʱ��
    out 70h, al
    in al, 71h

    ; ����BCD��ת��ΪASCII��
    mov ah, al
    mov cl, 4
    shr ah, cl
    and al, 00001111b

    add ah, 30h
    add al, 30h

    ; ��ʾ��/��/�� ʱ:��:��
    mov byte ptr es:[di], ah
    add di, 2
    mov byte ptr es:[di], al
    add di, 2

    pop ax  ; �ָ�����
    cmp al, 0  ; �ж��Ƿ�Ϊ���һ������
    je over

    cmp al, 7h  ; �ж��Ƿ������ڣ����ڲ���ʾ
    je kongge
    
    ja fanxiegang  ; �������ֺ��б����ʾ

    jb maohao  ; �������ֺ��ð����ʾ

fanxiegang:
    mov ax, '/'  ; ��ʾб��
    jmp next

maohao:
    mov ax, ':'  ; ��ʾð��
    jmp next

kongge:
    mov ax, ' '  ; ��ʾ�ո�
    jmp next

next:
    mov byte ptr es:[di], al  ; ��ʾ�������ַ�
    add di, 2
over:
    pop cx  ; �ָ�ѭ��������
    loop s0  ; ����ѭ��

    ; ������ѭ�����ٴ�ͷ��ʼִ�г���
    jmp start

mov ax, 4c00h
int 21h
code ends
end start

