/*
输入一个小写字母，输出其对应的大写字母。例如输入 q[回车] 时，会输出 Q。
*/


#include <stdio.h>
int main()
{
    char a;
    scanf ("%c",&a);
    printf("%c",a-32);
    return 0;
}