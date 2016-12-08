#include<stdio.h>
main() {
    int a[10], i;
    for(i=0; i<10; i++)
        scanf("%d",&a[i]);
    for(i=0; i<10; i++) {
        if(i%2==0)
            printf("%4d", a[i]);
    }
    printf("\n");
    for(i=0; i<10; i++) {
        if(i%2==0) continue;
        printf("%4d", a[i]);
    }
}
