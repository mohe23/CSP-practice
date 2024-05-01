#include<iostream>
using namespace std;


int main(){

 int i,j,n,a[1001],sum=0;
 int s1=0,s2=0,t,k=-1;
    cin>>n;//整数数量

    for(i=0;i<n;i++)
        cin>>a[i];//输入整数。

    for(i=0;i<n;i++){
        t=a[i];
        //cout<<t<<" ";
        for(j=0;j<n;j++){
            if(a[j]>t)
                s1=s1+1;
            else if(a[j]<t)
                s2=s2+1;
            else
                continue;
        }
      //cout<<s1<<" "<<s2<<endl;
      if((s1!=0)&&(s2!=0)&&(s1==s2)){
            k=t;
            break;
      }
      else{

        s1=0;
        s2=0;


      }
    }


    for(i=0;i<n;i++)
        sum=sum+a[i];

    if(sum==a[0]*n)
        k=a[0];

 cout<<k<<endl;
 return 0;

}
