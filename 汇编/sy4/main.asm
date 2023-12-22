CODES  SEGMENT
       ASSUME CS:CODES,DS:CODES
; 定义IntrDispTime  1CH中断处理子程序
;显示个人信息和时间的中断处理程序
IntrDispTime PROC Far
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	PUSH SI
	PUSH DI
	PUSH DS
	PUSH ES
	MOV AX, CODES
	MOV DS, AX 
	MOV AX, 0B800H
	MOV ES, AX               ;ES指向显示缓存段
	CALL  ReadDateTime
	MOV SI,  OFFSET TIME_STYLE
	MOV DI, 80*0*2 + 62*2    ;屏幕第0行第62列在显存中的偏移地址
	CALL  DispString
	MOV SI, OFFSET MyInfor
	MOV DI, 0                ;屏幕第0行第0列在显存中的偏移地址
	CALL DispString
	POP ES
	POP DS
	POP DI
	POP SI
	POP DX
	POP CX
	POP BX
	POP AX
	IRET
IntrDispTime ENDP
; 定义TIME_STYLE,TIME_CMOS,MyInfor 变量
TIME_STYLE   db 'YY/MM/DD HH:MM:SS',0 ;格式化的日期时间字符串
TIME_CMOS   db 9,8,7,4,2,0 ;CMOS RAM中日期时间各分量的地址
MyInfor  db 'PROGRAMMER: Zhang San, 1234567890, Class 2',0 ;个人信息

; 定义DispString  显示0结尾的字符串子程序
;在屏幕上显示0结尾的字符串
;入口参数: ES指向显示缓存段
;SI = 0字符串首偏移地址
;DI = 显示缓存偏移地址(=I*80*2+j*2)
DispString   PROC   Near
          PUSH AX             ;保护寄存器
NextChar:
          LODSB                 ;AL<-(SI),SI<-SI+1
          CMP AL,0
          JE DispOver
          MOV AH,00000111B      ;字符属性
          STOSW                 ;(DI)<-AX, DI<-DI+2
          JMP NextChar
DispOver:
           POP AX ;恢复寄存器
           Ret
DispString ENDP

; 定义ReadDateTime读日期时间子程序
;读取CMOS RAM中的日期时间于TIME_STYLE中
ReadDateTime PROC Near
        MOV SI,OFFSET TIME_CMOS
        MOV DI,OFFSET TIME_STYLE
        MOV CX,6
NextRead:           ;循环6次
        MOV  AL, [SI]
        OUT  70H, AL   ;设置日期时间分量的地址
        IN  AL, 71H       ;读取日期时间分量于AL
        MOV AH,AL
        SHR AH, 1
        SHR AH, 1
        SHR AH, 1
        SHR AH, 1       ;分离日期时间分量高位BCD码存于AH
        AND AL, 00001111B;低位BCD码存于AL
        ADD AH, 30H
        ADD AL, 30H     ;转换成字符SACII
        MOV [DI], AH
        MOV [DI+1], AL  ;存于TIME_STYLE字符串
        ADD DI, 3
        INC SI
        LOOP NextRead
        Ret
ReadDateTime ENDP
; 定义 Main主程序
;主程序
Main PROC Far  
	;设置1CH中断向量
	MOV   AX,  SEG IntrDispTime
	MOV   DS, AX    
	MOV   DX,  OFFSET IntrDispTime
	MOV   AL, 1CH
	MOV   AH, 25H
	INT   21H
	;退出并驻留内存
	MOV ah, 31h
	mov al, 0   ;结束返回值0
	mov dx, ((Main -IntrDispTime + 15)/16)+ 16  ;驻留内存节数(连同PSP)  
	INT 21H
Main ENDP 

CODES ENDS
  END Main
