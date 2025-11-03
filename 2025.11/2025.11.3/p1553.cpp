/*

题目背景
以下为原题面，仅供参考:

给定一个数，请将该数各个位上数字反转得到一个新数。

这次与 NOIp2011 普及组第一题不同的是：这个数可以是小数，分数，百分数，整数。整数反转是将所有数位对调；小数反转是把整数部分的数反转，再将小数部分的数反转，不交换整数部分与小数部分；分数反转是把分母的数反转，再把分子的数反转，不交换分子与分母；百分数的分子一定是整数，百分数只改变数字部分。整数新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零；小数新数的末尾不为 0（除非小数部分除了 0 没有别的数，那么只保留1个 0）；分数不约分，分子和分母都不是小数（约分滴童鞋抱歉了，不能过哦。输入数据保证分母不为 0），本次没有负数。

题目描述
给定一个数，请将该数各个位上数字反转得到一个新数。

这次与 NOIp2011 普及组第一题不同的是：这个数可以是小数，分数，百分数，整数。

整数反转是将所有数位对调。

小数反转是把整数部分的数反转，再将小数部分的数反转，不交换整数部分与小数部分。

分数反转是把分母的数反转，再把分子的数反转，不交换分子与分母。

百分数的分子一定是整数，百分数只改变数字部分。

输入格式
一个实数 s

输出格式
一个实数，即 s 的反转数

*/

#include <bits/stdc++.h>

using namespace std;



int main(){
    vector<char> a;
    vector<char> b;
    vector<char> c;
    string line;
    char symbol=' ';
    int sum1=0,sum2=0;
    if(getline(cin,line)){
        
        char temp;
        stringstream ss(line);
        while(ss>>temp){
            if(temp<='9'&&temp>='0'){
                sum2++;
                a.push_back(temp);
            }else if(temp=='.'){
                a.push_back(temp);
                symbol='.';
                sum1=sum2;
                sum2=0;
            }else if(temp=='/'){
                a.push_back(temp);
                symbol='/';
                sum1=sum2;
                sum2=0;
            }else if(temp=='%'){
                //a.push_back(temp);
                symbol='%';
                break;
            }
        }
    }
    //cout<<sum1<<' '<<sum2;
    if(symbol==' '){
        for(int i=a.size()-1;i>=0;i--){
            b.push_back(a[i]);
        }
        
        int temp_int=0;
        for(int i=0;i<=b.size()-1;i++){
            if(temp_int==0&&b[i]=='0'){}
            else{
                cout<<b[i];temp_int++;
            }
        }
        if (b.size()==1&&a[0]=='0')cout<<0;
        
    }else if(symbol=='.'||symbol=='/'){
        for(int i=sum1-1;i>=0;i--){
            b.push_back(a[i]);
        }
        int temp_int=0;
        for(int i=0;i<=b.size()-1;i++){
            if(temp_int==0&&b[i]=='0'){}
            else{
                cout<<b[i];temp_int++;
            }
        }
        if (b.size()==1&&a[0]=='0')cout<<0;
        temp_int=0;
        if(symbol=='.'){cout<<'.';}else{cout<<'/';}
        if(symbol=='.'){
            for(int i=sum1+1;i<=sum1+sum2;i++){
                if(temp_int==0&&a[i]=='0'){}
                else{c.push_back(a[i]);temp_int++;}
            }
            
            for(int i=temp_int-1;i>=0;i--){
                cout<<c[i];
            }
            if (c.size()==0)cout<<0;
        }else {
            // for(int i=sum1+1;i<=sum1+sum2;i++){
            //     if(temp_int==0&&a[i]=='0'){}
            //     else{c.push_back(a[i]);temp_int++;}
            // }
            
            // for(int i=temp_int-1;i>=0;i--){
            //     cout<<c[i];
            // }
            for(int i=sum1+sum2;i>=sum1+1;i--){
                c.push_back(a[i]);
            }
            int temp_int=0;
            for(int i=0;i<=c.size()-1;i++){
                if(temp_int==0&&c[i]=='0'){}
                else{
                    cout<<c[i];temp_int++;
                }
            }
            if (c.size()==0)cout<<0;
        }
    }else if(symbol=='%'){
        for(int i=a.size()-1;i>=0;i--){
            b.push_back(a[i]);
        }
        int temp_int=0;
        for(int i=0;i<=b.size()-1;i++){
            if(temp_int==0&&b[i]=='0'){}
            else{
                cout<<b[i];temp_int++;
            }
        }
        if (b.size()==1&&a[0]=='0')cout<<0;
        cout<<'%';
    }

    return 0;
}

