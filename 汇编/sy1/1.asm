DATAS SEGMENT
    ;此处输入数据段代码
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
          mov    ax,(-85)
          mov    bx,76
          add    ax,bx
          mov    ax,85
          add    ax,(-76)
          mov    ax,85
          sub    ax,76
          mov    ax,85
          sub    ax,(-76)
          mov    ax,(-85)
          sub    ax,76
          mov    ax,(-85)
          sub    ax,(-76)
    
          MOV    AH,4CH
          INT    21H
CODES ENDS
    END START

