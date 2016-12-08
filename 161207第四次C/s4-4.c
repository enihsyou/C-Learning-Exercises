#include<stdio.h>
#define N 100
main() {
    int a[N],i,b;
    int f, k;
    for(i=0; i<N; i++)
        scanf("%d",&a[i]);
    scanf("%d",&b);
    for(i=0; i<N; i++) {
        if(b==a[i]) {
            f=1;
            k=i;
        }
    }
    if(f == 1)
        printf("b is on the %d location",k+1);
    else  printf("b is not in the a");
}
