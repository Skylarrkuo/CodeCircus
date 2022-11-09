#include <stdio.h>
#include <stdlib.h>
int main(){
    int arrLen; 
    int *array;
    int i;
    printf("please enter length：");
    scanf_s("%d", &arrLen);
    
    array = (int*)malloc( arrLen*sizeof(int) );
    if(!array){
        printf("create error！\n");
        exit(1); 
    }
    for(i=0; i<arrLen; i++){
        array[i] = i+1;
    }
    
    for(i=0; i<arrLen; i++){
        printf("%d  ", array[i]);
    }
    
    printf("\n");
    free(array); 
    
    system("pause");
    return 0;
}