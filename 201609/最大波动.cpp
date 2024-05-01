#include<iostream>
#include<cmath>
using namespace std;

int main(){

  int i,n,t,maxs=0,a[1001];
  cin>>n;

  for(i=0;i<n;i++)
    cin>>a[i];

  for(i=0;i<n-1;i++){

     t=abs(a[i]-a[i+1]);

     if(t>maxs)
        maxs=t;
  }

  cout<<maxs<<endl;

  return 0;
}
