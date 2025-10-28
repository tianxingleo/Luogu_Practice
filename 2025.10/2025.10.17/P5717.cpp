/*
给出三条线段 a,b,c 的长度，均是不大于 10000 的正整数。打算把这三条线段拼成一个三角形，它可以是什么三角形呢？

如果三条线段不能组成一个三角形，输出Not triangle；
如果是直角三角形，输出Right triangle；
如果是锐角三角形，输出Acute triangle；
如果是钝角三角形，输出Obtuse triangle；
如果是等腰三角形，输出Isosceles triangle；
如果是等边三角形，输出Equilateral triangle。
如果这个三角形符合以上多个条件，请按以上顺序分别输出，并用换行符隔开。

输入格式
输入 3 个整数 a、b 和 c。

输出格式
输出若干行判定字符串。
*/

#include<stdio.h>
int main(){
    int a,b,c,t;
    scanf("%d %d %d",&a,&b,&c);
    	if(a>b){	// 3 2 1
		t=a;	// t=3
		a=b;	// a=2
		b=t;	// b=3
	}
	if(a>c){	
		t=a;	// t=2
		a=c;	// a=1
		c=t;	// c=2
	}
	if(b>c){
		t=b;	// t=3
		b=c;	// b=2
		c=t;	// c=3
	}

    if(a+b<=c||a+c<b||b+c<a){
        printf("Not triangle\n");
    }else if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a){
        printf("Right triangle\n");
    }else if(a*a+b*b>c*c){
        printf("Acute triangle\n");
    }else if(a*a+b*b<c*c){
        printf("Obtuse triangle\n");
    
    }
    if(a+b<=c||a+c<b||b+c<a){
    }else{
        if(a==b||a==c||b==c){
        printf("Isosceles triangle\n");
        }
        if(a==b&&b==c){
        printf("Equilateral triangle\n");
        }
    }
    

    return 0;
}
