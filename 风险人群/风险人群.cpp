#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{
  int x;//���x���ꡣ
  int y;//���y���ꡣ
}Cor;


int Isin(int x,int y,int xl,int yb,int xr,int yt)//�ж�1���������Ƿ��ھ��������ڣ���xl,yb�������½����ꡣ(xr,yt)�����Ͻ�����
{
   int key;
   if((x>=xl)&&(x<=xr)&&(y>=yb)&&(y<=yt))
        key=1;
   else
        key=0;

   return key;
}


int Pan(Cor*a,int s,int len,int x1,int y1,int x2,int y2)//�жϸ���Ա�Ƕ����߷������򣬻��Ǿ����߷�������.s�����������Ľ綨ֵ��
{
  int i,j=0,ke,kee,s1=0,s2=0;
  for(i=0;i<len;i++)
  {
    kee=Isin(a[i].x,a[i].y,x1,y1,x2,y2);

    if(kee==1)
    {
        s1=s1+1;//�ھ��������ڵĵ���
        s2=s2+1;//�����ھ��������ڵĵ�����ֻҪ����1�����ھ��������ڵĵ㣬������0��
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
        ke=2;//��ʾ����Ա�Ƕ�����
        j=1;
       // cout<<endl;
        break;
       //return
    }

  }

  while(j!=1)
  {
    if((s1>=1)&&(s2<s))
      ke=1;//�����ʾ����Աֻ�Ǿ���������
    else
      ke=0;//��ʾ����Ա��û�о���������

      break;
  }

   return ke;
}


int main()
{

  int i,j,sum,k,t,x1,y1,x2,y2,flag,sum1=0,sum2=0;//sum1��ʾ�����߷��������������sum2��ʾ�����߷������������
  cin>>sum>>k>>t>>x1>>y1>>x2>>y2;

  for(i=0;i<sum;i++)//�ӵ�1���˿�ʼ����
  {
      Cor*a=(Cor*)calloc(t,sizeof(Cor));//�洢1���˵�t�������¼��

      for(j=0;j<t;j++)
      cin>>a[j].x>>a[j].y;//��ʾһ����Ա�����ĵ�����ꡣ

      flag=Pan(a,k,t,x1,y1,x2,y2);

      if(flag==2)//����������ͬʱҲ��ʾ������
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
