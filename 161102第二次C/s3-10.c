#include <stdio.h>
int input_number(){
    int n, dig = 0, result;
    printf("Input number: ");
    scanf("%d", &n);
    result = n;
    do {
        n /= 10;
        dig++;
    } while(n);
    if (dig != 6) return input_number();
    else return result;
}
main() {
    int n, a, b;
    n = input_number();
    a = n / 1000;
    b = n % 1000;
    printf("%d, ²ð·Ö³É:%d %d\n", n,a,b);

    printf("sum=%d, sub=%d, multi=%d\n", a+b,a-b,a*b);
    if (b == 0) printf("The second operator is zero!");
    else printf("dev=%.2lf, mod=%d", (double)a/b, a%b);
}
