

/*

题目描述
因为 151 既是一个质数又是一个回文数（从左到右和从右到左是看一样的），所以 151 是回文质数。

写一个程序来找出范围 [a,b](5≤a<b≤100,000,000)（一亿）间的所有回文质数。

输入格式
第一行输入两个正整数 a 和 b。

输出格式
输出一个回文质数的列表，一行一个。

*/


/*

#include <stdio.h>
#include <stdbool.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

vector<bool> zhishu(100000001,true);
vector<int> zhishu_1(6000000,0);
void zhishubiao(){
    int N=100000000;
    int c=0;
    for(int i=2;i<=N;i++){

        if(zhishu[i]==1){
            zhishu_1[c]=i;
            c++;
        }

        for(int j=0;zhishu_1[j]!=0&&zhishu_1[j]*i<=N;j++){
            zhishu[i*zhishu_1[j]]=0;
            if(i%zhishu_1[j]==0){
                break;
            }
        }
}
}


vector<int> huiwenshu_1(30000,0);

void huiwenshubiao(){
    string b;
    string c;
    int d=0;
    for(int i=5;i<=100000000;i+=2){
        b=to_string(i);
        c=b;
        reverse(b.begin(),b.end());
        if(b==c){
            huiwenshu_1[d]=i;
            d++;
        }
    }
    
}

bool if_huiwenshu(int a){
    string b=to_string(a);
    string c=b;
    reverse(b.begin(),b.end());
    if(b==c){
        return 1;
    }else{
        return 0;
    }
}

bool if_zhishu(int a){
    for(int i=2;i<a/2;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    huiwenshubiao();
    zhishubiao();
    int min,max;
    scanf("%d %d",&min,&max);
    vector<int> huiwenshu;
    if (min%2==0){
        min++;
    }
    for(int i=min;i<=max;i+=2){
        if(binary_search(huiwenshu_1.begin(), huiwenshu_1.end(), i)==1&&binary_search(zhishu_1.begin(), zhishu_1.end(), i)==1){
            cout<<i<<endl;
            //huiwenshu.push_back(i);
        }
    }



    return 0;
}


*/


#include <stdio.h>

#include <stdbool.h>

#include <vector>

#include <iostream>

#include <string>

#include <algorithm>

using namespace std;



vector<bool> zhishu(100000001,true);

vector<int> zhishu_1(6000000,0);

void zhishubiao(){

    int N=100000000;

    int c=0;

    for(int i=2;i<=N;i++){



        if(zhishu[i]==1){

            zhishu_1[c]=i;

            c++;

        }



        for(int j=0;j<c&&zhishu_1[j]*i<=N;j++){

            zhishu[i*zhishu_1[j]]=0;

            if(i%zhishu_1[j]==0){

                break;

            }

        }

}

}

string b,c;
/*
bool if_huiwenshu(int a){

    b=to_string(a);

    c=b;

    reverse(b.begin(),b.end());

    if(b==c){

        return 1;

    }else{

        return 0;

    }

}
*/
//频繁创建字符串对象（to_string 和 reverse 都很耗时）。
//全局变量 b、c 会导致线程不安全，也增加拷贝代价。

bool if_huiwenshu(int a) {
    int x = a, rev = 0;
    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev == a;
}


bool if_zhishu(int a){

    for(int i=2;i<a/2;i++){

        if(a%i==0){

            return 0;

        }

    }

    return 1;

}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //如果区间较大（如上亿），cout 输出太频繁也会拖慢程序，可以改为缓冲输出。

    zhishubiao();

    int min,max;

    scanf("%d %d",&min,&max);

    //vector<int> huiwenshu;

    if (min%2==0){

        min++;

    }

    for(int i=min;i<=max;i+=2){

        if(  if_huiwenshu(i)==1&&zhishu[i]){

            cout<<i<<endl;

            //huiwenshu.push_back(i);

        }

    }







    return 0;

}