#include <stdio.h>
main() {
    int i, sum = 0;
    i = 1;
    while (i <= 100) sum += i++;
    printf("The sum from 1 to 100 is %d\n", sum);
}
