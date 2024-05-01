#include<iostream>
using namespace std;

typedef struct{

  int tbegin;//装车开始时间
  int tend;//装车结束时间

}Time;

Time a[2001],b[2001];

int Is(int t1,int t2,int t3,int t4){//判断时间段[t1,t2]与[t3,t4]是否有重叠。
    int l1,l2,key;

    if(t1<=t3){
        l1=t1;
        l2=t2;

        if(l2>t3)
            key=1;
        else
            key=0;
    }
    else{
          l1=t3;
          l2=t4;

          if(l2>t1)
            key=1;
          else
            key=0;
    }

   return key;
}

一般csp第2题需要   2个for     循环才能解决。
int main(){

int i,j,n,s1,s2,k;
long long sum=0;

cin>>n;

   for(i=0;i<n;i++)
    cin>>a[i].tbegin>>a[i].tend;

   for(i=0;i<n;i++)
    cin>>b[i].tbegin>>b[i].tend;
//判断2个时间段是否有交叉。但是不一定是一对一的，拿a的每1个时间段与b的每1个时间段比较。
   for(i=0;i<n;i++){
      for(j=0;j<n;j++){

        k=Is(a[i].tbegin,a[i].tend,b[j].tbegin,b[j].tend);
        if(k==1){//2个时间段有交叉

              if(a[i].tbegin<b[j].tbegin)//a的开始时间<b的开始时间，取b
                s1=b[j].tbegin;
              else//a的开始时间>=b的开始时间，取a
                s1=a[i].tbegin;

              if(a[i].tend>b[j].tend)//a的结束时间>b的结束时间，取b
                s2=b[j].tend;
              else//a的结束时间<=b的结束时间，取a
                 s2=a[i].tend;

              sum=sum+s2-s1;
           }
       else
         sum=sum+0;

      }


   }

   cout<<sum<<endl;

   return 0;
}
