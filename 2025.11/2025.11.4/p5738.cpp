// 题目描述
// n(n≤100) 名同学参加歌唱比赛，并接受 m(m≤20) 名评委的评分，评分范围是 0 到 10 分。这名同学的得分就是这些评委给分中去掉一个最高分，去掉一个最低分，剩下 m−2 个评分的平均数。请问得分最高的同学分数是多少？评分保留 2 位小数。

// 输入格式
// 第一行两个整数 n,m。
// 接下来 n 行，每行各 m 个整数，表示得分。

// 输出格式
// 输出分数最高的同学的分数，保留两位小数。

#include <bits/stdc++.h>
#include <iterator>
using namespace std;

float solve(vector<float>&rank,int m){
    for(int i=0;i<=m-1;i++){
        cin>>rank[i];
    }
    int max=distance(rank.begin(),find(rank.begin(),rank.end(),*max_element(rank.begin(), rank.end())));
    int min=distance(rank.begin(),find(rank.begin(),rank.end(),*min_element(rank.begin(), rank.end())));
    rank[max]=0;
    rank[min]=0;
    float sum=0;
    for(int i=0;i<=m-1;i++){
        sum+=rank[i];
    }
    return sum/(m-2);
}

int main(){
    int m,n;
    cin>>n>>m;
    vector<vector<float>>rank(n,vector<float>(m,0));
    vector<float>last;
    for(float i=0;i<=n-1;i++){
        last.push_back(solve(rank[i],m));
    }
    printf("%.2f",*max_element(last.begin(), last.end()));
    return 0;
}