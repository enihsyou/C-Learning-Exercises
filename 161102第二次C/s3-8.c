#include <stdio.h>
main() {
    int i = 10 ,a, dig = 0;
    printf("Input a number: ");
    scanf("%d", &a);
    do {
        printf("%d", a % i);
        a /= i;
        dig++;
    } while(a);
    printf("\n%d digits", dig);
}
