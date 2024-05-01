#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{
    int x;//点x坐标
    int y;//点y坐标
    char ch;//点的类别。
}Di;


int All(int*la,int siz)//判断数组a的所有元素是否同号，size是数组长度。返回值为1表示所有元素同号。
{
    int i5,key=1;

    for(i5=1;i5<siz;i5++)
    {
        if(la[0]*la[i5]<=0)//如果数组中2个元素相乘为小于0或者等于0，表示这2个元素异号或者至少有一个为0，那这样表示不是同号。
        {
            key=0;
            break;
        }

    }

  return key;
}


int main()
{
   int i,j,a1,a2;//a1，a2是点数以及直线数；
    int f1,f2,t1,t2,t3,sum1=0,sum2=0;//t1,t2,t3分别是方程的系数，sum1,sum2表示的是A，B类型点数。
   double kw;

   cin>>a1>>a2;

   Di*d=(Di*)calloc(a1,sizeof(Di));//坐标点。

     for(i=0;i<a1;i++)
     {
          cin>>d[i].x>>d[i].y>>d[i].ch;//输入点坐标以及类型。
          if(d[i].ch=='A')
             sum1=sum1+1;//统计A类点数量
          else
            sum2=sum2+1;//统计B类点数量。
     }

       int*wa=(int*)calloc(sum1,sizeof(int));
      int*wb=(int*)calloc(sum2,sizeof(int));

     for(i=0;i<a2;i++)
     {
         cin>>t1>>t2>>t3;//输入方程系数。
         int w1=0,w2=0;

         for(j=0;j<a1;j++)
         {
             kw=t1+t2*d[j].x+t3*d[j].y;//带入点坐标计算方程的值。
             if(d[j].ch=='A')
             {
                if(kw>0)
                  wa[w1]=1;
                else if(kw<0)
                    wa[w1]=-1;
                else
                    wa[w1]=0;

                w1=w1+1;
             }

             else
             {
                if(kw>0)
                  wb[w2]=1;
                else if(kw<0)
                    wb[w2]=-1;
                else
                    wb[w2]=0;

                w2=w2+1;
             }
         }

      f1=All(wa,sum1);//判断第i个方程下，所有A型点计算的结果是否同号
      f2=All(wb,sum2);//判断第i个方程下，所有B型点计算的结果是否同号

      if(f1&&f2&&(wa[0]*wb[0]<0))//wa[0]*wb[0]<0确定2种元素的结果符号相反。
		cout<<"Yes"<<endl;
      else
	    cout<<"No"<<endl;
    }

 return 0;
}
