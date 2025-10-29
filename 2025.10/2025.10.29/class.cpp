#include <stdio.h>
#include <string.h>

int main() {
    char array[3][20] = {"Liu", "Guan", "Zhang"};
    char t[20]; // 临时变量

    // 逆序：交换 array[0] 和 array[2]
    strcpy(t, array[0]);
    strcpy(array[0], array[2]);
    strcpy(array[2], t);

    // 输出逆序后的结果
    for (int i = 0; i < 3; i++) {
        printf("%s\n", array[i]);
    }

    return 0;
}
