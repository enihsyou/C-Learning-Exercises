#include<stdio.h>
main() {
    int a[10],b[9], i,j=0,k=0;
    for(i=0; i<10; i++)
        scanf("%d",&a[i]);
    for(i=1; i<10; i++) {
        b[j++] = a[i-1] / a[i];
    }
    for(i=0; i<10; i++) {
        printf("%4d", a[i]);
    }
    printf("\n");
    for(j=0; j<9; j++) {
        printf("%4d", b[j]);
        k++;
        if(k == 3) {
            printf("\n");
            k=0;
        }
    }
}
