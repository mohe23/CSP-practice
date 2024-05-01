#include<stdio.h>
#include<stdlib.h>

float a[100006];
int main()
{
  int i,n;
  int k;
  int s1;
  float s2;
  float  g;
  float t[3];
  scanf("%d",&n);

   for(i=0;i<n;i++)
    scanf("%f",&a[i]);

  if(n%2==0)//表示数据总数是偶数。
  {
    k=n/2;
    t[0]=a[0];
    t[1]=(a[k-1]+a[k])/2;
    t[2]=a[n-1];
  }

  else
  {
    k=n/2;
    t[0]=a[0];
    t[1]=a[k];
    t[2]=a[n-1];
  }

  if(t[0]<t[2])//这个就是原数据升序排列的
  {
      g=t[0];
      t[0]=t[2];
      t[2]=g;
  }


s1=(int)(t[1]);
s2=t[1]-s1;

  if(s2!=0)
     printf("%.0f %.1f %.0f\n",t[0],t[1],t[2]);
  else
     printf("%.0f %.0f %.0f\n",t[0],t[1],t[2]);

  return 0;
}
