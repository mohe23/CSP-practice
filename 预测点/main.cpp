
#include <iostream>
#include<stdlib.h>
using namespace std;

double**Func(double**a,int num)//�������ݴ�С�����������С�
 {
    int i,j,m,n;
   for(i=0;i<3;i++)
   for(j=i+1;j<num;j++)
   {
       if(a[i][1]<a[j][1])
        continue;

     else if(a[i][1]>a[j][1])
     {
       m=a[i][0];//���Ե���š�
       n=a[i][1];//���롣
       a[i][0]=a[j][0];
       a[i][1]=a[j][1];
       a[j][0]=m;
       a[j][1]=n;
     }
     else //���������ʱ������ţ����С����ǰ��
     {
         if(a[i][0]>a[j][0])//���ǰһ�����Ե���Ŵ��ں�һ�����򽻻���ż��ɣ���Ϊֵ����ȣ����ý���ֵ�ˣ���
         {
            m=a[i][0];
            a[i][0]=a[j][0];
            a[j][0]=m;
         }
     }

   }

   return a;
 }


int main()
{
 int i1,n1,x,y,c,d1,d2;
 double **b;
cin>>n1>>x>>y;

 b=(double**)calloc(n1,sizeof(double));
 for(i1=0;i1<n1;i1++)
 {

  b[i1]=(double*)calloc(2,sizeof(double));
 }

 for(i1=0;i1<n1;i1++)
 {

  cin>>d1>>d2;
   c=(x-d1)*(x-d1)+(y-d2)*(y-d2);
    b[i1][0]=i1+1;
    b[i1][1]=c;
 }


 b=Func(b,n1);

 for(i1=0;i1<3;i1++)
 cout<<b[i1][0]<<endl;

 return 0;

}
