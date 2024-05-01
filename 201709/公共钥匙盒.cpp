#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{

   int number;//Ҫȡ�õ�Կ�ױ�ţ���1��ʼ��
   int begintime;//ȡԿ��ʱ�䡣
   int consist;//�Ͽ���ʱ��
   int endtime;//��Կ��ʱ�䡣
   int counts;//���������ֵΪ2��˵�������ʦ�Ѿ�����Σ�����Կ���ˡ�
}key;


int getorder(int *d,int lens,int nums){//���ر��numsֵ���ڵ��������š�lens������d�ĳ��ȡ�
     int i,s2=-1;
     for(i=0;i<lens;i++){
        if(d[i]==nums){
            s2=i;
            break;
        }
     }
  return s2;
}



int**getm(key *k1,int len,int **a,int value,int num){//����begintime��endtime����value�Ķ�Ӧ��Կ�ױ�ţ�
                                                            //����c��ŵ���Կ�׵�����λ�á�
    int i;
    a[0][0]=0;//��ʾbegintime/endtime����value��Կ��������
    if(num==1){//����begintime==value�Ľ�ʦ�õ�Կ�ױ�š�
        for(i=0;i<len;i++){
            if((k1[i].counts==0)&&(k1[i].begintime==value)){//ֻ����δ�Ͽε���ʦ��

                a[0][0]=a[0][0]+1;
                a[a[0][0]][0]=k1[i].number;//�洢Կ�����
                a[a[0][0]][1]=i;//�洢��ʦ�����
            }
        }
    }
    else{//����endtime==value�Ľ�ʦ�õ�Կ�ױ�š�num==0
       for(i=0;i<len;i++){
            if((k1[i].counts==1)&&(k1[i].endtime==value)){//ֻ����ʦ�Ѿ���ʼ�Ͽ��ˣ�
                //k1[i].counts=k1[i].counts+1;//�������Կ�ס�
                a[0][0]=a[0][0]+1;
                a[a[0][0]][0]=k1[i].number;//�洢Կ�����
                a[a[0][0]][1]=i;//�洢��ʦ�����
            }
        }
    }

 return a;

}


