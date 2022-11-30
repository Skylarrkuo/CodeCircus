#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int count[26]={0},max=0,i;
  char ch;
  while((ch=getchar())!='\n')
    count[ch-'a']++;
  for(i=1;i<26;i++)
    if(count[i]>count[max])
      max=i;
  printf("%c\n%d",max+'a',count[max]);
  return 0;
}