DATAS SEGMENT
	;此处输入数据段代码
	in_msg  db 'input hex: $'
	out_msg db 10,13,'output: $'
	inv     db 10,13,'invalid  $'
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
	;mov dx,offset in_msg
	      lea    dx,in_msg
	      mov    ah,09
	      int    21h
    

	      xor    bx,bx                      	;mov bx,0
	l0:   
	      mov    ah,1
	      int    21h
	      cmp    al,0dh
	      je     l4
	      cmp    al,'0'
	      jb     l5
	      cmp    al,'9'
	      ja     l1
	      sub    al,30h
	      jmp    l3
	l1:   cmp    al,'A'
	      jb     l5
	      cmp    al,'F'
	      ja     l2
	      sub    al,37h
	      jmp    l3
	l2:   cmp    al,'a'
	      jb     l5
	      cmp    al,'f'
	      ja     l5
	      sub    al,57h
	l3:   mov    ah,0
	      push   cx
	      mov    cl,4
	      shl    bx,cl
	      add    bx,ax
	      pop    cx
	      loop   l0
    
	l4:   
	      mov    dx,offset out_msg
	      mov    ah,9
	      int    21h
	      mov    cx,16
	      mov    ax,8000h
	l8:   
	      push   ax
	      test   bx,ax
	      jnz    l9
	      mov    dl,'0'
	      jmp    l10
	l9:   
	      mov    dl,'1'
	l10:  
	      mov    ah,2
	      int    21h
	      pop    ax
	      shr    ax,1
	      loop   l8
	      jmp    l6
	
	l5:   mov    ah,9
	      mov    dx,offset inv
	      int    21h
	l6:   
	      MOV    AH,4CH
	      INT    21H
CODES ENDS
    END START

