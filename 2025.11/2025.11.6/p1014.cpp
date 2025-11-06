// 题目描述
// 现代数学的著名证明之一是 Georg Cantor 证明了有理数是可枚举的。他是用下面这一张表来证明这一命题的：



// 我们以 Z 字形给上表的每一项编号。第一项是 1/1，然后是 1/2，2/1，3/1，2/2，…

// 输入格式
// 整数 N（1≤N≤10 
// 7
//  ）。

// 输出格式
// 表中的第 N 项。

#include <bits/stdc++.h>
using namespace std;

int a_1(vector<int>&arr,int n,int temp_int){
    int temp=1;
    bool temp_bool=1;
    for(int i=1;temp<temp_int;i++){
        if(temp_bool==1){
            for(int j=i;j>=1;j--){
                arr[temp]=j;
                temp++;
                temp_bool=0;
            }
        }else{
            for(int j=1;j<=i;j++){
                arr[temp]=j;
                temp++;
                temp_bool=1;
            }
        }
        
    }
    return arr[n];
}

int a_2(vector<int>&arr,int n,int temp_int){
    int temp=1;
    bool temp_bool=0;
    for(int i=1;temp<temp_int;i++){
        if(temp_bool==1){
            for(int j=i;j>=1;j--){
                arr[temp]=j;
                temp++;
                temp_bool=0;
            }
        }else{
            for(int j=1;j<=i;j++){
                arr[temp]=j;
                temp++;
                temp_bool=1;
            }
        }
        
    }
    return arr[n];
}


int main(){
    int n;
    cin>>n;
    int temp_int=0;
    for(int i=1;temp_int<n;i++){
        temp_int+=i;
    }
    vector<int>arr(temp_int+1,0);
    int left=a_1(arr,n,temp_int);
    //cout<<left;
    int right=a_2(arr,n,temp_int);
    //cout<<right;
    cout<<left<<'/'<<right;
    return 0;
}