// 这是一个组合求和并判断素数的问题。

// 题目描述
// 已知 n 个整数 x1, x2, ..., xn，以及 1 个整数 k（k < n）。从 n 个整数中任选 k 个整数相加，可分别得到一系列的和。

// 例如：当 n=4，k=3，4 个整数分别为 3, 7, 12, 19 时，可得全部的组合与它们的和为： 3 + 7 + 12 = 22 3 + 7 + 19 = 29 7 + 12 + 19 = 38 3 + 12 + 19 = 34

// 现在，要求你计算出和为素数共有多少种。 例如上例，只有一种的和为素数：3 + 7 + 19 = 29。

// 输入格式
// 第一行两个空格隔开的整数 n, k（1 <= n <= 20，k < n）。 第二行 n 个整数，分别为 x1, x2, ..., xn（1 <= xi <= 5 * 10^6）。

// 输出格式
// 输出一个整数，表示种类数。


#include <bits/stdc++.h>
using namespace std;

vector<bool>zhishu(200000001,1);
void zhishubiao(){
    int n=100000000;
    zhishu[0]=0;
    zhishu[1]=0;
    int sqrt_1=sqrt(n);
    for(int i=2;i<=sqrt_1;i++){
        if(zhishu[i]==1){
            for(int j=i*i;j<=n;j+=i){
                zhishu[j]=0;
            }
        }
    }
}

int n,k;
vector<int>arr;
int sum=0;
vector<int>path;

bool is_zhishu(vector<int>&path){
    int temp_int=0;
    for(int i=0;i<=k-1;i++){
        temp_int=temp_int+path[i];
    }
    return zhishu[temp_int];
}

void choose(int idx){
    if(path.size()==k){
        if(is_zhishu(path)){
            sum++;
        }
        return;
    }
    if(idx==arr.size()){
        return;
    }
    if(path.size()+(arr.size()-idx)<k){
        return;
    }

    path.push_back(arr[idx]);
    choose(idx+1);
    path.pop_back();

    choose(idx+1);

}

int main(){
    zhishubiao();
    cin>>n>>k;
    arr.resize(n);
    //path.resize(k);
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
        //sum++;
    }
    choose(0);
    cout<<sum;
    return 0;
}




// #include <bits/stdc++.h>
// using namespace std;

// vector<bool>arr(200000001,1);
// int sum=0;

// void zhishubiao(){
//     int n=100000000;
//     arr[0]=0;
//     arr[1]=0;
//     int sqrt_1=sqrt(n);
//     for(int i=2;i<=sqrt_1;i++){
//         if(arr[i]==1){
//             for(int j=i*i;j<=n;j+=i){
//                 arr[j]=0;
//             }
//         }
//     }
// }

// void count(vector<int>&arr_1,vector<int>&choose,vector<int>&zhizhen,int n,int k){
//     if(zhizhen[0]<=n-k){

//     }
// }

// int main(){
//     zhishubiao();
//     int n,k;
//     cin>>n>>k;
//     vector<int>arr_1(n);
//     vector<int>choose(k);
//     vector<int>zhizhen(k);
//     for(int i=0;i<=k-1;i++){
//         zhizhen[i]=1+i;
//     }
//     for(int i=0;i<=n-1;i++){
//         cin>>arr_1[i];
//     }
//     //for(int )


//     return 0;
// }