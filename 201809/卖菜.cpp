#include<iostream>
using namespace std;

int main(){

int i,n,s,d[1001],t[1001];
 cin>>n;//���������
 for(i=0;i<n;i++)
    cin>>d[i];//��������ÿ����ҵĵ�1�ζ���

 for(i=0;i<n;i++){
    if(i==0)
      s=(d[i]+d[i+1])/2;//���1�����ڵ�ֻ�е�2�ҡ�ȥβ����ȡ��
    else if(i==n-1)
        s=(d[i-1]+d[i])/2;//���n������ֻ�е�n-1�ҡ�
    else
        s=(d[i-1]+d[i]+d[i+1])/3;//���������ڵ����������ҡ�

    t[i]=s;
 }

  for(i=0;i<n;i++)
    cout<<t[i]<<" ";

 return 0;

}
