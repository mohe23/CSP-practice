#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{

   int number;//Ҫȡ�õ�Կ�ױ�ţ���1��ʼ��
   int begintime;//ȡԿ��ʱ�䡣
   int consist;//�Ͽ���ʱ��
   int endtime;//��Կ��ʱ�䡣
   int counts;//���������ֵΪ2��˵�������ʦ�Ѿ�����Σ�����Կ���ˡ�
}key;


int*getlist(key *k,int *li,int lengs){//��ÿ�ʼ��������е�ʱ��㡣

   int i,j,t,flag=0;//flag������ǵ�ǰ�����Ƿ��뵱ǰ������Ԫ����ͬ������ͬ��Ϊ1����ͬ����Ϊ0
   li[0]=0;
   for(i=0;i<lengs;i++){
        cout<<"i: "<<i<<endl;
     if(i==0){
           li[0]=li[0]+1;
          li[li[0]]=k[i].begintime;
           li[0]=li[0]+1;
          li[li[0]]=k[i].endtime;        //(k[i].endtime==li[j])
     }
     else{
           for(j=1;j<=li[0];j++){
              if(k[i].begintime==li[j]){//���������ͬ�����֣��Ͳ����롣
                  flag=1;//�����ظ������֡�
                  break;
              }
           }
           if(flag==0){
              li[0]=li[0]+1;
               li[li[0]]=k[i].begintime;
           }
           else
              flag=0;//���½�flag��Ϊ0.

            for(j=1;j<=li[0];j++){
              if(k[i].endtime==li[j]){//���������ͬ�����֣��Ͳ����롣
                  flag=1;//�����ظ������֡�
                  break;
              }
           }
           if(flag==0){
              li[0]=li[0]+1;
               li[li[0]]=k[i].endtime;
           }
           else
              flag=0;
        }
   }

   for(i=1;i<=li[0];i++)
   for(j=i+1;j<=li[0];j++){
      if(li[i]>li[j]){//�������С�
          t=li[i];
          li[i]=li[j];
          li[j]=t;
      }
   }

return li;
}


int main(){
    int i;
   int N=5;
  int K=7;

   key*k=(key*)calloc(K,sizeof(key));//����ÿ1λ��ʦ��
   int*n=(int*)calloc(2*K+1,sizeof(int));//���N��Կ�׵�����λ�ã�һ��ʼ��˳����1~N��

  k[0].number=1;
  k[0].begintime=1;
  k[0].consist=14;
  k[0].endtime=15;
  k[0].counts=0;

  k[1].number=3;
  k[1].begintime=3;
  k[1].consist=12;
  k[1].endtime=15;
  k[1].counts=0;

  k[2].number=1;
  k[2].begintime=15;
  k[2].consist=12;
  k[2].endtime=27;
  k[2].counts=0;

  k[3].number=2;
  k[3].begintime=7;
  k[3].consist=20;
  k[3].endtime=27;
  k[3].counts=0;

  k[4].number=3;
  k[4].begintime=18;
  k[4].consist=12;
  k[4].endtime=30;
  k[4].counts=0;

  k[5].number=4;
  k[5].begintime=21;
  k[5].consist=19;
  k[5].endtime=40;
  k[5].counts=0;

  k[6].number=5;
  k[6].begintime=30;
  k[6].consist=9;
  k[6].endtime=39;
  k[6].counts=0;

  int s=sizeof(char);
  cout<<s<<endl;

  n=getlist(k,n,7);

  for(i=1;i<=n[0];i++)
    cout<<n[i]<<" ";


  cout<<endl;

  return 0;
}
