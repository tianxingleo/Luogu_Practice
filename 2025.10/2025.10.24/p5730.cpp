/*

题目描述
液晶屏上，每个阿拉伯数字都是可以显示成 3×5 的点阵的（其中 X 表示亮点，. 表示暗点）。现在给出数字位数（不超过 100）和一串数字，要求输出这些数字在显示屏上的效果。数字的显示方式如同样例输出，注意每个数字之间都有一列间隔。

输入格式
第一行输入一个正整数 n，表示数字的位数。

第二行输入一个长度为 n 的自然数。

输出格式
输出五行，表示显示屏上的数字。

*/

#include<iostream>
#include<vector>
using namespace std;

char number[10][5][4]={{
    {'X','X','X'},
    {'X','.','X'},
    {'X','.','X'},
    {'X','.','X'},
    {'X','X','X'}
},{
    {'.','.','X'},
    {'.','.','X'},
    {'.','.','X'},
    {'.','.','X'},
    {'.','.','X'}
},{
    {'X','X','X'},
    {'.','.','X'},
    {'X','X','X'},
    {'X','.','.'},
    {'X','X','X'}
},{
    "XXX",
    "..X",
    "XXX",
    "..X",
    "XXX"
},{
    "X.X",
    "X.X",
    "XXX",
    "..X",
    "..X"

},{
    "XXX",
    "X..",
    "XXX",
    "..X",
    "XXX"
},{
    "XXX",
    "X..",
    "XXX",
    "X.X",
    "XXX"
},{
    "XXX",
    "..X",
    "..X",
    "..X",
    "..X",
},{
    "XXX",
    "X.X",
    "XXX",
    "X.X",
    "XXX"
},{
    "XXX",
    "X.X",
    "XXX",
    "..X",
    "XXX"
}



};

/*

char a_1[5][3]={
    {'.','.','X'},
    {'.','.','X'},
    {'.','.','X'},
    {'.','.','X'},
    {'.','.','X'}
};

char a_0[5][3]={
    {'X','X','X'},
    {'X','.','X'},
    {'X','.','X'},
    {'X','.','X'},
    {'X','X','X'}
};

char a_2[5][3]{
    {'X','X','X'},
    {'.','.','X'},
    {'X','X','X'},
    {'X','.','.'},
    {'X','X','X'}
};

char a_3[5][4]{
    "XXX",
    "..X",
    "XXX",
    "..X",
    "XXX"
};

char a_4[5][4]{
    "X.X",
    "X.X",
    "XXX",
    "..X",
    "..X"

};

char a_5[5][4]{
    "XXX",
    "X..",
    "XXX",
    "..X",
    "XXX"
};

char a_6[5]
*/

int main(){
    int n;
    cin>>n;
    vector<vector<char>> pin(5,vector<char>(n*3+n));
    string numbers_1;
    cin>>numbers_1;
    vector <int>numbers_2(n,0);
    for(int i=0;i<=n-1;i++){
        numbers_2[i]=numbers_1[i]-'0';
    }

    //int lie=0;//操作的列
    for(int i=0;i<=n-1;i++){//数字
        for(int j=0;j<=4;j++){//行
            for(int m=0;m<=2;m++){//列
                pin[j][m+i*4]=number[numbers_2[i]][j][m];
                //lie+=1;//正在操作的列
            }
            pin[j][3+i*4]='.';
            //lie+=1;
        }
    }


    for(int i=0;i<=4;i++){
        for(int j=0;j<=n*3+n-2;j++){
            cout<<pin[i][j];
        }
        cout<<endl;
    }

    return 0;
}