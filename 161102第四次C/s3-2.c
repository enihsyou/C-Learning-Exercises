#include <stdio.h>
main() {
    int a, b, c, max;
    printf("Please input three integers: \n");
    scanf("%d%d%d", &a, &b, &c);
    max = a;
    if (c > b) max = c > a ? c : a;
    else max = b > a ? b : a;
    printf("The max number is %d", max);
}
