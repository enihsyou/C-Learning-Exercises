#include <stdio.h>
main() {
    float a, b;
    int i, f = 0;
    printf("请主持人输入时尚手机的实际价格\n");
    scanf("%f", &b);
    system("cls");
    for (i = 1; i <= 3; i++) {
        printf("\n\n请观众猜时尚手机的价格\n");
        scanf("%f", &a);
        if(a < b) printf("低了\n");
        if(a == b) {
            printf("猜对了!\n");
            f = 1;
            break;
        }
        if(a > b) printf("高了\n");
    }
    if(f != 1)printf("你输了，加油！\n");
    system("pause");
}
