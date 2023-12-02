#include <iostream>
#include <math.h>
using namespace std;
char a[30][40];
//�ݹ鴫Ⱦ
void chuan(int i, int j)
{
    if ((i >= 0 && i < 30) && (j >= 0 && j < 40)){
        if (a[i][j] == '0'){
            a[i][j] = '2';
            chuan(i, j+1);
            chuan(i, j-1);
            chuan(i+1, j);
            chuan(i-1, j);
        }
    }
}

int main()
{
    int n = 0;
    for (int i = 0; i < 30; i++)
    {
        scanf("%s", a[i]);
    }
    system("cls");
    chuan(0,0);
    cout << "==============================================" << endl;
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            cout << a[i][j];
            if(a[i][j]=='2')
                n+=1;
        }
        cout << endl;
    }
     cout <<"2:"<< n <<endl;
    return 0;
}
