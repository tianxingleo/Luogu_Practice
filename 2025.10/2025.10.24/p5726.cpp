/*

题目描述
现在有 n(n≤1000) 位评委给选手打分，分值从 0 到 10。需要去掉一个最高分，去掉一个最低分（如果有多个最高或者最低分，也只需要去掉一个），剩下的评分的平均数就是这位选手的得分。现在输入评委人数和他们的打分，请输出选手的最后得分，精确到 2 位小数。

输入格式
第一行输入一个正整数 n，表示有 n 个评委。

第二行输入 n 个正整数，第 i 个正整数表示第 i 个评委打出的分值。

输出格式
输出一行一个两位小数，表示选手的最后得分。


*/



#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> rank(n);
    for (int i=0;i<=n-1;i++){
        cin>>rank[i];
    }
    int min=rank[0];
    int max=rank[0];

    for(int i=1;i<=n-1;i++){
        if(min>rank[i]){
            min=rank[i];
        }
    }
    
    for(int i=0;i<=n-1;i++){
        if(max<rank[i]){
            max=rank[i];
        }
    }
    for(int i=0;i<=n-1;i++){
        if(rank[i]==min){
            rank[i]=0;
            break;
        }
    }
    for(int i=0;i<=n-1;i++){
        if(rank[i]==max){
            rank[i]=0;
            break;
        }
    }
    int sum=0;
    for(int i=0;i<=n-1;i++){
        sum=sum+rank[i];
    }
    float rank_1=float(sum)/float(n-2);
    printf("%.2f",rank_1);


    return 0;
}