#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("�������������������");
    int i;
    scanf("%i", &i);
    int min = i%60;
    int hour =  i / 60;
    printf("%i:%i%n", hour, min);

    return 0;
}
