// 题目描述
// 给定一个整数 N，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零（参见样例 2）。

// 输入格式
// 一个整数 N。

// 输出格式
// 一个整数，表示反转后的新数。

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==0){
        cout<<0;
    }else if(n<0){
        string ss=to_string(n*(-1));
        size_t size=ss.size();
        cout<<'-';
        for(int temp=0,i=size-1;i>=0;i--){
            if(ss[i]!='0'&&temp==0){
                temp+=1;
                cout<<ss[i];
            }else if(temp!=0){
                cout<<ss[i];
            }
        }
    }else if(n>0){
        string ss=to_string(n);
        size_t size=ss.size();
        //cout<<'-';
        for(int temp=0,i=size-1;i>=0;i--){
            if(ss[i]!='0'&&temp==0){
                temp+=1;
                cout<<ss[i];
            }else if(temp!=0){
                cout<<ss[i];
            }
        }
    }
    return 0;
}