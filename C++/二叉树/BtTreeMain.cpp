#include <iostream>
#include <windows.h>
#include "BtTreeMain.h"
using namespace std;

int main(){
    int ZhuangTai= true;
    while (ZhuangTai){
        cout << "1.创建空二叉树"<<endl;
        cout << "2.先序存储二叉树"<<endl;
        cout << "3.先序遍历二叉树"<<endl;
        cout << "4.中序遍历二叉树"<<endl;
        cout << "5.后序遍历二叉树"<<endl;
        cout << "6.销毁二叉树"<<endl;
        cout << "7.清空二叉树"<<endl;
        cout << "0.退出"<<endl;

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
                    cout<<"二叉树已经不存在"<<endl;
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
