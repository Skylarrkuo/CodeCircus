#include <stdio.h >

int main(){
    int a,b;
    float x,y;
    char c1,c2;

    scanf("a=%db=%d",&a,&b);
    scanf("%f%e",&x,&y);
    scanf("%c%c",&c1,&c2);

    printf("\na=%d,b=%d\n",a,b);
    printf("x=%f,y=%e\n",x,y);
    printf("c1=%c,c2=%c",c1,c2);
    

    return 0;
}