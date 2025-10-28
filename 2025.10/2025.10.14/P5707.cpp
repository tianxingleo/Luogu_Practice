/*

学校和 yyy 的家之间的距离为 s 米，而 yyy 以 v 米每分钟的速度匀速走向学校。

在上学的路上，yyy 还要额外花费 10 分钟的时间进行垃圾分类。

学校要求必须在上午 8:00 到达，请计算在不迟到的前提下，yyy 最晚能什么时候出门。

由于路途遥远，yyy 可能不得不提前一点出发，但是提前的时间不会超过一天。

输入格式
一行两个正整数 s,v，分别代表路程和速度。

输出格式
输出一个 24 小时制下的时间，代表 yyy 最晚的出发时间。

输出格式为 HH:MM，分别代表该时间的时和分。必须输出两位，不足前面补 0。

*/

#include <stdio.h>
int main(){
    int s,v,min,hour,HH,MM;
    scanf ("%d %d",&s,&v);
    min=s/v+10;
    if(s%v!=0){
        min++;
    }
    hour=(min-min%60)/60;
    min=min-60*hour;
    if (min==00){
        min=60;
        hour--;
    }
    if (hour<8){
        HH=7-hour;
        MM=60-min;
        //HH=0;MM=0;
        if (MM>=10){
            printf("0%d:%d",HH,MM);
        }else{
            printf("0%d:0%d",HH,MM);
        }
        //return 0;
    }else {
        HH=24-(hour-7);
        MM=60-min;
        if (HH>=10){
            if (MM>=10){
                printf("%d:%d",HH,MM);
            }else{
                printf("%d:0%d",HH,MM);
            }
        }
        if (HH<10){
            if (MM>=10){
            printf("0%d:%d",HH,MM);
            }else{
            printf("0%d:0%d",HH,MM);
        }
        }
        //return 0;
    }
    
}