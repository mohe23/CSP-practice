#include<iostream>
using namespace std;


int po(int t,int s){//ȡt��s��ֵ�ľ���ֵ��
    int q;
    q=t-s;
    if(q<0)
        q=-q;
    else
        q=q;

    return q;
}


int main(){

  int i,j,n,m,minum=10001;
  int a[1001];

     cin>>n;//������������
     for(i=0;i<n;i++)
      cin>>a[i];//����n������

      for(i=0;i<n;i++)
      for(j=i+1;j<n;j++){
         m=po(a[i],a[j]);//ȡ����ֵ��
         if(m<minum)
            minum=m;
      }

  cout<<minum<<endl;

  return 0;
}
