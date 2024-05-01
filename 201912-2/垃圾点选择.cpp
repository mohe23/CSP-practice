#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{
  int x;
  int y;
}Cord;

int Is(int a,int b,Cord*c,int len)//判断点(a,b)是否在结构体数组c中。
{
    int i,key=0;
    for(i=0;i<len;i++)
    {
       if((a==c[i].x)&&(b==c[i].y))
        {
            key=1;
            break;
        }

    }
  return key;
}

int Grade(int a,int b,Cord*c,int len)
{
  int i,k1,k2,k3,k4,k5,k6,k7,k8;//分别表示左，右，上，下，左上，左下，右上，右下。
  int sum,sum0,sum1,sum2,sum3,sum4;
  k1=Is(a-1,b,c,len);//左
  k2=Is(a+1,b,c,len);//右
  k3=Is(a,b+1,c,len);//上
  k4=Is(a,b-1,c,len);//下
  k5=Is(a-1,b+1,c,len);//左上
  k6=Is(a-1,b-1,c,len);//左下
  k7=Is(a+1,b+1,c,len);//右上
  k8=Is(a+1,b-1,c,len);//右下

  if(k1*k2*k3*k4==1)//表示找到了符合要求的一个垃圾点。
    sum=k5+k6+k7+k8;
  else//找不到符合要求的垃圾点。
    sum=5;

  return sum;
}

int main()
{
  int i,num,s,s0,s1,s2,s3,s4,s5;
  s0=s1=s2=s3=s4=0;
   Cord*d;
   cin>>num;

   d=(Cord*)calloc(num,sizeof(Cord));

   for(i=0;i<num;i++)
    cin>>d[i].x>>d[i].y;

   for(i=0;i<num;i++)
   {
     s=Grade(d[i].x,d[i].y,d,num);
     switch(s)
     {
         case 0: s0=s0+1;break;
         case 1: s1=s1+1;break;
         case 2: s2=s2+1;break;
         case 3: s3=s3+1;break;
         case 4: s4=s4+1;break;
         case 5: s5=s5+1;break;
         default:cout<<"出错!"<<endl;break;
     }

   }

  cout<<s0<<endl;
  cout<<s1<<endl;
  cout<<s2<<endl;
  cout<<s3<<endl;
  cout<<s4<<endl;

  return 0;
}
