// 题目描述
// 猫猫 TOM 和小老鼠 JERRY 最近又较量上了，但是毕竟都是成年人，他们已经不喜欢再玩那种你追我赶的游戏，现在他们喜欢玩统计。

// 最近，TOM 老猫查阅到一个人类称之为“逆序对”的东西，这东西是这样定义的：对于给定的一段正整数序列，逆序对就是序列中 a 
// i
// ​
//  >a 
// j
// ​
//   且 i<j 的有序对。知道这概念后，他们就比赛谁先算出给定的一段正整数序列中逆序对的数目。注意序列中可能有重复数字。

// Update：数据已加强。

// 输入格式
// 第一行，一个数 n，表示序列中有 n 个数。

// 第二行 n 个数，表示给定的序列。序列中每个数字不超过 10 
// 9
//  。

// 输出格式
// 输出序列中逆序对的数目。


// #include <bits/stdc++.h>
// using nam std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int>shulie(n+1,0);
//     for(int i=0;i<=n-1;i++){
//         cin>>shulie[i];
//     }espace
//     shulie[n]=0;
//     int sum=0;
//     for(int i=0;i<=n-2;i++){
//         vector<int>shulie_1=shulie;
//         sort(shulie_1.begin()+i+1,shulie_1.begin()+n);
//         for (int j=i+1;shulie_1[j]<shulie_1[i]&&j<=n-1;j++){
//             sum++;
//         }
//     }
//     cout<<sum;
//     return 0;
// }


// #include <stdio.h>
// #include <vector>

// int main(){

    
//     int n;
//     scanf("%d",&n);
//     std::vector<int>shulie(n,0);
//     for(int i=0;i<=n-1;i++){
//         scanf("%d",&shulie[i]);
//     }
//     int sum=0;
//     for(int i=0;i<=n-2;i++){
//         for (int j=i+1;j<=n-1;j++){
//             if(shulie[i]>shulie[j]){
//                 sum++;
//             }
//         }
//     }
//     printf("%d",sum);
// }


#include <bits/stdc++.h>
using namespace std;

long long int sum=0;

void merge(vector<int>&arr,int min,int mid,int max){
    vector<int>temp;
    int i=min,j=mid+1;
    int second=0;
    while(i<=mid&&j<=max){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
            sum+=second;
        }else{
            temp.push_back(arr[j]);
            j++;
            second++;
        }
    }
    while(j<=max){
        temp.push_back(arr[j]);
        j++;
        second++;
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
        sum+=second;
    }
    for(int i=min;i<=max;i++){
        arr[i]=temp[i-min];
    }
}

void sort(vector<int>&arr,int min,int max){
    if(min<max){
        int mid=(min+max)/2;
        sort(arr,min,mid);
        sort(arr,mid+1,max);
        merge(arr,min,mid,max);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    std::vector<int>shulie(n,0);
    for(int i=0;i<=n-1;i++){
        scanf("%d",&shulie[i]);
    }
    sort(shulie,0,n-1);
    cout<<sum;
    return 0;
}