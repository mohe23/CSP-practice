#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{
  int x;//点的x坐标。
  int y;//点的y坐标。
}Cor;


int Isin(int x,int y,int xl,int yb,int xr,int yt)//判断1个点坐标是否在矩形区域内，（xl,yb）是左下角坐标。(xr,yt)是右上角坐标
{
   int key;
   if((x>=xl)&&(x<=xr)&&(y>=yb)&&(y<=yt))
        key=1;
   else
        key=0;

   return key;
}


int Pan(Cor*a,int s,int len,int x1,int y1,int x2,int y2)//判断该人员是逗留高风险区域，还是经过高风险区域.s是连续经过的界定值。
{
  int i,j=0,ke,kee,s1=0,s2=0;
  for(i=0;i<len;i++)
  {
    kee=Isin(a[i].x,a[i].y,x1,y1,x2,y2);

    if(kee==1)
    {
        s1=s1+1;//在矩形区域内的点数
        s2=s2+1;//连续在矩形区域内的点数，只要遇到1个不在矩形区域内的点，立即清0。
    }

    else
    {
        s1=s1;
        s2=0;
    }

    cout<<"s1:"<<s1<<endl;
    cout<<"s2:"<<s2<<endl;
    if((s1>=s)&&(s2>=s))
    {
        ke=2;//表示该人员是逗留的
        j=1;
       // cout<<endl;
        break;
       //return
    }

  }

  while(j!=1)
  {
    if((s1>=1)&&(s2<s))
      ke=1;//这个表示该人员只是经过该区域
    else
      ke=0;//表示该人员就没有经过该区域。

      break;
  }

   return ke;
}


int main()
{

  int i,j,sum,k,t,x1,y1,x2,y2,flag,sum1=0,sum2=0;//sum1表示经过高风险区域的人数，sum2表示逗留高风险区域的人数
  cin>>sum>>k>>t>>x1>>y1>>x2>>y2;

  for(i=0;i<sum;i++)//从第1个人开始处理。
  {
      Cor*a=(Cor*)calloc(t,sizeof(Cor));//存储1个人的t个坐标记录。

      for(j=0;j<t;j++)
      cin>>a[j].x>>a[j].y;//表示一个人员经过的点的坐标。

      flag=Pan(a,k,t,x1,y1,x2,y2);

      if(flag==2)//曾经逗留的同时也表示经过。
      {
        sum1=sum1+1;
        sum2=sum2+1;
      }

      else if(flag==1)
        sum1=sum1+1;
      else
        continue;
  }


   cout<<sum1<<endl;
   cout<<sum2<<endl;

  return 0;
}
