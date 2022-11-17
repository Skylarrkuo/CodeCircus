#include <stdio.h>
int main()
{
    // 请在此输入您的代码
    float NP, i, ls, jgrs, yxrs; //人数，循环变量，临时变量存储成绩，及格人数，优秀人数
    float JGL, YXL;              //及格率，优秀率
    scanf("%f", &NP);
    JGL = 0;
    YXL = 0;
    jgrs = 0;
    yxrs = 0;
    for (i = 1; i <= NP; i++)
    {
        scanf("%f", &ls);
        if (ls >= 60.0){
            jgrs++;
            if(ls>=85.0){
                yxrs++;
            }
        }
    }
    JGL = jgrs / NP;
    YXL = yxrs / NP;

    printf("%.0f%%\n", 100 * JGL);
    printf("%.0f%%\n", 100 * YXL);
    return 0;
}