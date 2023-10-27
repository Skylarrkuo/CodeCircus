#include <iostream>
#include <windows.h>
#include "BtTreeMain.h"
using namespace std;

int main(){
    int ZhuangTai= true;
    while (ZhuangTai){
        cout << "1.�����ն�����"<<endl;
        cout << "2.����洢������"<<endl;
        cout << "3.�������������"<<endl;
        cout << "4.�������������"<<endl;
        cout << "5.�������������"<<endl;
        cout << "6.���ٶ�����"<<endl;
        cout << "7.��ն�����"<<endl;
        cout << "0.�˳�"<<endl;

        cin>>ZhuangTai;
        switch (ZhuangTai) {
            case 1:
                BiTNode *T;
                system("pause");
                break;
            case 2:
                CreateBiTree_PreOrder(T);
                system("pause");
                break;
            case 3:
                if(T->Date){
                    PreOrderTraverse(T);
                }
                system("pause");
                break;
            case 4:
                if(T->Date){
                    PreOrderTraverse(T);
                }
                system("pause");
                break;
            case 5:
                if(T->Date){
                    InOrderTraverse(T);
                }
                system("pause");
                break;
            case 6:
                if(T->Date){
                    DestroyBiTree(T);
                }else{
                    cout<<"�������Ѿ�������"<<endl;
                }
                system("pause");
                break;
            case 7:
                break;
        }
        system("cls");
    }
    return 0;
}
