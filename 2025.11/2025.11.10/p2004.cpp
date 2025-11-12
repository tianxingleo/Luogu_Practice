#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,C;
    cin>>N>>M>>C;
    vector<vector<int>>each(N+1,vector<int>(M+1,0));
    vector<vector<int>>sum_each(N+1,vector<int>(M+1,0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>each[i][j];
            if(i==1&&j==1)sum_each[1][1]=each[1][1];
            else{
                sum_each[i][j]=sum_each[i-1][j]+sum_each[i][j-1]-sum_each[i-1][j-1]+each[i][j];
            }
        }
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=M;j++){
    //         cout<<sum_each[i][j]<<' ';
    //     }cout<<endl;
    // }cout<<endl;
    int max=sum_each[C][C];
    int temp=0;
    int max_x=1,max_y=1;
    vector<vector<int>>sum_each_1(N+1,vector<int>(M+1,0));

    for(int i=1;i<=N+1-C;i++){
        for(int j=1;j<=M+1-C;j++){
            temp=(sum_each[i+C-1][j+C-1]-sum_each[i+C-1][j-1]-sum_each[i-1][j+C-1]+sum_each[i-1][j-1]);
            if(max<temp){
                max=temp;
                max_x=i;
                max_y=j;
            }
            //cout<<sum_each[i+C-1][i+C-1]<<" "<<sum_each[i+C-1][j-1]<<" "<<sum_each[i-1][j+C-1]<<" "<<sum_each[i-1][j-1]<<endl;
            sum_each_1[i][j]=temp;
        }
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=M;j++){
    //         cout<<sum_each_1[i][j]<<' ';
    //     }cout<<endl;
    // }cout<<endl;
    cout<<max_x<<' '<<max_y;

}