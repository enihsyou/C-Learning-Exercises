#include<stdio.h>
int fun(int a[], int n, int *p) {
    int days = 0, max=0, t=0,i=0, num=0;
    while (i<n) {
        printf("current: %d\n", *a);
        if(*a >= 500)days ++;
        if(*a >= 300) {
            if (*a == t) {
                if (++num > max) {
                    max = num;
                }
            } else {t = *a;num = 1;}
        }
        a++;
        i++;
    }
    printf("日消费达到500或以上的天有%d天\n",days);
    printf("日消费在300或以上的连续天数最多有%d天",num);
}
int main2() {
    int a[7] = {300, 300, 600, 100, 900, 900, 900}, n=7;
    fun(a, n, a);
    return 0;
}
