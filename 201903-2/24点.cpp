#include<iostream>
using namespace std;


typedef struct{

  int a1;
  char a2;
  int a3;
  char a4;
  int a5;
  char a6;
  int a7;
}Da;


int Compa(char c1,char c2){//�Ƚ�c1,c2�����ȼ������c1>c2,����1�����򷵻�0��

   int t=1;

   if(((c1=='+')||(c1=='-'))&&((c2=='x')||(c2=='/')))
            t=0;

  return t;
}


int Cal(int m1,char m2,int m3){//����ñ��ʽֵ��

    int s;
    if(m2=='+')//�ӷ�
        s=m1+m3;
      else if(m2=='-')//����
          s=m1-m3;
        else if(m2=='x')//�˷�
            s=m1*m3;
          else //����
             s=m1/m3;

    return s;
}


void Calculate(int n1,char h2,int n3,char h4,int n5){//�жϱ��ʽ�Ƿ���24�㣬����ǣ���ӡYes�������ӡNo .
    int r,sum;

    //cout<<n1<<" "<<h2<<" "<<n3<<" "<<h4<<" "<<n5<<endl;
    r=Compa(h2,h4);//�Ƚ�����������ȼ���
    if(r==1){


       sum=Cal(n1,h2,n3);
       //cout<<sum<<endl;
       sum=Cal(sum,h4,n5);
    }

    else{

      sum=Cal(n3,h4,n5);
      //cout<<sum<<endl;
      sum=Cal(n1,h2,sum);

    }

    //cout<<sum<<endl;
    if(sum==24)
        cout<<"Yes"<<endl;
      else
          cout<<"No"<<endl;

}


int main(){

  Da b[105];
  int i,num,k;

  cin>>num;//������ʽ������

  for(i=0;i<num;i++)
    cin>>b[i].a1>>b[i].a2>>b[i].a3>>b[i].a4>>b[i].a5>>b[i].a6>>b[i].a7;

  for(i=0;i<num;i++){

    k=Compa(b[i].a2,b[i].a4);//�Ƚ�ǰ2������������ȼ���
    if(k==1){

       b[i].a1=Cal(b[i].a1,b[i].a2,b[i].a3);
        Calculate(b[i].a1,b[i].a4,b[i].a5,b[i].a6,b[i].a7);
    }

    else{

      b[i].a3=Cal(b[i].a3,b[i].a4,b[i].a5);
       Calculate(b[i].a1,b[i].a2,b[i].a3,b[i].a6,b[i].a7);
    }

  }


  return 0;
}