int** uporder(int **b){//������b���ձ�Ŵ�С�������С�b[0]�д������Ԫ�ظ�����

   int i,j,s1,s3;

   if(b[0][0]>1){
       for(i=1;i<=b[0][0];i++){
         for(j=i+1;j<=b[0][0];j++){
            if(b[i][0]>b[j][0]){
               s1=b[i][0];//Կ�ױ��
               s3=b[i][1];//��ʦ���
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


int*getlist(key *k,int *li,int lengs){//��ÿ�ʼ��������е�ʱ��㡣

   int i,j,t,flag=0;//flag������ǵ�ǰ�����Ƿ��뵱ǰ������Ԫ����ͬ������ͬ��Ϊ1����ͬ����Ϊ0
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
              if(k[i].begintime==li[j]){//���������ͬ�����֣��Ͳ����롣
                  flag=1;//�����ظ������֡�
                  break;
              }
           }
           if(flag==0){
              li[0]=li[0]+1;
               li[li[0]]=k[i].begintime;
           }
           else
              flag=0;//���½�flag��Ϊ0.

            for(j=1;j<=li[0];j++){
              if(k[i].endtime==li[j]){//���������ͬ�����֣��Ͳ����롣
                  flag=1;//�����ظ������֡�
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
      if(li[i]>li[j]){//�������С�
          t=li[i];
          li[i]=li[j];
          li[j]=t;
      }
   }

return li;
}


int main(){

 int i,j,N,K,sum,order,x1;
 cin>>N>>K;//���������������ʦ������


 key*k=(key*)calloc(K,sizeof(key));//����ÿ1λ��ʦ��
 int*n=(int*)calloc(N,sizeof(int));//���N��Կ�׵�����λ�ã�һ��ʼ��˳����1~N��
 int*f=(int*)calloc(2*K+1,sizeof(int));//���ʱ��㡣

   int**b=(int**)calloc(N+1,sizeof(int));//���begintime����valueֵ��Կ�ױ�š�
   int**e=(int**)calloc(N+1,sizeof(int));//���endtime����valueֵ��Կ�ױ�š�

     for(i=0;i<N+1;i++){//ע��2ά�������������ı�д
         b[i]=(int*)calloc(2,sizeof(int));
         e[i]=(int*)calloc(2,sizeof(int));
     }

     for(i=0;i<N;i++)
        n[i]=i+1;//һ��ʼԿ�װ��մ������Ҵ�1~N��

    for(i=0;i<K;i++){
         cin>>k[i].number>>k[i].begintime>>k[i].consist;
        k[i].endtime=k[i].begintime+k[i].consist;//���㷵��Կ��ʱ�䡣
        k[i].counts=0;
    }

    f=getlist(k,f,K);


    for(sum=1;sum<=f[0];sum++){//ֻҪ����1����ʦû�������
      b=getm(k,K,b,f[sum],1);//begintime==time.
      e=getm(k,K,e,f[sum],0);//endtime==time��

      if((b[0][0]!=0)&&(e[0][0]==0)){//��ȡԿ�׵ģ�û�л�Կ�׵�
          //cout<<"��ȡԿ�׵ģ�û�л�Կ�׵�"<<endl;
        for(i=1;i<=b[0][0];i++){
            order=getorder(n,N,b[i][0]);//����Կ�׺ţ��ҳ�����λ�������е�λ�á�
            //cout<<"!= ==  "<<order<<" "<<b[1][0]<<endl;
            n[order]=0;//ȡ��Կ�ף���Կ����������λ�ö�Ӧ��ֵΪ0��
            k[b[i][1]].counts=k[b[i][1]].counts+1;//����ʦȡ����Կ�ס�

        }     //k[i].coutsӦ�������������õ�
      }
       else if((b[0][0]==0)&&(e[0][0]!=0)){//ֻ�з�Կ�׵ģ�û��ȡԿ�׵�
          //cout<<"ֻ�з�Կ�׵ģ�û��ȡԿ�׵�"<<endl;
            e=uporder(e);//����Կ�������������
          for(i=1;i<=e[0][0];i++){
            for(j=0;j<N;j++){
                if(n[j]==0){//��λ��Ϊ�գ��򽫸�λ�õ�Ԫ��ֵ��ΪԿ�ױ��
                  n[j]=e[i][0];//ע�����ǻ�Կ�ף�������e��
                  k[e[i][1]].counts=k[e[i][1]].counts+1;//����ʦ����ϿΣ���Կ�ס�
                  break;
                }
            }
          }

       }
      else if((b[0][0]!=0)&&(e[0][0]!=0)){//����ȡԿ�׵ģ����л�Կ�׵ġ����ʱ���Ȼ�Կ�ף���ȡԿ��
        // cout<<"����ȡԿ�׵ģ����л�Կ�׵�"<<endl;
         e=uporder(e);//����Կ�������������
         for(i=1;i<=e[0][0];i++){//�Ȼ�Կ�ס�
            for(j=0;j<N;j++){
                if(n[j]==0){//��λ��Ϊ�գ��򽫸�λ�õ�Ԫ��ֵ��ΪԿ�ױ��
                  n[j]=e[i][0];//ע�����ǻ�Կ�ף�������e��
                  k[e[i][1]].counts=k[e[i][1]].counts+1;//����ʦ����ϿΣ���Կ�ס�
                  break;
                }
            }
          }

         for(i=1;i<=b[0][0];i++){//��ȡԿ��
            order=getorder(n,N,b[i][0]);//����Կ�׺ţ��ҳ�����λ�������е�λ�á�
            n[order]=0;//ȡ��Կ�ף���Կ����������λ�ö�Ӧ��ֵΪ0��
             k[b[i][1]].counts=k[b[i][1]].counts+1;//����ʦȡ����Կ�ס�
         }
      }

      else//���ʱ���û��ȡԿ�׵ģ�Ҳû�л�Կ�׵ġ�
         x1=0;

  }

for(i=0;i<N;i++)
    cout<<n[i]<<" ";

 return 0;
}
