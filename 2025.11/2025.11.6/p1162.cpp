// 题目描述
// 由数字 0 组成的方阵中，有一任意形状的由数字 1 构成的闭合圈。现要求把闭合圈内的所有空间都填写成 2。例如：6×6 的方阵（n=6），涂色前和涂色后的方阵如下：

// 如果从某个 0 出发，只向上下左右 4 个方向移动且仅经过其他 0 的情况下，无法到达方阵的边界，就认为这个 0 在闭合圈内。闭合圈不一定是环形的，可以是任意形状，但保证闭合圈内的 0 是连通的（两两之间可以相互到达）。

// 0 0 0 0 0 0
// 0 0 0 1 1 1
// 0 1 1 0 0 1
// 1 1 0 0 0 1
// 1 0 0 1 0 1
// 1 1 1 1 1 1

// 0 0 0 0 0 0
// 0 0 0 1 1 1
// 0 1 1 2 2 1
// 1 1 2 2 2 1
// 1 2 2 1 2 1
// 1 1 1 1 1 1

// 输入格式
// 每组测试数据第一行一个整数 n(1≤n≤30)。

// 接下来 n 行，由 0 和 1 组成的 n×n 的方阵。

// 方阵内只有一个闭合圈，圈内至少有一个 0。

// 输出格式
// 已经填好数字 2 的完整方阵。

// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>>arr;
// vector<vector<int>>arr_1;
// vector<vector<int>>temp_arr;
// vector<vector<int>>temp_arr_1;

// int n;

// int choose(int idx_1,int idx_2){
//     if(temp_arr[idx_1][idx_2]==1){
//         return 1;
//     }else{
//         temp_arr[idx_1][idx_2]=1;
//     }
    
//     //if(idx_1==n&&idx_2==n)return 0;
//     if(idx_1==n+1||idx_2==n+1||idx_1==0||idx_2==0)return 0;
//     if(arr[idx_1][idx_2]==1)return 1;
//     if(choose(idx_1-1,idx_2)&&choose(idx_1+1,idx_2)&&choose(idx_1,idx_2-1)&&choose(idx_1,idx_2+1)){
//         //arr_1[idx_1][idx_2]=2;
//         return 1;
//     }
//     temp_arr[idx_1][idx_2]=0;
//     return 0;
// }

// int main(){
//     cin>>n;
//     arr.resize(n+1);
//     for(int i=0;i<=n;i++){
//         arr[i].resize(n+1);
//     }
//     temp_arr.resize(n+1);
//     for(int i=0;i<=n;i++){
//         temp_arr[i].resize(n+1);
//     }
//     temp_arr_1=temp_arr;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             cin>>arr[i][j];
//         }
//     }
    
//     arr_1=arr;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             temp_arr=temp_arr_1;
//             if(arr[i][j]==0){if(choose(i,j))arr_1[i][j]=2;}
//         }
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             cout<<arr_1[i][j]<<' ';
//         }cout<<endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>arr;//主数组
vector<vector<int>>arr_1;//储存是否访问
vector<vector<int>>arr_const;//恒定数组

//vector<vector<int>>temp_arr;
//vector<vector<int>>temp_arr_1;

int n;
vector<int> dx={0,0,1,-1};
vector<int> dy={1,-1,0,0};//前后左右

int is_in(int idx,int idy){
    if(idx>=1&&idx<=n&&idy>=1&&idy<=n){
        return 1;
    }else{
        return 0;
    }
}

int bfs(int idx,int idy){
    
    queue<vector<int>> q;//初始化队列
    q.push({idx,idy});
    arr_1[idx][idy]=1;
    while(!q.empty()){
        vector<int> temp_arr=q.front();
        q.pop();

        if(is_in(temp_arr[0],temp_arr[1])){
            for(int i=0;i<=3;i++){
                if(is_in(temp_arr[0]+dx[i],temp_arr[1]+dy[i])&&arr_1[temp_arr[0]+dx[i]][temp_arr[1]+dy[i]]==0){
                    q.push({temp_arr[0]+dx[i],temp_arr[1]+dy[i]});
                    arr_1[temp_arr[0]+dx[i]][temp_arr[1]+dy[i]]=1;
                }else if(is_in(temp_arr[0]+dx[i],temp_arr[1]+dy[i])==0){
                    return 0;
                }
            }
        }
        
        // for(int i=1;i<=n;i++){//输出数组
        //     for(int j=1;j<=n;j++){
        //         cout<<arr[i][j]<<"  ";
        //     }cout<<endl;
        // }cout<<endl;

    }
    return 2;
}

int main(){
    cin>>n;//输入多少行多少列
    arr.resize(n+1);
    for(int i=0;i<=n;i++){
        arr[i].resize(n+1);
    }//调整数组大小
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }//输入二维数组

    arr_const=arr;//赋值到已访问数组
    
    //操作
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr_1=arr_const;
            if(arr[i][j]!=1){
                arr[i][j]=bfs(i,j);
            }
        }
    }
    
    for(int i=1;i<=n;i++){//输出数组
        for(int j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    return 0;
}