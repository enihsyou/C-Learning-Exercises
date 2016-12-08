#include <string.h>
#include <stdio.h>
main() {
    int a[100] = {1}, *pa, right, tmp;
    int i,j;

    for(i=0; i<10; i++) {
        pa = a;
        while(*pa != 0) printf("%5d", *pa++);
        printf("\n");
        pa = a;
        right = *pa++;
        while(*pa != 0){
            tmp  = *pa;
            *pa = *pa + right;
            right = tmp;
            pa++;
        }
        *pa = 1;
    }
}
