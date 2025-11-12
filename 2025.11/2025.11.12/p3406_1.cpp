// # P3406 海底高铁

// ## 题目描述

// 该铁路经过 $N$ 个城市，每个城市都有一个站。不过，由于各个城市之间不能协调好，于是乘车每经过两个相邻的城市之间（方向不限），必须单独购买这一小段的车票。第 $i$ 段铁路连接了城市 $i$ 和城市 $i+1(1\leq i<N)$。如果搭乘的比较远，需要购买多张车票。第 $i$ 段铁路购买纸质单程票需要 $A_i$ 博艾元。

// 虽然一些事情没有协调好，各段铁路公司也为了方便乘客，推出了 IC 卡。对于第 $i$ 段铁路，需要花 $C_i$ 博艾元的工本费购买一张 IC 卡，然后乘坐这段铁路一次就只要扣 $B_i(B_i<A_i)$ 元。IC 卡可以提前购买，有钱就可以从网上买得到，而不需要亲自去对应的城市购买。工本费不能退，也不能购买车票。每张卡都可以充值任意数额。对于第 $i$ 段铁路的 IC 卡，无法乘坐别的铁路的车。

// Uim 现在需要出差，要去 $M$ 个城市，从城市 $P_1$ 出发分别按照 $P_1,P_2,P_3,\cdots,P_M$ 的顺序访问各个城市，可能会多次访问一个城市，且相邻访问的城市位置不一定相邻，而且不会是同一个城市。

// 现在他希望知道，出差结束后，至少会花掉多少的钱，包括购买纸质车票、买卡和充值的总费用。

// ## 输入格式

// 第一行两个整数，$N,M$。

// 接下来一行，$M$ 个数字，表示 $P_i$。

// 接下来 $N-1$ 行，表示第 $i$ 段铁路的 $A_i,B_i,C_i$。

// ## 输出格式

// 一个整数，表示最少花费

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 9 10
// 3 1 4 1 5 9 2 6 5 3
// 200 100 50
// 300 299 100
// 500 200 500
// 345 234 123
// 100 50 100
// 600 100 1
// 450 400 80
// 2 1 10
// ```

// ### 输出 #1

// ```
// 6394
// ```

// ## 说明/提示

// $2$ 到 $3$ 以及 $8$ 到 $9$ 买票，其余买卡。

// 对于 $30\%$ 数据 $M=2$。

// 对于另外 $30\%$ 数据 $N\leq1000，M\leq1000$。

// 对于 $100\%$ 的数据 $M,N\leq 10^5，A_i,B_i,C_i\le10^5$。


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>ticket(1,vector<int>(4,0));


int main(){
    int M,N;
    cin>>N>>M;
    vector<int>destination(M,0);
    vector<long long>destination_sum(N,0);

    for(int i=0;i<=M-1;i++){
        cin>>destination[i];
    }
    ticket.resize(N, vector<int>(4, 0));
    
    for(int i=0;i<=N-2;i++){
        for(int j=1;j<=3;j++){
            cin>>ticket[i][j];
        }
    }

    //计算每一段路经过的次数
    for(int i=0;i<=M-2;i++){
        if(destination[i+1]-destination[i]<0){
            for(int j=destination[i]-1-1;j>=destination[i+1]-1;j--){
                destination_sum[j]++;
            }
        }else if(destination[i+1]-destination[i]>0){
            for(int j=destination[i]-1;j<destination[i+1]-1;j++){
                destination_sum[j]++;
            }
        }
        
    }

    //计算是否需要买ic卡
    vector<bool> ic(N-1,0);
    for(int i=0;i<N-1;i++){
        if(ticket[i][1]*destination_sum[i]>(ticket[i][3]+ticket[i][2]*destination_sum[i])){
            ic[i]=1;
        }
    }

    //计算总共花的钱
    long long sum=0;
    for(int i=0;i<=N-2;i++){
        if(ic[i]==0){
            sum+=ticket[i][1]*destination_sum[i];
        }else if(ic[i]==1){
            sum+=ticket[i][3]+ticket[i][2]*destination_sum[i];
        }
    }
    cout<<sum;
    return 0;
}