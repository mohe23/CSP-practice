#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{
    int p;//常数系数
    int q;//x系数
    int t;//y系数
}Xi;

int main()
{

 Xi*x=(Xi*)malloc(sizeof(Xi));
 cin>>x->p>>x->q>>x->t;
 cout<<x->p<<endl<<x->q<<x->t<<endl;
 return 0;
}
