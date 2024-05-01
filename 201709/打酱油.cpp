#include<iostream>
using namespace std;

int main(){

  int i,j,N,n,sum=0;
  int a[10][3],b[10];//a*5+b*3+c=n;每1行存放的是a,b,c三个系数。还有每次计算的总瓶数。
  cin>>N;//输入总钱数,N是10的倍数。
  n=N/10;//变简单一些。

  for(i=0;i*5<=n;i++){

    a[i][0]=i;//存放5前面的系数。每1个数代表7瓶
    a[i][1]=(n-i*5)/3;//存放3前面的系数。每1个数代表4瓶
    a[i][2]=(n-i*5)%3;//存放单独买的酱油数。
    b[i]=a[i][0]*7+a[i][1]*4+a[i][2];//每1次的总瓶数。
    //cout<<b[i]<<endl;
  }

  i=i-1;//此时i比最大的值大1，所以减去1；如果不减去1，那么就会出现错误。这个是下面的循环条件为“<=”

  for(j=0;j<=i;j++){//找最大瓶数，

    if(b[j]>sum)
        sum=b[j];
  }


  cout<<sum<<endl;

  return 0;
}
