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



int getorder(int *d,int lens,int nums){//���ر��numsֵ���ڵ��������š�lens������d�ĳ��ȡ�
     int i,s2=-1;
     for(i=0;i<lens;i++){
        if(d[i]==nums){
            s2=i;
            break;
        }
     }
  return s2;
}


int*getm(key *k1,int len,int *a,int value,int num){//����begintime��endtime����value�Ķ�Ӧ��Կ�ױ�ţ�
                                                            //����c��ŵ���Կ�׵�����λ�á�
    int i,t;
   // a[0]=0;//��ʾbegintime/endtime����value��Կ��������
    if(num==1){//����begintime==value�Ľ�ʦ�õ�Կ�ױ�š�
        for(i=0;i<len;i++){
            if((k1[i].counts==0)&&(k1[i].begintime==value)){//ֻ����δ�Ͽε���ʦ��

                k1[i].counts=k1[i].counts+1;//ȡ���˸�Կ�ס�
                a[0]=a[0]+1;
                t=a[0];
                a[t]=k1[i].number;
                 cout<<"t:"<<t<<endl;
                cout<<k1[i].number<<endl;
            }
            else
                continue;
        }
    }

    if(num==0){//����endtime==value�Ľ�ʦ�õ�Կ�ױ�š�num==0
       for(i=0;i<len;i++){
            if((k1[i].counts==1)&&(k1[i].endtime==value)){//ֻ����ʦ�Ѿ���ʼ�Ͽ��ˣ�
                k1[i].counts=k1[i].counts+1;//�������Կ�ס�
                a[0]=a[0]+1;
                t=a[0];
                a[t]=k1[i].number;
                cout<<"t:"<<t<<endl;
                cout<<k1[i].number<<endl;
            }
            else
                continue;
        }
    }

 return a;

}


int main(){

  int i;
  int*a=(int*)calloc(5,sizeof(int));
  key*k=(key*)calloc(4,sizeof(key));

 for(i=0;i<5;i++)
    a[i]=0;

  k[0].number=2;
  k[0].begintime=1;
  k[0].consist=3;
  k[0].endtime=4;
  k[0].counts=0;

  k[1].number=4;
  k[1].begintime=1;
  k[1].consist=4;
  k[1].endtime=6;
  k[1].counts=0;

  k[2].number=3;
  k[2].begintime=1;
  k[2].consist=2;
  k[2].endtime=5;
  k[2].counts=0;

  k[3].number=1;
  k[3].begintime=1;
  k[3].consist=3;
  k[3].endtime=5;
  k[3].counts=0;


  a=getm(k,4,a,1,0);

  if(a[0]>0){
    for(i=1;i<a[0];i++)
        cout<<a[i]<<endl;
  }
  else
    cout<<a[0]<<" "<<"������Ԫ��"<<endl;

  //a[0]=23;
  //a[1]=2;
  //a[2]=31;
  //a[3]=7;

  //int con1=getorder(a,4,31);
  //int con2=getorder(a,4,33);

  //cout<<con1<<endl<<con2<<endl;
  return 0;
}
