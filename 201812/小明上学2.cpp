#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{

  int k;//��ʶ���̵�
  long long t;//����ʱ�̣����̵Ƶĵ���ʱ��
}road;


int main(){

  int i;
  long long r,y,g,n,num,sum,s,sum1=0;
   road d[100001];
  cin>>r>>y>>g;
  cin>>n;

   //road*d=(road*)calloc(n,sizeof(road));
     for(i=0;i<n;i++)
    cin>>d[i].k>>d[i].t;


    for(i=0;i<n;i++){
            num=d[i].t;

        if(d[i].k==0)
            sum1=sum1+num;

        else if(d[i].k==1){//����ʱ��ʱ���źŵ�Ϊ���
                sum=sum1%(r+y+g);
                s=sum1/(r+y+g);

            if(sum<num)
               sum=num;
              else if((sum>=num)&&(sum<(num+g)))
                   sum=sum;
                else if((sum>=(num+g))&&(sum<(num+g+y)))
                    sum=num+g+y+r;
                  else //if((sum>=(num+g+y))&&(sum<(r+g+y)))//sum-num-g-y>0
                      sum=num+r+g+y;

            sum1=sum+(r+g+y)*s;
        }

         else if(d[i].k==2){//����ʱ�̸��źŵ�Ϊ�Ƶơ�
              sum=sum1%(r+y+g);
                s=sum1/(r+y+g);

              if(sum<num+r)
                  sum=num+r;
               else if((sum>=(num+r))&&(sum<(num+g+r)))
                  sum=sum;
                else //sum-num>r
                    sum=g+2*r+y+num;

            sum1=sum+(r+g+y)*s;
         }
        else{//����ʱ���źŵ�Ϊ�̵�
           sum=sum1%(r+y+g);
            s=sum1/(r+y+g);

         if(sum<num)
            sum=sum;
         else if((sum>=num)&&(sum<(num+y)))
            sum=num+r+y;
         else if((sum>=(num+y))&&(sum<(num+y+r)))
            sum=num+y+r;
         else
            sum=sum;

           sum1=sum+(r+g+y)*s;
        }

    }
cout<<sum1<<endl;

}
