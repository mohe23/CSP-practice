#include<iostream>
using namespace std;

int main(){

int i,a[31],b[31],n=0;//b[31]存放的是每一次的得分。
long long sum=0;

//for(i=0;i<31;i++)
    //a[i]=3;//置初值，区别1,2,0。

for(i=0;i<31;i++){
    cin>>a[i];


    if(a[i]==0)
        break;
    else
        continue;

      n=n+1;
}


for(i=0;i<31;i++){
    if(a[i]==1){//跳到了方块上，但是没有跳到中心上。
        sum=sum+1;
        b[i]=1;
    }
    else if(a[i]==2){//跳到了方块中心。
        if(i==0){//第1块跳到了中心。
             sum=sum+2;
             b[i]=2;
            }

        else{//第n块跳在方块中心。
              if(b[i-1]==1){//前1块得分为1分，这次得2分
                sum=sum+2;
                b[i]=2;
              }
              else{//前1块得分为2分，这次得分是前1次得分加2分

                sum=sum+b[i-1]+2;
                b[i]=b[i-1]+2;
              }
            }
          }

       else{//如果遇到数字0，跳出循环。

        b[i]=0;
        break;
       }
    }

  cout<<sum<<endl;
    return 0;
}





