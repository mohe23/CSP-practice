#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{

  int id;//���
  int key;//��ǣ�1-��̭��0-δ��̭
}child;

int Isk(int number,int k0){//�ж�����number�Ƿ���k0�ı�����number�ĸ�λ�Ƿ�k0�����ǣ�����1�����򣬷���0

   int t1=0,t2=0,r;
      if(number%10==k0)
          t1=1;

      if(number%k0==0)//�����ܱ�k0������
         t2=1;

       if(t1+t2>0)//����1��Ϊ1��
           r=1;
       else
           r=0;

return r;
}


int getorder(child *cd,int length){//����δ����̭�ı��

   int p,d;
   for(p=0;p<length;p++){
         if(cd[p].key!=1){
             d=cd[p].id;
             break;
         }
   }

 return d;
}


int main(){

  int i=1,j,label=0,sum=0,n,k,ke,g;

  cin>>n>>k;

  child *c=(child*)calloc(n,sizeof(child));
    for(j=0;j<n;j++){

       c[j].id=j+1;//n��ͬѧ��Ŵ�1��ʼ��
       c[j].key=0;//��ʾδ��̭��
    }

     while(sum!=(n-1)){//ֻҪsum��ֵ��Ϊ(n-1)��

          ke=Isk(i,k);//�ж�����i�Ƿ���k�ı�����������i�ĸ�λ��k�������ڣ�����1�����򣬷���0
          //cout<<ke<<endl;
          if((ke==1)&&(c[label].key==0)){//��ͬѧδ����̭����ʱ�ֵ���һ����̭������
              c[label].key=1;//����̭
              sum=sum+1;
              label=(label+1)%n;
          }

          else if((ke!=1)&&(c[label].key==0)){//��ͬѧδ����̭����ʱ�ֵ���һ������̭������
               g=c[label].id;
               label=(label+1)%n;
               sum=sum+0;
          }
//�ֵ���̭��ͬѧ��Ҫ����һ����̭��ͬѧ�Ƿ��Ǳ���̭��
          else if((ke==1)&&(c[label].key==1)){//��ͬѧ�ѱ���̭,��ʱ�ֵ���һ����̭�����֡���
               while(c[label].key==1){
                   label=(label+1)%n;
               }
                            //�������ͬѧ�����ֵ���һ��ͬѧ��̭
               c[label].key=1;
             sum=sum+1;
             label=(label+1)%n;
          }
          else{//��ͬѧ�ѱ���̭,��ʱ�ֵ���һ������̭�����֡�������ͬѧ���ֵ�����һ��ͬѧ��
             while(c[label].key==1){
                label=(label+1)%n;
               }
             //label=(label+1)%n;
             g=c[label].id;
              sum=sum+0;
             label=(label+1)%n;
          }

        i=i+1;
     }

  //g=getorder(c,n);

  cout<<g<<endl;

  //int f=Isk(3,3);

  //cout<<endl<<f<<endl;

}
