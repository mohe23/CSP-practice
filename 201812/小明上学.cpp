#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{

  int k;//��ʶ���̵�
  int t;//
}road;


int main(){

 int i,r,y,g,sum,s=0;
 cin>>r>>y>>g;
 cin>>sum;

 road*d=(road*)calloc(sum,sizeof(road));
 for(i=0;i<sum;i++)
    cin>>d[i].k>>d[i].t;

 for(i=0;i<sum;i++){
     if(d[i].k==0)//ͨ��·��,
          s=s+d[i].t;
      else if(d[i].k==1)//�������
             s=s+d[i].t;
         else if(d[i].k==2)//�����Ƶƣ�����ע�⣬��Ϊ�Ƶƹ����Ǻ�ƣ�����Ҫ�ٶ�����Ϻ��ʱ�䡣
               s=s+d[i].t+r;
            else
                continue;

 }

 cout<<s;

 return 0;
}
