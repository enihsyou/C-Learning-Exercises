#include <stdio.h>
int main() {
    int a[20], i, j; long d;
    printf("\n");
    scanf("%ld", &d); //获取数字
    for (i = 0; d; i++) {
        a[i] = d % 10; //写入数字到数组
        d /= 10;
    }
    for (j = 0; j < i; j++) {
        if (a[j] != a[i - j - 1]) {
            break;
        }
    }
    if (i == j) {
        printf("is 回文\n");
    }
    return 0;
}
