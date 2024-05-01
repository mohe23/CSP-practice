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


int Compa(char c1,char c2){//比较c1,c2的优先级，如果c1>c2,返回1；否则返回0。

   int t=1;

   if(((c1=='+')||(c1=='-'))&&((c2=='x')||(c2=='/')))
            t=0;

  return t;
}


int Cal(int m1,char m2,int m3){//计算该表达式值。

    int s;
    if(m2=='+')//加法
        s=m1+m3;
      else if(m2=='-')//减法
          s=m1-m3;
        else if(m2=='x')//乘法
            s=m1*m3;
          else //除法
             s=m1/m3;

    return s;
}


void Calculate(int n1,char h2,int n3,char h4,int n5){//判断表达式是否是24点，如果是，打印Yes；否则打印No .
    int r,sum;

    //cout<<n1<<" "<<h2<<" "<<n3<<" "<<h4<<" "<<n5<<endl;
    r=Compa(h2,h4);//比较运算符的优先级。
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

  cin>>num;//输入表达式总数。

  for(i=0;i<num;i++)
    cin>>b[i].a1>>b[i].a2>>b[i].a3>>b[i].a4>>b[i].a5>>b[i].a6>>b[i].a7;

  for(i=0;i<num;i++){

    k=Compa(b[i].a2,b[i].a4);//比较前2个运算符的优先级。
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
