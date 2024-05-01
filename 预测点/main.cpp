
#include <iostream>
#include<stdlib.h>
using namespace std;

double**Func(double**a,int num)//根据数据大小按照升序排列。
 {
    int i,j,m,n;
   for(i=0;i<3;i++)
   for(j=i+1;j<num;j++)
   {
       if(a[i][1]<a[j][1])
        continue;

     else if(a[i][1]>a[j][1])
     {
       m=a[i][0];//测试点序号。
       n=a[i][1];//距离。
       a[i][0]=a[j][0];
       a[i][1]=a[j][1];
       a[j][0]=m;
       a[j][1]=n;
     }
     else //当距离相等时，看序号，序号小的在前。
     {
         if(a[i][0]>a[j][0])//如果前一个测试点序号大于后一个，则交换序号即可（因为值都相等，不用交换值了）。
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
