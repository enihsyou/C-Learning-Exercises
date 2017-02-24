#include<stdio.h>
int main1() {
    int a,b,c, k;
    scanf("%d %d %d", &a, &b, &c);
    k = a^b^c;
    if (k == a)
        puts("A");
    else if (k == b)
        puts("B");
    else if (k == c)
        puts("C");
    return 0;
}
