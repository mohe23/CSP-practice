#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{

   int number;//要取用的钥匙编号，从1开始。
   int begintime;//取钥匙时间。
   int consist;//上课用时。
   int endtime;//返钥匙时间。
   int counts;//计数，如果值为2，说明这个老师已经上完课，返回钥匙了。
}key;


int*getlist(key *k,int *li,int lengs){//获得开始与结束所有的时间点。

   int i,j,t,flag=0;//flag用来标记当前数字是否与当前数组中元素相同，若相同，为1；不同，则为0
   li[0]=0;
   for(i=0;i<lengs;i++){
        cout<<"i: "<<i<<endl;
     if(i==0){
           li[0]=li[0]+1;
          li[li[0]]=k[i].begintime;
           li[0]=li[0]+1;
          li[li[0]]=k[i].endtime;        //(k[i].endtime==li[j])
     }
     else{
           for(j=1;j<=li[0];j++){
              if(k[i].begintime==li[j]){//如果出现相同的数字，就不计入。
                  flag=1;//出现重复的数字。
                  break;
              }
           }
           if(flag==0){
              li[0]=li[0]+1;
               li[li[0]]=k[i].begintime;
           }
           else
              flag=0;//重新将flag置为0.

            for(j=1;j<=li[0];j++){
              if(k[i].endtime==li[j]){//如果出现相同的数字，就不计入。
                  flag=1;//出现重复的数字。
                  break;
              }
           }
           if(flag==0){
              li[0]=li[0]+1;
               li[li[0]]=k[i].endtime;
           }
           else
              flag=0;
        }
   }

   for(i=1;i<=li[0];i++)
   for(j=i+1;j<=li[0];j++){
      if(li[i]>li[j]){//升序排列。
          t=li[i];
          li[i]=li[j];
          li[j]=t;
      }
   }

return li;
}


int main(){
    int i;
   int N=5;
  int K=7;

   key*k=(key*)calloc(K,sizeof(key));//代表每1位老师。
   int*n=(int*)calloc(2*K+1,sizeof(int));//存放N个钥匙的最终位置，一开始的顺序是1~N。

  k[0].number=1;
  k[0].begintime=1;
  k[0].consist=14;
  k[0].endtime=15;
  k[0].counts=0;

  k[1].number=3;
  k[1].begintime=3;
  k[1].consist=12;
  k[1].endtime=15;
  k[1].counts=0;

  k[2].number=1;
  k[2].begintime=15;
  k[2].consist=12;
  k[2].endtime=27;
  k[2].counts=0;

  k[3].number=2;
  k[3].begintime=7;
  k[3].consist=20;
  k[3].endtime=27;
  k[3].counts=0;

  k[4].number=3;
  k[4].begintime=18;
  k[4].consist=12;
  k[4].endtime=30;
  k[4].counts=0;

  k[5].number=4;
  k[5].begintime=21;
  k[5].consist=19;
  k[5].endtime=40;
  k[5].counts=0;

  k[6].number=5;
  k[6].begintime=30;
  k[6].consist=9;
  k[6].endtime=39;
  k[6].counts=0;

  int s=sizeof(char);
  cout<<s<<endl;

  n=getlist(k,n,7);

  for(i=1;i<=n[0];i++)
    cout<<n[i]<<" ";


  cout<<endl;

  return 0;
}
