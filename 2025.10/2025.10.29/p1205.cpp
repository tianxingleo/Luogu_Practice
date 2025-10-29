// 题目描述
// 一块 n×n 正方形的黑白瓦片的图案要被转换成新的正方形图案。写一个程序来找出将原始图案按照以下列转换方法转换成新图案的最小方式：

// 转 90°：图案按顺时针转 90°。

// 转 180°：图案按顺时针转 180°。

// 转 270°：图案按顺时针转 270°。

// 反射：图案在水平方向翻转（以中央铅垂线为中心形成原图案的镜像）。

// 组合：图案在水平方向翻转，然后再按照 1∼3 之间的一种再次转换。

// 不改变：原图案不改变。

// 无效转换：无法用以上方法得到新图案。

// 如果有多种可用的转换方法，请选择序号最小的那个。

// 只使用上述 7 个中的一个步骤来完成这次转换。

// 输入格式
// 第一行一个正整数 n。

// 然后 n 行，每行 n 个字符，全部为 @ 或 -，表示初始的正方形。

// 接下来 n 行，每行 n 个字符，全部为 @ 或 -，表示最终的正方形。

// 输出格式
// 单独的一行包括 1∼7 之间的一个数字（在上文已描述）表明需要将转换前的正方形变为转换后的正方形的转换方法。

#include <bits/stdc++.h>
using namespace std;

int same(vector<vector<char>> &a,vector<vector<char>> &b,int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]==a[i][j]){
                sum++;
            }
        }
    }
    if(sum==n*n){
        return 1;
    }else{
        return 0;
    }
}

int if_1(vector<vector<char>> &a,vector<vector<char>> &a_1,vector<vector<char>> &b,int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[i][j]=a[n+1-j][i];
        }
    }
    // for(int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         cout<<b[i][j];
    //     }
    //     cout<<endl;
    // }cout<<endl;
    if(same(b,a_1,n)==1){
        return 1;
    }else{
        return 0;
    }
}

int if_2(vector<vector<char>> &a,vector<vector<char>> &a_1,vector<vector<char>> &b,int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[i][j]=a[n+1-i][n+1-j];
        }
    }
    if(same(b,a_1,n)==1){
        return 1;
    }else{
        return 0;
    }
}

int if_3(vector<vector<char>> &a,vector<vector<char>> &a_1,vector<vector<char>> &b,int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[i][j]=a[j][n+1-i];
        }
    }
    if(same(b,a_1,n)==1){
        return 1;
    }else{
        return 0;
    }
}

int if_4(vector<vector<char>> &a,vector<vector<char>> &a_1,vector<vector<char>> &b,int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[i][j]=a[i][1+n-j];
        }
    }
    if(same(b,a_1,n)==1){
        return 1;
    }else{
        return 0;
    }
}

int if_5(vector<vector<char>> &a_1,vector<vector<char>> &a_2,vector<vector<char>> &b,int n){
    if_4(a_1,b,a_1,n);
    vector<vector<char>>b_1(n+1,vector<char>(n+1));//二次计算
    vector<vector<char>>b_2(n+1,vector<char>(n+1));//二次计算
    vector<vector<char>>b_3(n+1,vector<char>(n+1));//二次计算
    if_1(b,a_1,b_1,n);
    if_2(b,a_1,b_2,n);
    if_3(b,a_1,b_3,n);
    if(same(b_1,a_2,n)||same(b_2,a_2,n)||same(b_3,a_2,n)){
        return 1;
    }else {
        return 0;
    }
}



int main(){
    int n;
    cin>>n;
    vector<vector<char>>a_1(n+1,vector<char>(n+1));//输入的数组
    vector<vector<char>>a_2(n+1,vector<char>(n+1));//输入的数组
    vector<vector<char>>b(n+1,vector<char>(n+1));//一次计算
    vector<vector<char>>c(n+1,vector<char>(n+1));//二次计算
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>a_1[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>a_2[i][j];
        }
    }
    // if_4(a_1,b,n);
    // for(int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         cout<<b[i][j];
    //     }
    //     cout<<endl;
    // }
    if(if_1(a_1,a_2,b,n)){
        cout<<1;
    }else if(if_2(a_1,a_2,b,n)){
        cout<<2;
    }else if(if_3(a_1,a_2,b,n)){
        cout<<3;
    }else if(if_4(a_1,a_2,b,n)){
        cout<<4;
    }else if(if_5(a_1,a_2,b,n)){
        cout<<5;
    }else if(same(a_1,a_2,n)){
        cout<<6;
    }else{
        cout<<7;
    }

    return 0;
}