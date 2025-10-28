/*

给定一个字符，用它构造一个底边长 5 个字符，高 3 个字符的等腰字符三角形。

输入格式
输入只有一行，包含一个字符。

输出格式
该字符构成的等腰三角形，底边长 5 个字符，高 3 个字符。

  *
 ***
*****


*/

#include <stdio.h>
int main()
{
    char a;
    scanf("%c",&a);
    printf("  %c\n %c%c%c\n%c%c%c%c%c",a,a,a,a,a,a,a,a,a);
    return 0;
}