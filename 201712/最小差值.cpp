#include<iostream>
using namespace std;


int po(int t,int s){//取t与s差值的绝对值。
    int q;
    q=t-s;
    if(q<0)
        q=-q;
    else
        q=q;

    return q;
}


int main(){

  int i,j,n,m,minum=10001;
  int a[1001];

     cin>>n;//输入整数个数
     for(i=0;i<n;i++)
      cin>>a[i];//输入n个整数

      for(i=0;i<n;i++)
      for(j=i+1;j<n;j++){
         m=po(a[i],a[j]);//取绝对值。
         if(m<minum)
            minum=m;
      }

  cout<<minum<<endl;

  return 0;
}
