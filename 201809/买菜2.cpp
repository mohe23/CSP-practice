#include<iostream>
using namespace std;

typedef struct{

  int tbegin;//װ����ʼʱ��
  int tend;//װ������ʱ��

}Time;

Time a[2001],b[2001];

int Is(int t1,int t2,int t3,int t4){//�ж�ʱ���[t1,t2]��[t3,t4]�Ƿ����ص���
    int l1,l2,key;

    if(t1<=t3){
        l1=t1;
        l2=t2;

        if(l2>t3)
            key=1;
        else
            key=0;
    }
    else{
          l1=t3;
          l2=t4;

          if(l2>t1)
            key=1;
          else
            key=0;
    }

   return key;
}

һ��csp��2����Ҫ   2��for     ѭ�����ܽ����
int main(){

int i,j,n,s1,s2,k;
long long sum=0;

cin>>n;

   for(i=0;i<n;i++)
    cin>>a[i].tbegin>>a[i].tend;

   for(i=0;i<n;i++)
    cin>>b[i].tbegin>>b[i].tend;
//�ж�2��ʱ����Ƿ��н��档���ǲ�һ����һ��һ�ģ���a��ÿ1��ʱ�����b��ÿ1��ʱ��αȽϡ�
   for(i=0;i<n;i++){
      for(j=0;j<n;j++){

        k=Is(a[i].tbegin,a[i].tend,b[j].tbegin,b[j].tend);
        if(k==1){//2��ʱ����н���

              if(a[i].tbegin<b[j].tbegin)//a�Ŀ�ʼʱ��<b�Ŀ�ʼʱ�䣬ȡb
                s1=b[j].tbegin;
              else//a�Ŀ�ʼʱ��>=b�Ŀ�ʼʱ�䣬ȡa
                s1=a[i].tbegin;

              if(a[i].tend>b[j].tend)//a�Ľ���ʱ��>b�Ľ���ʱ�䣬ȡb
                s2=b[j].tend;
              else//a�Ľ���ʱ��<=b�Ľ���ʱ�䣬ȡa
                 s2=a[i].tend;

              sum=sum+s2-s1;
           }
       else
         sum=sum+0;

      }


   }

   cout<<sum<<endl;

   return 0;
}
