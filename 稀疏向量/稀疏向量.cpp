#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{
   int order;//序号
   long value;//值
}Ve;


int main()
{
   int i,j=0,s,r=0,s2,s3;
   int t1;
   long t2;//s1,s2,s3分别表示向量的维度数，a,b向量中不为0的分量数目。
   long long s1;
   long long k=0;//a,b向量的内积。
   cin>>s1>>s2>>s3;

   Ve*a=(Ve*)calloc(s2,sizeof(Ve));

   for(i=0;i<s2;i++)
    cin>>a[i].order>>a[i].value;//输入向量a不为0的分量。

   for(i=0;i<s3;i++)
   {
      cin>>t1>>t2;
       while(j<s2)
       {
           if(t1<a[j].order)
            break;
           else if(t1>a[j].order)
            j=j+1;
           else
           {
               k=k+t2*(a[j].value);
               break;
           }

       }

   }

   cout<<k<<endl;

   return 0;
}
