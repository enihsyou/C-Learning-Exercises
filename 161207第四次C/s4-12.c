#include <string.h>
#include <stdio.h>
main() {
    int a[8], *left, *right, tmp,scanfor;
    int i,j;

    for(i =0,left = a; i<8; i++) {
        scanf("%d", left++);
    }
    for(i = 0, left=a; i<8; i++,left++)
        for(j=i,right = a+i; j<8; j++,right++)
            if(*left > *right) {
                tmp = *left;
                *left =*right;
                *right = tmp;
            }
    for(i=0,left = a; i<8; i++) {
        printf("%5d", *left++);
    }
    scanf("%d", &scanfor);
    left =a;
    right=a+8;
    while(*left<*right) {
        if(*(left+(right-left)/2) > scanfor) {
            right =left + (right-left)/2;
        } else if(*(left+(right-left)/2) == scanfor) {
            return scanfor;
        } else {
            left = left + (right-left)/2;
        }
    }
    return -1;
}
