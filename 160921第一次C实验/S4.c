#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("输入分钟数（整数）：");
    int i;
    scanf("%i", &i);
    int min = i%60;
    int hour =  i / 60;
    printf("%i:%i%n", hour, min);

    return 0;
}
