// 根据斯诺登事件出的一道水题

// // 数据已经修正 By absi2011 如果还有问题请联系我

// 题目描述
// 2013 年 X 月 X 日，俄罗斯办理了斯诺登的护照，于是他混迹于一架开往委内瑞拉的飞机。但是，这件事情太不周密了，因为 FBI 的间谍早已获悉他的具体位置——但这不是最重要的——最重要的是如果要去委内瑞拉，那么就要经过古巴，而经过古巴的路在美国的掌控之中。

// 丧心病狂的奥巴马迫降斯诺登的飞机，搜查时却发现，斯诺登杳无踪迹。但是，在据说是斯诺登的座位上，发现了一张纸条。纸条由纯英文构成：Obama is a two five zero.（以 . 结束输出，只有 6 个单词 + 一个句号，句子开头如没有大写亦为合法）这句话虽然有点无厘头，但是警官陈珺骛发现这是一条极其重要的线索。他在斯诺登截获的一台笔记本中找到了一个 C++ 程序，输入这条句子后立马给出了相对应的密码。陈珺鹜高兴得晕了过去，身为警官的你把字条和程序带上了飞机，准备飞往曼哈顿国际机场，但是在飞机上检查的时候发现——程序被粉碎了！飞机抵达华盛顿只剩 5 分钟，你必须在这 5 分钟内编写（杜撰）一个程序，免受上司的 10000000000mod10 大板。破译密码的步骤如下：

// 找出句子中所有用英文表示的数字 (≤20)，列举在下：
// 正规：one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty
// 非正规：a both another first second third
// 为避免造成歧义，another 算作 1 处理。
// 将这些数字平方后对 100 取模，如 0→0→00，5→25→25，19→361→61。
// 把这些两位数（按任意顺序）按数位排成一行，组成一个新数，如果开头为 0，就去 0，如 {00,25,61}→2561。
// 找出所有排列方法中最小的一个数，即为密码。
// 输入格式
// 一个含有 6 个单词的句子。

// 保证整个句子的字符个数（包括空格）不超过 1000。

// 输出格式
// 一个整型变量（密码）。如果没有符合要求的数字出现，则输出 0。


#include <bits/stdc++.h>
using namespace std;

// 正规：one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty
// 非正规：a both another first second third
int which(string a){
    string number[21]={"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
    if(a=="one"||a=="a"||a=="another"||a=="first"){
        return 1;
    }else if(a=="two"||a=="both"||a=="second"){
        return 2;
    }else if(a=="three"||a=="third"){
        return 3;
    }else{
        for(int i=0;i<=20;i++){
            if(a==number[i]){
                return i;
            }
        }
    }
    return -1;
}

int main(){
    // string a;
    // cin>>a;
    // cout<<which(a);
    vector <string> word;
    vector <int> number;
    string line;
    getline(cin,line);
    string temp_string;
    stringstream ss(line);
    while(ss>>temp_string){
        if(which(temp_string)!=-1){
            number.push_back(which(temp_string));
        }
    }
    int number_length=number.size();
    for(int i=0;i<number_length;i++){
        number[i]=number[i]*number[i]%100;
    }
    if(number.size()==0){
        cout<<0;
        return 0;
    }
    sort(number.begin(),number.end());
    vector <int>number_0;
    vector <int>number_10;
    for(int i=0;i<=number.size()-1;i++){
        if(number[i]<10){
            number_0.push_back(number[i]);
        }else{
            number_10.push_back(number[i]);
        }
    }

    //int m;
    
    // for(int i=0,a=0,b=0;i<=number.size()-1;i++){
    //     if(number_0[a]==0){
    //         a++;
    //         continue;
    //     }
    //      //m=number_10.size()-1;
    //     if(a<=number_0.size()-1&&b<=number_10.size()-1){
    //         if(number_0[a]*10<=number_10[b]){
    //             word.push_back(to_string(number_0[a]));
    //             a++;
    //         }else{
    //             word.push_back(to_string(number_10[b]));
    //             b++;
    //         }
    //     }else{
    //         if(a<=number_0.size()-1){
    //             word.push_back(to_string(number_0[a]));
    //             a++;
    //         }
    //         if(b<=number_10.size()-1){
    //             word.push_back(to_string(number_10[b]));
    //             b++;
    //         }
    //     }
    // }

    bool temp_bool=0;
    int temp_int=0;
    if(number[number.size()-1]<10)temp_bool=1;
    for(int i=0;i<=number_length-1;i++){
        if(number[i]==0){
        }else if(number[i]>=1){
            if(number[i]<10&&temp_int==0){
                word.push_back(to_string(number[i]));
                temp_int++;
            }else{
                if(number[i]<10){
                    word.push_back("0"+to_string(number[i]));
                    temp_int++;
                }else{
                    word.push_back(to_string(number[i]));
                    temp_int++;
                }
            }
        }
    }
    for(int i=0;i<=word.size()-1;i++){
        cout<<word[i];
    }

    return 0;
}