#include<iostream>
#include<stdlib.h>
using namespace std;


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

int main(){


int i,j;
int**a=(int**)calloc(5,sizeof(int));
   for(i=0;i<5;i++)
    a[i]=(int*)calloc(2,sizeof(int));
   a[0][0]=4;

   a[1][0]=12;
   a[1][1]=1;
   a[2][0]=8;
   a[2][1]=2;
   a[3][0]=6;
   a[3][1]=3;
   a[4][0]=1;
   a[4][1]=4;

for(i=1;i<=a[0][0];i++)
    cout<<a[i][0]<<" "<<a[i][1]<<endl;

    cout<<endl;

    a=uporder(a);

for(i=1;i<=a[0][0];i++)
    cout<<a[i][0]<<" "<<a[i][1]<<endl;

return 0;
}
