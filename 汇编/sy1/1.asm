DATAS SEGMENT
    ;�˴��������ݶδ���
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

