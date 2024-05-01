#include<iostream>
#include<stdlib.h>
using namespace std;


int Minorder(int*d,int len)//返回数组d中绝对值最大的序号，如果有并列，返回较小的序号。
{
  int i,order,values;
   order=0;
   values=d[0];
   for(i=1;i<len;i++)
   {
      if(values>d[i])
      {
        order=i;
        values=d[i];
      }
      else if(values==d[i])
      {
          if(order>i)
            order=i;
      }
      else
        continue;
   }

 return order;
}

int main()
{
  int*a=(int*)calloc(10,sizeof(int));
  a[0]=-13;
  a[1]=-3;
  a[2]=-23;
  a[3]=-211;
  a[4]=-31;
  a[5]=-3;
  a[6]=-10;
  a[7]=-9;
  a[8]=-13;
  a[9]=-39;

  int k=Minorder(a,10);
  cout<<k<<endl;
}
