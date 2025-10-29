#include <bits/stdc++.h>
using namespace std;

bool zhishu[101];
int word_1['z'+1];

void zhishubiao(){
    for(int i=2;i<=100;i++){
        zhishu[i]=1;
    }
    for(int i=2;i<=100;i++){
        for(int j=i*i;j<=100&&zhishu[i];j+=i){
            zhishu[j]=0;
        }
    }
}



int main(){
    zhishubiao();
    string word;
    cin>>word;
    int n=word.size();
    int maxn=0,minn=100;
    
    for(int i=0;i<=n-1;i++){
        word_1[word[i]]++;
    }
    for(int i='a';i<='z';i++){
        if(maxn<word_1[i]){
            maxn=word_1[i];
        }
    }
    for(int i='a';i<='z';i++){
        if(minn>word_1[i]&&word_1[i]!=0){
            minn=word_1[i];
        }
    }
    if(zhishu[maxn-minn]){
        cout<<"Lucky Word"<<endl<<maxn-minn;
    }else{
        cout<<"No Answer"<<endl<<0;
    }

    return 0;
}