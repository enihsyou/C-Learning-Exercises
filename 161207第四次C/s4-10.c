#include <string.h>
#include <stdio.h>
main() {
    int a[3][3], *pa;
    int i,j,sum=0, k=0;
    pa = a;
    for(i=0; i<9; i++)
        scanf("%d", pa++);

    pa = a;
    for(i=0; i<9; i++) {
        printf("%4d", *pa++);
        k++;
        if(k==3) {
            printf("\n");
            k=0;
        }
    }

    for(i=0; i<3; i++) {
        for(j=0;j<3;j++){
            if(i==j || i + j ==2)
            sum += a[i][j];
        }
    }
    printf("%d", sum);
}
