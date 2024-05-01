#include<iostream>
using namespace std;


int Mos(int num)
{
  int a,b,c,key;
  a=num/100;
  b=(num-a*100)/10;
  c=num%10;

  if(((num%7)==0)||(a==7)||(b==7)||(c==7))
       key=1;
  else
      key=0;

  return key;
}


int main()
{
  int k,ke,n=1,sum=1,x1,x2,x3,x4;//x1,x2,x3,x4是甲乙丙丁跳过的次数。
  x1=0;
  x2=0;
  x3=0;
  x4=0;

  cin>>k;

  while(sum<=k)//计数没有超过k
  {
    ke=Mos(n);
    if(ke==1)//只要计数到了7或者7的倍数。
    {
        //cout<<n<<endl;
        if((n%4)==1)
            x1=x1+1;//甲跳过次数加1.
        else if((n%4)==2)
            x2=x2+1;//乙跳过次数加1.
        else if((n%4)==3)
            x3=x3+1;//丙跳过次数加1.
        else
            x4=x4+1;//丁跳过次数加1.

        sum=sum;//只要报数到7或者7的倍数，不计数。
    }

    else
     sum=sum+1;

    n=n+1;
  }

  cout<<x1<<endl;
  cout<<x2<<endl;
  cout<<x3<<endl;
  cout<<x4<<endl;

  return 0;
}
