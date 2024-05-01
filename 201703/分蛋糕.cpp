#include<iostream>
using namespace std;

int main(){

 int i,j,n,k,c=0,sum=0,a[1001];
  cin>>n>>k;//输入蛋糕数，以及指定重量k。

    for(i=0;i<n;i++)
       cin>>a[i];//输入n块蛋糕的重量。

    for(i=0;i<n;){
        sum=sum+a[i];

        if(sum>=k){
          c=c+1;
          sum=0;//将sum重置为0.
          i++;
        }

        else if((sum<k)&&(i!=(n-1)))
                i++;
        else{
           c=c+1;
           i++;
        }

    }

  cout<<c<<endl;
  return 0;
}
