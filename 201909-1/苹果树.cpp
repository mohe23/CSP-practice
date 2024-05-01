#include<iostream>
#include<stdlib.h>
using namespace std;

int a[1001][1001];
int b[1001];

int main()
{
   int i,j,m,n,sum=0;//m,n表示苹果树数目，疏果次数。
    int orders,v,temp=0;

   cin>>m>>n;

   if(m>1)
   {
     for(i=0;i<m;i++)
     {
        b[i]=0;
         for(j=0;j<n+1;j++)
         {
          cin>>a[i][j];
          sum=sum+a[i][j];
         }

      }

   for(i=0;i<m;i++)
   {
       for(j=1;j<n+1;j++)
    {
        temp=temp+a[i][j];
    }
       b[i]=temp;
       temp=0;
   }

      orders=0;
      v=b[0];
      for(i=1;i<m;i++)
      {
        if(v>b[i])
        {
          orders=i;
          v=b[i];
        }
      }

      v=-v;
      orders=orders+1;
   }

   else//只有1棵树
   {
     for(i=0;i<n+1;i++)
     {
         cin>>b[i];
         sum=sum+b[i];
     }

     v=b[0]-sum;
     orders=1;
   }

   cout<<sum<<" "<<orders<<" "<<v<<endl;
    return 0;
}
