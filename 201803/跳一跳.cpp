#include<iostream>
using namespace std;

int main(){

int i,a[31],b[31],n=0;//b[31]��ŵ���ÿһ�εĵ÷֡�
long long sum=0;

//for(i=0;i<31;i++)
    //a[i]=3;//�ó�ֵ������1,2,0��

for(i=0;i<31;i++){
    cin>>a[i];


    if(a[i]==0)
        break;
    else
        continue;

      n=n+1;
}


for(i=0;i<31;i++){
    if(a[i]==1){//�����˷����ϣ�����û�����������ϡ�
        sum=sum+1;
        b[i]=1;
    }
    else if(a[i]==2){//�����˷������ġ�
        if(i==0){//��1�����������ġ�
             sum=sum+2;
             b[i]=2;
            }

        else{//��n�����ڷ������ġ�
              if(b[i-1]==1){//ǰ1��÷�Ϊ1�֣���ε�2��
                sum=sum+2;
                b[i]=2;
              }
              else{//ǰ1��÷�Ϊ2�֣���ε÷���ǰ1�ε÷ּ�2��

                sum=sum+b[i-1]+2;
                b[i]=b[i-1]+2;
              }
            }
          }

       else{//�����������0������ѭ����

        b[i]=0;
        break;
       }
    }

  cout<<sum<<endl;
    return 0;
}





