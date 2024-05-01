//#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct{
    int x;//��x����
    int y;//��y����
    char ch;//������
}Di;


typedef struct{
    int p;//����ϵ��
    int q;//xϵ��
    int t;//yϵ��
}Xi;


double**Calc(Di*a,Xi*b,int s1,int s2)//���ݵ�����x,y���뵽ֱ�߷����У�����ÿһ����ļ�������s1,s2�ǵ�ĸ�����ֱ�߷��̵ĸ�����
{
  int i,j;
  double**c=(double**)calloc(s2,sizeof(double));
  for(i=0;i<s2;i++)
    c[i]=(double*)calloc(s1,sizeof(double));//�洢��ͬ���ڲ�ֱͬ�߷����¼����ֵ��

  for(i=0;i<s2;i++)
  for(j=0;j<s1;j++)
  {
    c[i][j]=(double)(b[i].p)+(double)(a[j].x)*(double)(b[i].q)+(double)(a[j].y)*(double)(b[i].t);
  }

  return c;
}



int*ABorder(Di*a,int suma,char h)//������������Ϊ"h"�������ڽṹ�������ϵ�����λ�ã���һ�������ţ�������Ԫ�ش��
 {                                 //�ĸ��������͵����ݵ�����������suma�ǽṹ������a��Ԫ��������
   int i,su;
   int *so=(int*)calloc(suma,sizeof(int));
     so[0]=0;
   for(i=0;i<suma;i++)
   {
       if(a[i].ch==h)
       {
         su=so[0]+1;
         so[0]=su;//�������Ϊh����������
         so[su]=i;//��������ڽṹ���λ�á�
       }
   }

  return so;
 }


 double*GetArray(double**a,int*b,int d)//a�����еĵ��ڲ�ͬ�����¼���Ľ����b�Ǵ洢A/B���������ڽṹ�������λ���Լ�������
 {                                 //d���������һ�������¼���ġ�
     int i,sg,sf;
     sg=b[0];//��ø��������ݵ�������
     double*c=(double*)calloc(sg,sizeof(double));
     for(i=0;i<sg;i++)
     {
         sf=b[i+1];//��ʾ���ݵ�λ�á�
         c[i]=a[d][sf];
     }

  return c;
 }


int IsAll(double*a,int size)//�ж�����a������Ԫ���Ƿ�ͬ�ţ�size�����鳤�ȡ�����ֵΪ1��ʾ����Ԫ��ͬ�š�
{
    int i,key=1;

    for(i=1;i<size;i++)
    {
        if(a[0]*a[i]<0)
        {
            key=0;
            break;
        }
    }

  return key;
}


int main()
{
   int a1,a2,sa,sb,i;
   int *Aorder,*Border;
   double**k;


   scanf("%d %d",&a1,&a2);//���������������

   k=(double**)calloc(a2,sizeof(double));
   for(i=0;i<a1;i++)
    k[i]=(double*)calloc(a1,sizeof(double));

   Di*d=(Di*)calloc(a1,sizeof(Di));//����㡣
   Xi*e=(Xi*)calloc(a2,sizeof(Xi));//��ŷ��̵�ϵ����

    Aorder=(int*)calloc(a1,sizeof(int));//���A�������ݵĸ�������Ԫ�ش�ţ�����ЩԪ�����ڵ�λ�á�
    Border=(int*)calloc(a2,sizeof(int));//���B�������ݵĸ�������Ԫ�ش�ţ�����ЩԪ�����ڵ�λ�á�

   for(i=0;i<a1;i++)
       scanf("%d %d %c",&(d[i].x),&(d[i].y),&(d[i].ch));

   for(i=0;i<a2;i++)
       scanf("%d %d %d",&(e[i].p),&(e[i].q),&(e[i].t));

    k=Calc(d,e,a1,a2);//������е��ڲ�ͬ�ķ����µļ�������

    Aorder=ABorder(d,a1,'A');
    Border=ABorder(d,a1,'B');

    sa=Aorder[0];//����ΪA�����ݵ�����
    sb=Border[0];//����ΪB�����ݵ�����

    for(i=0;i<a2;i++)
    {
      int f1,f2;
      double*wa=(double*)calloc(sa,sizeof(double));
      double*wb=(double*)calloc(sa,sizeof(double));
      wa=GetArray(k,Aorder,i);//��i�������£�����A�͵����Ľ����
      wb=GetArray(k,Border,i);//��i�������£�����B�͵����Ľ����

      f1=IsAll(wa,sa);//�жϵ�i�������£�����A�͵����Ľ���Ƿ�ͬ��
      f2=IsAll(wb,sb);//�жϵ�i�������£�����B�͵����Ľ���Ƿ�ͬ��
      //�������2������ĸ���������Ԫ�صķ�����ͬ����Ҫȷ��2�������Ԫ�ط���Ҫ�෴���ű�ʾ��ȷ�����ࡣ

      if((f1==1)&&(f2==1)&&(wa[0]*wb[0]<0))//wa[0]*wb[0]<0ȷ��2��Ԫ�صĽ�������෴��
        printf("YES\n");
      else
        printf("NO\n");

    }

 return 0;

}
