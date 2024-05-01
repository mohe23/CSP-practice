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


int*getm(key *k1,int len,int *a,int value,int num){//返回begintime或endtime等于value的对应的钥匙编号，
                                                            //数组c存放的是钥匙的排列位置。
    int i,t;
   // a[0]=0;//表示begintime/endtime等于value的钥匙数量。
    if(num==1){//返回begintime==value的教师拿的钥匙编号。
        for(i=0;i<len;i++){
            if((k1[i].counts==0)&&(k1[i].begintime==value)){//只处理还未上课的老师。

                k1[i].counts=k1[i].counts+1;//取到了该钥匙。
                a[0]=a[0]+1;
                t=a[0];
                a[t]=k1[i].number;
                 cout<<"t:"<<t<<endl;
                cout<<k1[i].number<<endl;
            }
            else
                continue;
        }
    }

    if(num==0){//返回endtime==value的教师拿的钥匙编号。num==0
       for(i=0;i<len;i++){
            if((k1[i].counts==1)&&(k1[i].endtime==value)){//只有老师已经开始上课了，
                k1[i].counts=k1[i].counts+1;//返还这个钥匙。
                a[0]=a[0]+1;
                t=a[0];
                a[t]=k1[i].number;
                cout<<"t:"<<t<<endl;
                cout<<k1[i].number<<endl;
            }
            else
                continue;
        }
    }

 return a;

}


int main(){

  int i;
  int*a=(int*)calloc(5,sizeof(int));
  key*k=(key*)calloc(4,sizeof(key));

 for(i=0;i<5;i++)
    a[i]=0;

  k[0].number=2;
  k[0].begintime=1;
  k[0].consist=3;
  k[0].endtime=4;
  k[0].counts=0;

  k[1].number=4;
  k[1].begintime=1;
  k[1].consist=4;
  k[1].endtime=6;
  k[1].counts=0;

  k[2].number=3;
  k[2].begintime=1;
  k[2].consist=2;
  k[2].endtime=5;
  k[2].counts=0;

  k[3].number=1;
  k[3].begintime=1;
  k[3].consist=3;
  k[3].endtime=5;
  k[3].counts=0;


  a=getm(k,4,a,1,0);

  if(a[0]>0){
    for(i=1;i<a[0];i++)
        cout<<a[i]<<endl;
  }
  else
    cout<<a[0]<<" "<<"无数据元素"<<endl;

  //a[0]=23;
  //a[1]=2;
  //a[2]=31;
  //a[3]=7;

  //int con1=getorder(a,4,31);
  //int con2=getorder(a,4,33);

  //cout<<con1<<endl<<con2<<endl;
  return 0;
}
