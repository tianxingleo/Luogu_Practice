#include <bits/stdc++.h>
using namespace std;

vector<int>deepth;
vector<int>diff;

int n;

void plusplus(int i,int j){
    // diff[i]--;
    // diff[j+1]++;
    // deepth[0]=diff[0];
    // for(int a=1;a<n;a++){//
    //     deepth[a]=deepth[a-1]+diff[a];
    // }
    for(int a=i;a<=j;a++){
        deepth[a]--;
    }
}

int main(){
    
    cin>>n;
    deepth.resize(n+1,0);
    diff.resize(n+1,0);
    cin>>deepth[0];
    diff[0]=deepth[0];
    for(int i=1;i<n;i++){
        cin>>deepth[i];
        diff[i]=deepth[i]-deepth[i-1];
    }

    int sum=0;
    //开始操作
    for(int i=0;i<n;i++){
        for(;;){
            int j=i;
            for(;deepth[j]>0;j++){}
            if(j>i)j--;
            if(deepth[j]>0){
                sum++;
                plusplus(i,j);
                ;
            }
            else break;
        }    

    }
    cout<<sum;

    return 0;
}