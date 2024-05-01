#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{
    int point;//表示小球的位置。
    int lr;//小球运动的方向，1-向右；0-向左。
}ball;


ball *func(ball *ba,int length){//是否有球相撞。
 int r,s;

 for(r=0;r<length;r++)
   for(s=r+1;s<length;s++){
      if(ba[r].point==ba[s].point){//出现2球相撞。

               ba[r].lr=1-ba[r].lr;
               ba[s].lr=1-ba[s].lr;
      }
   }

 return ba;
}


int main(){

 int i,j,k,n,L,t;//n-小球个数 L-线段长度，t-需要经过的时间
// ball a[101];
 cin>>n>>L>>t;
 ball*a=(ball*)calloc(n+1,sizeof(ball));


 for(i=0;i<n;i++){
    cin>>a[i].point;//输入小球起始位置。
    a[i].lr=1;//一开始所有小球都是向右运动
 }
//要处理碰撞，不是只有移动！！！！！
 for(i=0;i<t;i++){
    for(j=0;j<n;j++){

      if(a[j].point==0){//小球遇到了左端点。
            if(a[j].lr==0){//在原点向左运动
               a[j].lr=1-a[j].lr;
                a[j].point=a[j].point+1;
            }
            else//在原点向右运动
                a[j].point=a[j].point+1;

        }

          else if(a[j].point==L){//小球遇到了右端点，会转向左，同时位置减1.
                if(a[j].lr==1){//在终点向右运动
                   a[j].lr=1-a[j].lr;
                   a[j].point=a[j].point-1;
                }
                else//在终点向左运动
                   a[j].point=a[j].point-1;

          }

             else{//小球在区间中间位置。
                 if(a[j].lr==0)//向左运动中
                    a[j].point=a[j].point-1;

                 else//向右运动中
                    a[j].point=a[j].point+1;//运动时遇到了端点就要开始变方向。

             }
     }

      a=func(a,n);


  }

  for(k=0;k<n;k++)
    cout<<a[k].point<<" ";

  return 0;
}
