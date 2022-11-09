#include <stdio.h>

int main(){
    printf("%ld\n",__STDC_VERSION__);
    system("pause");
    int i;
    char c[]="yhyhfgjfghjfghjfghjfghkjfgjkfg";
    printf("%lld\n", sizeof(c));
    printf("%s\n", c);
    for (i = sizeof(c)-1; i >=0 ;i--){
        printf("%c", c[i]);
    }
}