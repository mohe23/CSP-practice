#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{
    int p;//����ϵ��
    int q;//xϵ��
    int t;//yϵ��
}Xi;

int main()
{

 Xi*x=(Xi*)malloc(sizeof(Xi));
 cin>>x->p>>x->q>>x->t;
 cout<<x->p<<endl<<x->q<<x->t<<endl;
 return 0;
}
