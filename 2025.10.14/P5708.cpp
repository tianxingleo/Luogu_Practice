/*

一个三角形的三边长分别是 a、b、c，那么它的面积为  
p(p−a)(p−b)(p−c)
​
 ，其中 p= 
2
1
​
 (a+b+c)。输入这三个数字，计算三角形的面积，四舍五入精确到 1 位小数。

输入格式
第一行输入三个实数 a,b,c，以空格隔开。

输出格式
输出一个实数，表示三角形面积。精确到小数点后 1 位。

*/

#include <stdio.h>
#include <math.h>
int main(){
    float a,b,c,p;
    scanf("%f %f %f",&a,&b,&c);
    p=(a+b+c)/2;
    printf("%.1f",pow(p*(p-a)*(p-b)*(p-c),0.5));
    return 0;
}