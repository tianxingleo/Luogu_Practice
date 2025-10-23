/*

已知正整数 n 是两个不同的质数的乘积，试求出两者中较大的那个质数。

输入格式
输入一个正整数 n。

输出格式
输出一个正整数 p，即较大的那个质数。

*/

//1.生成质数表
//2.循环尝试，小于等于n/2
//3.输出

#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;

vector <bool> zhishubiao_1(100000001,1);
vector <int> zhishubiao_2(6000000,0);
int c=0;
void zhishubiao(){
    for(int a=2;a<=100000000;a++){
        if (zhishubiao_1[a]==1){
            zhishubiao_2[c]=a;
            c++;
        }
        for(int b=0;b<c&zhishubiao_2[b]*a<=100000000;b++){
            zhishubiao_1[zhishubiao_2[b]*a]=0;
            if(a%zhishubiao_2[b]==0){
                break;
            }
        }
    }
}

int search(int n){
    for(int i=0;zhishubiao_2[i]<=n/2;i++){
        for (int j=i;zhishubiao_2[j]<=n/2;j++){
            if (zhishubiao_2[i]*zhishubiao_2[j]==n){
                return zhishubiao_2[j];
            }
        }
    }
}

int main(){
    zhishubiao();
    int n,p;
    cin>>n;
    for(int i=0;zhishubiao_2[i]<=n/2;i++){
        if(n%zhishubiao_2[i]==0){
            p=n/zhishubiao_2[i];
            break;
        }
    }
    cout<<p;

    return 0;
}