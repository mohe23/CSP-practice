#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{

  int id;//编号
  int key;//标记，1-淘汰，0-未淘汰
}child;

int Isk(int number,int k0){//判断数字number是否是k0的倍数或number的个位是否k0，若是，返回1；否则，返回0

   int t1=0,t2=0,r;
      if(number%10==k0)
          t1=1;

      if(number%k0==0)//数字能被k0整除。
         t2=1;

       if(t1+t2>0)//至少1个为1。
           r=1;
       else
           r=0;

return r;
}


int getorder(child *cd,int length){//返回未被淘汰的编号

   int p,d;
   for(p=0;p<length;p++){
         if(cd[p].key!=1){
             d=cd[p].id;
             break;
         }
   }

 return d;
}


int main(){

  int i=1,j,label=0,sum=0,n,k,ke,g;

  cin>>n>>k;

  child *c=(child*)calloc(n,sizeof(child));
    for(j=0;j<n;j++){

       c[j].id=j+1;//n个同学编号从1开始。
       c[j].key=0;//表示未淘汰。
    }

     while(sum!=(n-1)){//只要sum的值不为(n-1)。

          ke=Isk(i,k);//判断数字i是否是k的倍数或者数字i的个位是k。若存在，返回1；否则，返回0
          //cout<<ke<<endl;
          if((ke==1)&&(c[label].key==0)){//该同学未被淘汰，此时轮到了一个淘汰的数字
              c[label].key=1;//被淘汰
              sum=sum+1;
              label=(label+1)%n;
          }

          else if((ke!=1)&&(c[label].key==0)){//该同学未被淘汰，此时轮到了一个不淘汰的数字
               g=c[label].id;
               label=(label+1)%n;
               sum=sum+0;
          }
//轮到淘汰的同学，要看下一个淘汰的同学是否还是被淘汰。
          else if((ke==1)&&(c[label].key==1)){//该同学已被淘汰,此时轮到了一个淘汰的数字。。
               while(c[label].key==1){
                   label=(label+1)%n;
               }
                            //跳过这个同学，就轮到下一个同学淘汰
               c[label].key=1;
             sum=sum+1;
             label=(label+1)%n;
          }
          else{//该同学已被淘汰,此时轮到了一个不淘汰的数字。跳过该同学，轮到了下一个同学。
             while(c[label].key==1){
                label=(label+1)%n;
               }
             //label=(label+1)%n;
             g=c[label].id;
              sum=sum+0;
             label=(label+1)%n;
          }

        i=i+1;
     }

  //g=getorder(c,n);

  cout<<g<<endl;

  //int f=Isk(3,3);

  //cout<<endl<<f<<endl;

}
