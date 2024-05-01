#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{
    int x;//点x坐标
    int y;//点y坐标
    char ch;//点的类别。
}Di;


typedef struct{
    int p;//常数系数
    int q;//x系数
    int t;//y系数
}Xi;


double**Calc(Di*a,Xi*b,int s1,int s2)//根据点坐标x,y带入到直线方程中，返回每一个点的计算结果。s1,s2是点的个数，直线方程的个数。
{
  int i,j;
  double**c=(double**)calloc(s2,sizeof(double));
  for(i=0;i<s2;i++)
    c[i]=(double*)calloc(s1,sizeof(double));//存储不同点在不同直线方程下计算的值。

        for(i=0;i<s2;i++)
         for(j=0;j<s1;j++)
    c[i][j]=(double)((b[i].p)+(a[j].x)*(b[i].q)+(a[j].y)*(b[i].t));


  return c;
}


int*ABorder(Di*a,int suma,char h)//返回数据类型为"h"的数据在结构体数组上的所有位置，用一个数组存放，数组首元素存放
 {                                 //的该数据类型的数据的数据总数。suma是结构体数组a的元素总数。
   int i,su;
   int*s=(int*)calloc(suma,sizeof(int));
     s[0]=0;
   for(i=0;i<suma;i++)
   {
       if(a[i].ch==h)
       {
         su=s[0]+1;
         s[0]=su;//存放类型为h的数据总数
         s[su]=i;//存放数据在结构体的位置。
       }

       else
        continue;
   }

  return s;
 }


 double*GetArray(double**a,int*b,int d)//a是所有的点在不同方程下计算的结果，b是存储A/B类型数据在结构体数组的位置以及个数。
 {                                 //d代表的是哪一个方程下计算的。
     int i,sg,sf;
     sg=b[0];//获得该类型数据的总数。
     double*sc=(double*)calloc(sg,sizeof(double));
     for(i=0;i<sg;i++)
     {
         sf=b[i+1];//表示数据的位置。
         sc[i]=a[d][sf];
     }

  return sc;
 }


int IsAll(double*a,int size)//判断数组a的所有元素是否同号，size是数组长度。返回值为1表示所有元素同号。
{
    int i,key=1;

    for(i=1;i<size;i++)
    {
        if(a[0]*a[i]<0)
        {
            key=0;
            break;
        }
        else
           key=key;
    }

  return key;
}


int main()
{
   int a1,a2,sa,sb,i;
   int *Aorder,*Border;
   double**k;

   cin>>a1>>a2;

   k=(double**)calloc(a2,sizeof(double));
   for(i=0;i<a2;i++)
    k[i]=(double*)calloc(a1,sizeof(double));

   Di*d=(Di*)calloc(a1,sizeof(Di));//坐标点。
   Xi*e=(Xi*)calloc(a2,sizeof(Xi));//存放方程的系数。

    Aorder=(int*)calloc(a1,sizeof(int));//存放A类型数据的个数（首元素存放）和这些元素所在的位置，一开始数组大小都为所有点数。
    Border=(int*)calloc(a1,sizeof(int));//存放B类型数据的个数（首元素存放）和这些元素所在的位置。一开始数组大小都为所有点数

   for(i=0;i<a1;i++)
	  cin>>d[i].x>>d[i].y>>d[i].ch;

   for(i=0;i<a2;i++)
	   cin>>e[i].p>>e[i].q>>e[i].t;

    k=Calc(d,e,a1,a2);//存放所有点在不同的方程下的计算结果。

    Aorder=ABorder(d,a1,'A');
    Border=ABorder(d,a1,'B');

    sa=Aorder[0];//类型为A的数据的数量
    sb=Border[0];//类型为B的数据的数量

    for(i=0;i<a2;i++)
    {
      int f1,f2;
      double*wa=(double*)calloc(sa,sizeof(double));
      double*wb=(double*)calloc(sb,sizeof(double));//!!!!!!错误之一
      wa=GetArray(k,Aorder,i);//第i个方程下，所有A型点计算的结果。
      wb=GetArray(k,Border,i);//第i个方程下，所有B型点计算的结果。

      f1=IsAll(wa,sa);//判断第i个方程下，所有A型点计算的结果是否同号
      f2=IsAll(wb,sb);//判断第i个方程下，所有B型点计算的结果是否同号
      //如果上述2个数组的各个数组内元素的符号相同，还要确定2个数组的元素符号要相反，才表示正确分了类。

      if((f1==1)&&(f2==1)&&(wa[0]*wb[0]<0))//wa[0]*wb[0]<0确定2种元素的结果符号相反。
		cout<<"YES"<<endl;
      else
	   cout<<"NO"<<endl;

    }

 return 0;

}
