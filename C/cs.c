#include <stdio.h>
#include <math.h>
int main(){
	int n,t,i,j,d=9999;
    int a[100001];
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    	scanf("%d",&a[i]);
	}
	for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - 1 - i; j++){
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                if(d<a[j]-a[j+1]){
                	d=a[j]-a[j+1];
				}
			}
        }
    }
    
	return 0;
}