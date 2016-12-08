#include <stdio.h>
#include <math.h>
long factorial(int n){
    long sum = 1;
    for (n; n > 1; n--)
        sum *= n;
    return sum;
}
e(int x) {
    int i = 1;
    long a, b;
    double sum = 1, temp;
    do {
        a = factorial(i);
        b = pow(x, i);
        temp = (double) b / a;
        sum += temp;
        i++;
    } while(temp >= 10e-6);
    printf("%.6lf", sum);
}
main() {
    e(1);
}
