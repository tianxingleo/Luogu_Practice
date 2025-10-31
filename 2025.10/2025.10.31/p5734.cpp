// 题目描述
// 你需要开发一款文字处理软件。最开始时输入一个字符串作为初始文档。可以认为文档开头是第 0 个字符。需要支持以下操作：

// 1 str：后接插入，在文档后面插入字符串 str，并输出文档的字符串；
// 2 a b：截取文档部分，只保留文档中从第 a 个字符起 b 个字符，并输出文档的字符串；
// 3 a str：插入片段，在文档中第 a 个字符前面插入字符串 str，并输出文档的字符串；
// 4 str：查找子串，查找字符串 str 在文档中最先的位置并输出；如果找不到输出 −1。
// 为了简化问题，规定初始的文档和每次操作中的 str 都不含有空格或换行。最多会有 q 次操作。

// 输入格式
// 第一行输入一个正整数 q，表示操作次数。

// 第二行输入一个字符串 str，表示最开始的字符串。

// 第三行开始，往下 q 行，每行表示一个操作，操作如题目描述所示。

// 输出格式
// 一共输出 q 行。

// 对于每个操作 1,2,3，根据操作的要求输出一个字符串。

// 对于操作 4，根据操作的要求输出一个整数。

#include <bits/stdc++.h>
using namespace std;

string is(string line,string sentence);
string change_1(string a,string b);
string change_2(string a,int a_1,int b_1);
string change_3(string a,int b,string c);
string change_4(string a,string b);

string array_1;

string is(string line,string sentence){
    stringstream ss(line);
    int number,a,b;
    ss>>number;
    string arr;
    if (number==1){
        ss>>arr;
        return change_1(sentence,arr);
    }else if(number==2){
        ss>>a>>b;
        return change_2(sentence,a,b);
    }else if(number==3){
        ss>>a>>arr;
        return change_3(sentence,a,arr);
    }else{
        ss>>arr;
        return change_4(sentence,arr);
    }
}

string change_1(string a,string b){
    array_1=a+b;
    return a+b;
}
string change_2(string a,int a_1,int b_1){
    string b="";
    for(int i=a_1;i<=min(int(a.size()),a_1+b_1-1);i++){
        b=b+a[i];
    }
    array_1=b;
    return b;
}
string change_3(string a,int b,string c){
    string d="";
    for(int i=0;i<b;i++){
        d=d+a[i];
    }
    d=d+c;
    for(int i=b;i<=a.size()-1;i++){
        d=d+a[i];
    }
    array_1=d;
    return d;
}
string change_4(string a,string b){
    int c=a.find(b);
    if(c!=-1){
        return to_string(c);
    }else{
        return "-1";
    }
}

int main(){
    int n;
    cin>>n;
    
    //cin.get();
    cin>>array_1;
    //cin.get();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string line;
    vector<string>answer(n);
    for(int i=0;i<=n-1;i++){
        if(getline(cin,line)){
            answer[i]=is(line,array_1);
            
        }
        
    }
    for(int i=0;i<=n-1;i++){
        cout<<answer[i]<<endl;
    }

    return 0;
}