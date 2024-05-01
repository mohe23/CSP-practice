#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{

  int k;//标识红绿灯
  int t;//
}road;


int main(){

 int i,r,y,g,sum,s=0;
 cin>>r>>y>>g;
 cin>>sum;

 road*d=(road*)calloc(sum,sizeof(road));
 for(i=0;i<sum;i++)
    cin>>d[i].k>>d[i].t;

 for(i=0;i<sum;i++){
     if(d[i].k==0)//通过路口,
          s=s+d[i].t;
      else if(d[i].k==1)//遇到红灯
             s=s+d[i].t;
         else if(d[i].k==2)//遇到黄灯，这里注意，因为黄灯过后是红灯，所以要再额外加上红灯时间。
               s=s+d[i].t+r;
            else
                continue;

 }

 cout<<s;

 return 0;
}
