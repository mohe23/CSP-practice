#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{
    int x;//��x����
    int y;//��y����
    char ch;//������
}Di;


int All(int*la,int siz)//�ж�����a������Ԫ���Ƿ�ͬ�ţ�size�����鳤�ȡ�����ֵΪ1��ʾ����Ԫ��ͬ�š�
{
    int i5,key=1;

    for(i5=1;i5<siz;i5++)
    {
        if(la[0]*la[i5]<=0)//���������2��Ԫ�����ΪС��0���ߵ���0����ʾ��2��Ԫ����Ż���������һ��Ϊ0����������ʾ����ͬ�š�
        {
            key=0;
            break;
        }

    }

  return key;
}


int main()
{
   int i,j,a1,a2;//a1��a2�ǵ����Լ�ֱ������
    int f1,f2,t1,t2,t3,sum1=0,sum2=0;//t1,t2,t3�ֱ��Ƿ��̵�ϵ����sum1,sum2��ʾ����A��B���͵�����
   double kw;

   cin>>a1>>a2;

   Di*d=(Di*)calloc(a1,sizeof(Di));//����㡣

     for(i=0;i<a1;i++)
     {
          cin>>d[i].x>>d[i].y>>d[i].ch;//����������Լ����͡�
          if(d[i].ch=='A')
             sum1=sum1+1;//ͳ��A�������
          else
            sum2=sum2+1;//ͳ��B���������
     }

       int*wa=(int*)calloc(sum1,sizeof(int));
      int*wb=(int*)calloc(sum2,sizeof(int));

     for(i=0;i<a2;i++)
     {
         cin>>t1>>t2>>t3;//���뷽��ϵ����
         int w1=0,w2=0;

         for(j=0;j<a1;j++)
         {
             kw=t1+t2*d[j].x+t3*d[j].y;//�����������㷽�̵�ֵ��
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

      f1=All(wa,sum1);//�жϵ�i�������£�����A�͵����Ľ���Ƿ�ͬ��
      f2=All(wb,sum2);//�жϵ�i�������£�����B�͵����Ľ���Ƿ�ͬ��

      if(f1&&f2&&(wa[0]*wb[0]<0))//wa[0]*wb[0]<0ȷ��2��Ԫ�صĽ�������෴��
		cout<<"Yes"<<endl;
      else
	    cout<<"No"<<endl;
    }

 return 0;
}
