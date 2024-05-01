#include<iostream>
using namespace std;

int main(){

int i,n,s,d[1001],t[1001];
 cin>>n;//输入店铺数
 for(i=0;i<n;i++)
    cin>>d[i];//依次输入每个店家的第1次定价

 for(i=0;i<n;i++){
    if(i==0)
      s=(d[i]+d[i+1])/2;//与第1家相邻的只有第2家。去尾法即取整
    else if(i==n-1)
        s=(d[i-1]+d[i])/2;//与第n家相邻只有第n-1家。
    else
        s=(d[i-1]+d[i]+d[i+1])/3;//其他家相邻的是左右两家。

    t[i]=s;
 }

  for(i=0;i<n;i++)
    cout<<t[i]<<" ";

 return 0;

}
