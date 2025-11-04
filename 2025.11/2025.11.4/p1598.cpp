// 题目描述
// 写一个程序从输入文件中去读取四行大写字母（全都是大写的，每行不超过 100 个字符），然后用柱状图输出每个字符在输入文件中出现的次数。严格地按照输出样例来安排你的输出格式。

// 输入格式
// 四行字符，由大写字母组成，每行不超过 100 个字符。

// 输出格式
// 由若干行组成，前几行由空格和星号组成，最后一行则是由空格和字母组成的。在任何一行末尾不要打印不需要的多余空格。不要打印任何空行。

#include <bits/stdc++.h>
using namespace std;

void in(vector<int>&word){
    string line;
    if(getline(cin,line)){
        stringstream ss(line);
        char temp;
        while(ss>>temp){
            if (temp>='A'&&temp<='Z'){
                word[temp-'A']++;
            }
        }
    }

}

int main(){
    vector<int>word(26,0);
    for(int i=1;i<=4;i++){
        in(word);
    }
    int max=*max_element(word.begin(), word.end());
    vector <vector<char>>symbol(max,vector<char>(26,' '));
    for(int i=0;i<=max-1;i++){
        for(int j=0;j<=25;j++){
            if(word[j]>=max-i){
                symbol[i][j]='*';
            }
        }
    }

    for(int i=0;i<=max-1;i++){
        for(int j=0;j<=25;j++){
            cout<<symbol[i][j]<<' ';
        }
        cout<<endl;
    }
    char temp_char;
    for(int i=0;i<=25;i++){
        temp_char='A'+i;
        cout<<temp_char<<' ';
    }
    return 0;
}