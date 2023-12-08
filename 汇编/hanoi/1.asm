DATAS SEGMENT
    ; 此处输入数据段代码
    DISK_COUNT DB 3          ; 汉诺塔的盘子数量
    SOURCE_TOWER DB 'A'      ; 起始塔
    TARGET_TOWER DB 'C'      ; 目标塔
    AUX_TOWER DB 'B'         ; 辅助塔
    MSG_MOVE DB 'Move disk from ', 0
DATAS ENDS

STACKS SEGMENT STACK
    DW 100H DUP (?)  ; 设置栈段大小
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES, DS:DATAS, SS:STACKS
START:
    MOV AX, DATAS
    MOV DS, AX

    ; 初始化
    MOV CX, OFFSET DISK_COUNT
    MOV SI, OFFSET SOURCE_TOWER
    MOV DI, OFFSET TARGET_TOWER
    MOV BX, OFFSET AUX_TOWER

    ; 调用递归过程
    CALL HANOI

    ; 程序结束
    MOV AH, 4CH
    INT 21H

HANOI PROC
    ; 参数：CX = 盘子数量， SI = 起始塔， DI = 目标塔， BX = 辅助塔

    CMP CX, 1      ; 如果只有一个盘子，直接移动
    JE  MOVE_DISK

    ; 否则，先将上面的 CX-1 个盘子从起始塔移动到辅助塔
    MOV DX, CX
    DEC DX
    PUSH DX       ; 保存 CX-1

    PUSH BX       ; 辅助塔作为目标塔
    PUSH DI       ; 目标塔作为辅助塔
    POP DI
    POP BX
    MOV DX, CX
    DEC DX
    PUSH DX
    CALL HANOI    ; 递归调用

    ; 然后，移动最底下的盘子到目标塔
    POP DX        ; 恢复 CX-1
    POP DI        ; 恢复目标塔
    POP BX        ; 恢复辅助塔
    MOV CX, 1
    CALL HANOI    ; 移动盘子

    ; 最后，将辅助塔上的 CX-1 个盘子移动到目标塔
    POP DX        ; 恢复 CX-1
    PUSH SI       ; 起始塔作为辅助塔
    PUSH BX       ; 辅助塔作为起始塔
    POP SI
    POP BX
    MOV CX, DX
    CALL HANOI    ; 递归调用

    RET

MOVE_DISK:
    ; 移动盘子的过程
    MOV AH, 09H
    LEA DX, MSG_MOVE
    INT 21H

    MOV DL, [SI]
    INT 21H

    MOV AH, 09H
    MOV DL, ' '    ; 输出一个空格
    INT 21H

    MOV AH, 09H
    LEA DX, TARGET_TOWER
    INT 21H

    MOV DL, [DI]
    INT 21H

    MOV AH, 09H
    INT 21H

    MOV AH, 09H
    MOV DL, 0AH    ; 换行
    INT 21H

    RET
HANOI ENDP

CODES ENDS
    END START
