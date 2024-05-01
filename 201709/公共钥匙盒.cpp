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


int getorder(int *d,int lens,int nums){//返回标号nums值所在的数组的序号。lens是数组d的长度。
     int i,s2=-1;
     for(i=0;i<lens;i++){
        if(d[i]==nums){
            s2=i;
            break;
        }
     }
  return s2;
}



int**getm(key *k1,int len,int **a,int value,int num){//返回begintime或endtime等于value的对应的钥匙编号，
                                                            //数组c存放的是钥匙的排列位置。
    int i;
    a[0][0]=0;//表示begintime/endtime等于value的钥匙数量。
    if(num==1){//返回begintime==value的教师拿的钥匙编号。
        for(i=0;i<len;i++){
            if((k1[i].counts==0)&&(k1[i].begintime==value)){//只处理还未上课的老师。

                a[0][0]=a[0][0]+1;
                a[a[0][0]][0]=k1[i].number;//存储钥匙序号
                a[a[0][0]][1]=i;//存储教师的序号
            }
        }
    }
    else{//返回endtime==value的教师拿的钥匙编号。num==0
       for(i=0;i<len;i++){
            if((k1[i].counts==1)&&(k1[i].endtime==value)){//只有老师已经开始上课了，
                //k1[i].counts=k1[i].counts+1;//返还这个钥匙。
                a[0][0]=a[0][0]+1;
                a[a[0][0]][0]=k1[i].number;//存储钥匙序号
                a[a[0][0]][1]=i;//存储教师的序号
            }
        }
    }

 return a;

}


int** uporder(int **b){//将数组b按照标号大小升序排列。b[0]中存放数组元素个数。

   int i,j,s1,s3;

   if(b[0][0]>1){
       for(i=1;i<=b[0][0];i++){
         for(j=i+1;j<=b[0][0];j++){
            if(b[i][0]>b[j][0]){
               s1=b[i][0];//钥匙编号
               s3=b[i][1];//老师序号
               b[i][0]=b[j][0];
               b[i][1]=b[j][1];
               b[j][0]=s1;
               b[j][1]=s3;
           }
        }
       }
    }


  return b;
}


int*getlist(key *k,int *li,int lengs){//获得开始与结束所有的时间点。

   int i,j,t,flag=0;//flag用来标记当前数字是否与当前数组中元素相同，若相同，为1；不同，则为0
   li[0]=0;
   for(i=0;i<lengs;i++){
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

 int i,j,N,K,sum,order,x1;
 cin>>N>>K;//输入教室数量，老师人数。


 key*k=(key*)calloc(K,sizeof(key));//代表每1位老师。
 int*n=(int*)calloc(N,sizeof(int));//存放N个钥匙的最终位置，一开始的顺序是1~N。
 int*f=(int*)calloc(2*K+1,sizeof(int));//存放时间点。

   int**b=(int**)calloc(N+1,sizeof(int));//存放begintime等于value值的钥匙标号。
   int**e=(int**)calloc(N+1,sizeof(int));//存放endtime等于value值的钥匙标号。

     for(i=0;i<N+1;i++){//注意2维数组的相关数量的编写
         b[i]=(int*)calloc(2,sizeof(int));
         e[i]=(int*)calloc(2,sizeof(int));
     }

     for(i=0;i<N;i++)
        n[i]=i+1;//一开始钥匙按照从左至右从1~N。

    for(i=0;i<K;i++){
         cin>>k[i].number>>k[i].begintime>>k[i].consist;
        k[i].endtime=k[i].begintime+k[i].consist;//计算返还钥匙时间。
        k[i].counts=0;
    }

    f=getlist(k,f,K);


    for(sum=1;sum<=f[0];sum++){//只要还有1个老师没有上完课
      b=getm(k,K,b,f[sum],1);//begintime==time.
      e=getm(k,K,e,f[sum],0);//endtime==time。

      if((b[0][0]!=0)&&(e[0][0]==0)){//有取钥匙的，没有还钥匙的
          //cout<<"有取钥匙的，没有还钥匙的"<<endl;
        for(i=1;i<=b[0][0];i++){
            order=getorder(n,N,b[i][0]);//根据钥匙号，找出它在位置数组中的位置。
            //cout<<"!= ==  "<<order<<" "<<b[1][0]<<endl;
            n[order]=0;//取该钥匙，该钥匙在数组中位置对应的值为0。
            k[b[i][1]].counts=k[b[i][1]].counts+1;//该老师取到了钥匙。

        }     //k[i].couts应该是在这里设置的
      }
       else if((b[0][0]==0)&&(e[0][0]!=0)){//只有返钥匙的，没有取钥匙的
          //cout<<"只有返钥匙的，没有取钥匙的"<<endl;
            e=uporder(e);//按照钥匙序号升序排列
          for(i=1;i<=e[0][0];i++){
            for(j=0;j<N;j++){
                if(n[j]==0){//该位置为空，则将该位置的元素值置为钥匙编号
                  n[j]=e[i][0];//注意这是还钥匙，是数组e。
                  k[e[i][1]].counts=k[e[i][1]].counts+1;//该老师完成上课，还钥匙。
                  break;
                }
            }
          }

       }
      else if((b[0][0]!=0)&&(e[0][0]!=0)){//既有取钥匙的，又有还钥匙的。这个时候，先还钥匙，再取钥匙
        // cout<<"既有取钥匙的，又有还钥匙的"<<endl;
         e=uporder(e);//按照钥匙序号升序排列
         for(i=1;i<=e[0][0];i++){//先还钥匙。
            for(j=0;j<N;j++){
                if(n[j]==0){//该位置为空，则将该位置的元素值置为钥匙编号
                  n[j]=e[i][0];//注意这是还钥匙，是数组e。
                  k[e[i][1]].counts=k[e[i][1]].counts+1;//该老师完成上课，还钥匙。
                  break;
                }
            }
          }

         for(i=1;i<=b[0][0];i++){//再取钥匙
            order=getorder(n,N,b[i][0]);//根据钥匙号，找出它在位置数组中的位置。
            n[order]=0;//取该钥匙，该钥匙在数组中位置对应的值为0。
             k[b[i][1]].counts=k[b[i][1]].counts+1;//该老师取到了钥匙。
         }
      }

      else//这个时间点没有取钥匙的，也没有还钥匙的。
         x1=0;

  }

for(i=0;i<N;i++)
    cout<<n[i]<<" ";

 return 0;
}
