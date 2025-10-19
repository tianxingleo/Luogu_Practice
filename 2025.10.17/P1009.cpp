/*
用高精度计算出 S=1!+2!+3!+⋯+n!（n≤50）。

其中 ! 表示阶乘，定义为 n!=n×(n−1)×(n−2)×⋯×1。例如，5!=5×4×3×2×1=120。

输入格式
一个正整数 n。

输出格式
一个正整数 S，表示计算结果。
*/

#include <stdio.h>
int main()
{
    int a;
    double b,c;
    scanf("%d",&a);
    c=0;
    for (;a>=1;a--){
        b=1;
        //printf("1\n");
        for(int i=a;i>=1;i--)
        {
            b=b*i;
            //printf("%.0lf\n",b);
        }
        c=c+b;
    }
    
    printf("%.0lf",c);
    return 0;
}