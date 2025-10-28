/*

题目背景
NOIp2015 提高组 Day1T1

题目描述
幻方是一种很神奇的 N×N 矩阵：它由数字 1,2,3,⋯⋯,N×N 构成，且每行、每列及两条对角线上的数字之和都相同。

当 N 为奇数时，我们可以通过下方法构建一个幻方：

首先将 1 写在第一行的中间。

之后，按如下方式从小到大依次填写每个数 K (K=2,3,⋯,N×N) ：

若 (K−1) 在第一行但不在最后一列，则将 K 填在最后一行， (K−1) 所在列的右一列；
若 (K−1) 在最后一列但不在第一行，则将 K 填在第一列， (K−1) 所在行的上一行；
若 (K−1) 在第一行最后一列，则将 K 填在 (K−1) 的正下方；
若 (K−1) 既不在第一行，也不在最后一列，如果 (K−1) 的右上方还未填数，则将 K 填在 (K−1) 的右上方，否则将 K 填在 (K−1) 的正下方。
现给定 N ，请按上述方法构造 N×N 的幻方。

输入格式
一个正整数 N，即幻方的大小。

输出格式
共 N 行，每行 N 个整数，即按上述方法构造出的 N×N 的幻方，相邻两个整数之间用单空格隔开。

*/

#include<iostream>
#include<vector>

using namespace std;
int main(){
    int N;
    cin>>N;
    vector<vector<int>>juzhen(N+1,vector<int>(N+1,0));
    int address[3]={0,1,N/2+1};
    juzhen[1][N/2+1]=1;
    for(int i=2;i<=N*N;i++){
        if (address[1]==1&&address[2]!=N){
            juzhen[N][address[2]+1]=i;
            address[1]=N;
            address[2]=address[2]+1;
        }else if(address[2]==N&&address[1]!=1){
            juzhen[address[1]-1][1]=i;
            address[1]=address[1]-1;
            address[2]=1;
        }else if(address[1]==1&&address[2]==N){
            juzhen[2][N]=i;
            address[1]=2;
            address[2]=N;
        }else{
            if(juzhen[address[1]-1][address[2]+1]==0){
                juzhen[address[1]-1][address[2]+1]=i;
                address[1]=address[1]-1;
                address[2]=address[2]+1;
            }else{
                juzhen[address[1]+1][address[2]]=i;
                address[1]=address[1]+1;
                address[2]=address[2];
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<juzhen[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;


}