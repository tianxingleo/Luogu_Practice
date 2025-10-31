// 题目描述
// 王老师正在教简单算术运算。细心的王老师收集了 i 道学生经常做错的口算题，并且想整理编写成一份练习。编排这些题目是一件繁琐的事情，为此他想用计算机程序来提高工作效率。王老师希望尽量减少输入的工作量，比如 5+8 的算式最好只要输入 5 和 8，输出的结果要尽量详细以方便后期排版的使用，比如对于上述输入进行处理后输出 5+8=13 以及该算式的总长度 6。王老师把这个光荣的任务交给你，请你帮他编程实现以上功能。

// 输入格式
// 第一行一个整数 i。

// 接着的 i 行为需要输入的算式，每行可能有三个数据或两个数据。

// 若该行为三个数据则第一个数据表示运算类型，a 表示加法运算，b 表示减法运算，c 表示乘法运算，接着的两个数据表示参加运算的运算数。

// 若该行为两个数据，则表示本题的运算类型与上一题的运算类型相同，而这两个数据为运算数。

// 输出格式
// 输出 2×i 行。对于每个输入的算式，输出完整的运算式及结果，第二行输出该运算式的总长度。

#include <bits/stdc++.h>
using namespace std;
int length(int a){
    string b=to_string(a);
    return b.size();
}

int calculating(char a,int b,int c){
    if(a=='a'){
        return b+c;
    }else if(a=='b'){
        return b-c;
    }else if(a=='c'){
        return b*c;
    }
}
char change(char a){
    if(a=='a'){
        return '+';
    }else if(a=='b'){
        return '-';
    }else if(a=='c'){
        return '*';
    }
}

int input_numbers(vector<char>&arr_cal,vector<int>&arr_1,int i,char last_number){
    string line;
    
    if(getline(cin,line)){
        stringstream ss(line);
        vector<int>arr_2(2);
        int element;
        int sum=0;
        char cal;
        
        if(ss>>cal>>arr_2[0]>>arr_2[1]&&(cal=='a'||cal=='b'||cal=='c')){
            arr_cal[i]=cal;
            arr_1.push_back(arr_2[0]);
            arr_1.push_back(arr_2[1]);
            return cal;

        }else{
            ss.clear();
            ss.seekg(0);
            ss>>arr_2[0]>>arr_2[1];
            arr_cal[i]=last_number;
            arr_1.push_back(arr_2[0]);
            arr_1.push_back(arr_2[1]);
            return last_number;
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<char>calculate(n);
    vector<vector<int>>numbers(n,vector<int>());
    char last_number='a';
    cin.get();
    for(int i=0;i<=n-1;i++){
        last_number=input_numbers(calculate,numbers[i],i,last_number);
    }
    for(int i=0;i<=n-1;i++){
        cout<<numbers[i][0]<<change(calculate[i])<<numbers[i][1]<<"="<<calculating(calculate[i],numbers[i][0],numbers[i][1])<<endl;
        cout<<length(numbers[i][1])+length(numbers[i][0])+length(calculating(calculate[i],numbers[i][0],numbers[i][1]))+2<<endl;
    }

    return 0;
}