#include<iostream>
#include<stdlib.h>
using namespace std;


int getorder(int*a,int len,int b){//获得学号为b在数组中的下标。

   int i,s;
   for(i=0;i<len;i++){
      if(b==a[i]){
         s=i;
         break;
      }
   }
  return s;
}


int*mov(int*a,int le,int number,int lens){//le是数组a的长度，lens是该学号移动的距离。

    int i,t,s;
    t=getorder(a,le,number);
    s=a[t];//将该学号保留存储。

    if(lens>0){//向后移动！！！
        for(i=t;i<t+lens;i++)
        a[i]=a[i+1];

       a[t+lens]=s;//将该学号移动到指定位置。
    }
    else{//向前移动
       for(i=t;i>t+lens;i--)
            a[i]=a[i-1];

       a[t+lens]=s;
    }

 return a;
}


int main(){

  int i,sum,num,w[1001][2];
  cin>>sum;
  cin>>num;
  for(i=0;i<num;i++)
    cin>>w[i][0]>>w[i][1];

  int*arr=(int*)calloc(sum,sizeof(int));//学生位置数组
   for(i=0;i<sum;i++)
       arr[i]=i+1;//一开始按照学号从左至右排列。


   for(i=0;i<num;i++)
     arr=mov(arr,sum,w[i][0],w[i][1]);

   for(i=0;i<sum;i++)
    cout<<arr[i]<<" ";

 return 0;
}



