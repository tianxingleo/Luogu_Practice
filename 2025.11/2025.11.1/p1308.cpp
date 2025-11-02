// 题目描述
// 一般的文本编辑器都有查找单词的功能，该功能可以快速定位特定单词在文章中的位置，有的还能统计出特定单词在文章中出现的次数。

// 现在，请你编程实现这一功能，具体要求是：给定一个单词，请你输出它在给定的文章中出现的次数和第一次出现的位置。注意：匹配单词时，不区分大小写，但要求完全匹配，即给定单词必须与文章中的某一独立单词在不区分大小写的情况下完全相同（参见样例 1），如果给定单词仅是文章中某一单词的一部分则不算匹配（参见样例 2）。

// 输入格式
// 共 2 行。

// 第 1 行为一个字符串，其中只含字母，表示给定单词；

// 第 2 行为一个字符串，其中只可能包含字母和空格，表示给定的文章。

// 输出格式
// 一行，如果在文章中找到给定单词则输出两个整数，两个整数之间用一个空格隔开，分别是单词在文章中出现的次数和第一次出现的位置（即在文章中第一次出现时，单词首字母在文章中的位置，位置从 0 开始）；如果单词在文章中没有出现，则直接输出一个整数 −1。

// 注意：空格占一个字母位


//gpt，存在问题
// #include <bits/stdc++.h>
// using namespace std;

// string to_lowercase(string s) {
//     for (auto &ch : s)
//         if (ch >= 'A' && ch <= 'Z')
//             ch += 32;
//     return s;
// }

// int main() {
//     string word, line;
//     cin >> word;
//     getline(cin >> ws, line); // 安全读取第二行

//     word = to_lowercase(word);
//     line = to_lowercase(line);

//     size_t pos = 0, first = string::npos;
//     size_t count = 0;
//     size_t len_word = word.size(), len_line = line.size();

//     while (true) {
//         pos = line.find(word, pos);
//         if (pos == string::npos) break;

//         bool left_ok = (pos == 0 || line[pos - 1] == ' ');
//         bool right_ok = (pos + len_word == len_line || line[pos + len_word] == ' ');
//         if (left_ok && right_ok) {
//             count++;
//             if (count == 1) first = pos;
//         }
//         pos += len_word; // 跳过已匹配单词
//     }

//     if (count == 0)
//         cout << -1;
//     else
//         cout << count << " " << first;

//     return 0;
// }


//自己写的
#include <bits/stdc++.h>
using namespace std;

string to_small(string a){
    int length=a.size();
    for(int i=0;i<=length-1;i++){
        if(a[i]<='Z'&&a[i]>='A'){
            a[i]+=32;
        }
    }
    return a;
}

int main(){
    string str,line;
    cin>>str;
    cin.ignore(1024,'\n');
    getline(cin,line);
    str=to_small(str);
    line=to_small(line);
    long long sum=0;
    
    // int temp=0;
    // int length_1=str.size();
    // int length_2=line.size();
    size_t first;
    size_t temp=0;
    size_t length_1=str.size();
    size_t length_2=line.size();
    for(size_t i=0;i<=length_2-1;i++){
        temp=line.find(str,i);
        if(temp!=string::npos&&(temp==0||line[temp-1]==' ')&&(temp+length_1==length_2||line[temp+length_1]==' ')){
            i=temp+length_1-1;
            sum++;
            if(sum==1){
                first=temp;
            }
        }else if(temp==string::npos){
            break;
        }else {
            i=temp+length_1-1;
        }
    }

    //gpt优化
    // size_t pos = 0;
    // while (true) {
    //     pos = line.find(str, pos);
    //     if (pos == string::npos) break;

    //     if ((pos == 0 || line[pos - 1] == ' ') &&
    //         (pos + length_1 == length_2 || line[pos + length_1] == ' ')) {
    //         if (sum == 0) first = pos;
    //         sum++;
    //     }

    //     pos += length_1; // ✅ 关键：从当前位置后面继续找
    // }
    
    if(sum!=0){
        cout<<sum<<' '<<first;
    }else{
        cout<<-1;
    }

    return 0;
}