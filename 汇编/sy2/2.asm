DATAS SEGMENT
      ;�˴��������ݶδ���
      OPR1  DB -85,85,85,85,-85,-85
      OP    DB '++----'
      OPR2  DB 76,-76,76,-76,76,-76
      RES   DB '(1)CF='                  ;���һ������ʽ�ļ����Ҫ����ż�1
      CF    DB '0'                       ;������������CF��־��ֵ��д������
            DB ',ZF='
      ZF    DB '0'                       ;������������ZF��־��ֵ��д������
            DB ',SF='
      SF    DB '0'                       ;������������SF��־��ֵ��д������
            DB ',OF='
      OF    DB '0'                       ;������������OF��־��ֵ��д������
            DB 0DH,0AH,'$'               ;�س����У��ַ������������ƽ��������ʾ
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
            XOR    SI,SI                            ;�������±�Ĵ�����0
      L0:   
      ;�ж�OP[SI]��ֵ�ǡ�+�����ǡ�-����������ִ�мӷ����Ǽ�������
            MOV    AL,OPR1[SI]
            MOV    BL,OP[SI]
            CMP    BL,'+'
            JNZ    L1                               ;�������+����ת�������+������
            ADD    AL,OPR2[SI]                      ;�ӷ�����
            JMP    L2
      L1:   SUB    AL,OPR2[SI]                      ;��������
      ;���ݱ�־λ��ֵ�����ģ���ַ���
      L2:   JC     L3                               ;JC:�����λ��־Ϊ1����ת
            MOV    CF,'0'
            JMP    L4
      L3:   MOV    CF,'1'
      L4:   JE     L5                               ;ZFͨ�������ж������������Ƿ����
            MOV    ZF,'0'
            JMP    L6
      L5:   MOV    ZF,'1'
      L6:   JS     L7                               ;JS��Jump if Sign��ָ�������SFΪ1ʱ��ת
            MOV    SF,'0'                           ;SF��־��ʾ�������ķ��ţ�������Ϊ��������SF������Ϊ1������Ϊ0��
            JMP    L8
      L7:   MOV    SF,'1'
      L8:   JO     L9                               ;JO��Jump if Overflow��ָ�������OFΪ1ʱ��ת
            MOV    OF,'0'                           ;OF��־��ʾ�������Ƿ��������������Ϊ1������Ϊ0��
            JMP    L10
      L9:   MOV    OF,'1'
      L10:  MOV    AH,09H                           ;����ʾ�ַ����Ĺ��ܺ���AH
            MOV    DX,OFFSET RES                    ;��׼����ʾ���ַ�����ƫ�Ƶ�ַ��DX
            INT    21H
            INC    RES[1]                           ;��ģ���еĽ����ż�1
            INC    SI                               ;ʹ�±�ָ����һ������ʽ
            CMP    SI,6
            JB     L0
      L11:  
CODES ENDS
    END START
