#include<iostream>
#include<stdlib.h>
using namespace std;


int getorder(int*a,int len,int b){//���ѧ��Ϊb�������е��±ꡣ

   int i,s;
   for(i=0;i<len;i++){
      if(b==a[i]){
         s=i;
         break;
      }
   }
  return s;
}


int*mov(int*a,int le,int number,int lens){//le������a�ĳ��ȣ�lens�Ǹ�ѧ���ƶ��ľ��롣

    int i,t,s;
    t=getorder(a,le,number);
    s=a[t];//����ѧ�ű����洢��

    if(lens>0){//����ƶ�������
        for(i=t;i<t+lens;i++)
        a[i]=a[i+1];

       a[t+lens]=s;//����ѧ���ƶ���ָ��λ�á�
    }
    else{//��ǰ�ƶ�
       for(i=t;i>t+lens;i--)
            a[i]=a[i-1];

       a[t+lens]=s;
    }

 return a;
}


int main(){

  int i,sum,num,w[1001][2];
  cin>>sum;
  cin>>num;
  for(i=0;i<num;i++)
    cin>>w[i][0]>>w[i][1];

  int*arr=(int*)calloc(sum,sizeof(int));//ѧ��λ������
   for(i=0;i<sum;i++)
       arr[i]=i+1;//һ��ʼ����ѧ�Ŵ����������С�


   for(i=0;i<num;i++)
     arr=mov(arr,sum,w[i][0],w[i][1]);

   for(i=0;i<sum;i++)
    cout<<arr[i]<<" ";

 return 0;
}



