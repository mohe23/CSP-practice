#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;



int main()
{
 int i1,n1,x,y,c,d1,d2;
 double **b;
 scanf("%d %d %d",&n1,&x,&y);
 //printf("\n");


 //a1=(int**)calloc(n1,sizeof(int));
 b=(double**)calloc(n1,sizeof(double));
 for(i1=0;i1<n1;i1++)
 {
  //a1[i1]=(int*)calloc(2,sizeof(int));
  b[i1]=(double*)calloc(2,sizeof(double));
 }

 for(i1=0;i1<n1;i1++)
 {
     scanf("%d %d",&d1,&d2);
  //printf("\n");
   c=(x-d1)*(x-d1)+(y-d2)*(y-d2);
    b[i1][0]=i1+1;
    b[i1][1]=c;
 }


 b=Func(b,n1);

 for(i1=0;i1<3;i1++)
 printf("%d\n",b[i1][0]);

 return 0;

}
