#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{
    int point;//��ʾС���λ�á�
    int lr;//С���˶��ķ���1-���ң�0-����
}ball;


ball *func(ball *ba,int length){//�Ƿ�������ײ��
 int r,s;

 for(r=0;r<length;r++)
   for(s=r+1;s<length;s++){
      if(ba[r].point==ba[s].point){//����2����ײ��

               ba[r].lr=1-ba[r].lr;
               ba[s].lr=1-ba[s].lr;
      }
   }

 return ba;
}


int main(){

 int i,j,k,n,L,t;//n-С����� L-�߶γ��ȣ�t-��Ҫ������ʱ��
// ball a[101];
 cin>>n>>L>>t;
 ball*a=(ball*)calloc(n+1,sizeof(ball));


 for(i=0;i<n;i++){
    cin>>a[i].point;//����С����ʼλ�á�
    a[i].lr=1;//һ��ʼ����С���������˶�
 }
//Ҫ������ײ������ֻ���ƶ�����������
 for(i=0;i<t;i++){
    for(j=0;j<n;j++){

      if(a[j].point==0){//С����������˵㡣
            if(a[j].lr==0){//��ԭ�������˶�
               a[j].lr=1-a[j].lr;
                a[j].point=a[j].point+1;
            }
            else//��ԭ�������˶�
                a[j].point=a[j].point+1;

        }

          else if(a[j].point==L){//С���������Ҷ˵㣬��ת����ͬʱλ�ü�1.
                if(a[j].lr==1){//���յ������˶�
                   a[j].lr=1-a[j].lr;
                   a[j].point=a[j].point-1;
                }
                else//���յ������˶�
                   a[j].point=a[j].point-1;

          }

             else{//С���������м�λ�á�
                 if(a[j].lr==0)//�����˶���
                    a[j].point=a[j].point-1;

                 else//�����˶���
                    a[j].point=a[j].point+1;//�˶�ʱ�����˶˵��Ҫ��ʼ�䷽��

             }
     }

      a=func(a,n);


  }

  for(k=0;k<n;k++)
    cout<<a[k].point<<" ";

  return 0;
}
