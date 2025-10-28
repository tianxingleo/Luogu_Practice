/*
这是一个欧拉筛算法的实现
*/

#include<stdio.h>
#include<stdbool.h>
int main(){
    int N;
    scanf("%d",&N);
    bool zhishu[N+1];
    int zhishu_1[N+1];
    int C=0;
    for (int i=0;i<=N;i++){
        zhishu[i]=1;
    }
    for (int i=0;i<=N;i++){
        zhishu_1[i]=0;
    }
    for(int i=2;i<=N;i++){

        if(zhishu[i]==1){
            zhishu_1[C]=i;
            C++;
        }

        for(int j=0;zhishu_1[j]!=0&&zhishu_1[j]*i<=N;j++){
            zhishu[i*zhishu_1[j]]=0;
            if(i%zhishu_1[j]==0){
                break;
            }
        }



        /*
        for (int j=2;j<=i&&i*j<=N;j++){
        
            
            if (zhishu[j]==1){
                zhishu[i*j]=0;
            }
            if (i%j==0){
                break;
            }
               
        } */
    }
    int sum=0;
    for (int i=0;zhishu_1[i]!=0;i++){
        printf("%d\n",zhishu_1[i]);
        sum++;
    }
    printf("%d",sum);

    return 0;
}