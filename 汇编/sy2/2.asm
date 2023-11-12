DATAS SEGMENT
      ;此处输入数据段代码
      OPR1  DB -85,85,85,85,-85,-85
      OP    DB '++----'
      OPR2  DB 76,-76,76,-76,76,-76
      RES   DB '(1)CF='                  ;完成一个运算式的计算后，要将编号加1
      CF    DB '0'                       ;根据运算结果将CF标志的值填写在这里
            DB ',ZF='
      ZF    DB '0'                       ;根据运算结果将ZF标志的值填写在这里
            DB ',SF='
      SF    DB '0'                       ;根据运算结果将SF标志的值填写在这里
            DB ',OF='
      OF    DB '0'                       ;根据运算结果将OF标志的值填写在这里
            DB 0DH,0AH,'$'               ;回车换行，字符串结束，控制结果分行显示
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
            XOR    SI,SI                            ;将数组下标寄存器清0
      L0:   
      ;判断OP[SI]的值是‘+’还是‘-’来决定是执行加法还是减法运算
            MOV    AL,OPR1[SI]
            MOV    BL,OP[SI]
            CMP    BL,'+'
            JNZ    L1                               ;如果不是+则跳转，如果是+则跳过
            ADD    AL,OPR2[SI]                      ;加法运算
            JMP    L2
      L1:   SUB    AL,OPR2[SI]                      ;减法运算
      ;根据标志位的值填充结果模板字符串
      L2:   JC     L3                               ;JC:如果进位标志为1则跳转
            MOV    CF,'0'
            JMP    L4
      L3:   MOV    CF,'1'
      L4:   JE     L5                               ;ZF通常用于判断两个操作数是否相等
            MOV    ZF,'0'
            JMP    L6
      L5:   MOV    ZF,'1'
      L6:   JS     L7                               ;JS（Jump if Sign）指令，它会在SF为1时跳转
            MOV    SF,'0'                           ;SF标志表示运算结果的符号，如果结果为负数，则SF被设置为1，否则为0。
            JMP    L8
      L7:   MOV    SF,'1'
      L8:   JO     L9                               ;JO（Jump if Overflow）指令，它会在OF为1时跳转
            MOV    OF,'0'                           ;OF标志表示运算结果是否溢出，如果溢出则为1，否则为0。
            JMP    L10
      L9:   MOV    OF,'1'
      L10:  MOV    AH,09H                           ;将显示字符串的功能号送AH
            MOV    DX,OFFSET RES                    ;将准备显示的字符串的偏移地址送DX
            INT    21H
            INC    RES[1]                           ;将模板中的结果编号加1
            INC    SI                               ;使下标指向下一个运算式
            CMP    SI,6
            JB     L0
      L11:  
CODES ENDS
    END START
