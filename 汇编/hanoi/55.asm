DATAS SEGMENT
    ;此处输入数据段代码
    tower db 'A', 'B', 'C'
    disks db 3                ; 汉诺塔的盘子数
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
             ASSUME CS:CODES,DS:DATAS,SS:STACKS
    START:   
             MOV    AX,DATAS
             MOV    DS,AX
    ;此处输入代码段代码
             mov    ax, 0                          ; 初始移动的柱子编号
             mov    bx, 1                          ; 目标移动的柱子编号
             mov    cx, 2                          ; 中间辅助的柱子编号
            
             mov    dx, 3                      ; 盘子数量
             call   hanoi                          ; 调用递归函数

    ; 程序结束
             int    20h

    hanoi:   
             push   ax
             push   bx
             push   cx
             push   dx

    ; 如果盘子数为1，直接移动
             cmp    dx, 1
             je     moveDisk

    ; 递归调用，将上面的n-1个盘子从A移动到C，使用B作为辅助
             mov    ax, dx
             dec    ax
             push   ax
             call   hanoi

    ; 移动底下的盘子
    moveDisk:
             pop    dx
             mov    ah, 2                          ; 输出字符的系统调用
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

    ; 递归调用，将上面的n-1个盘子从C移动到B，使用A作为辅助
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

