#include <stdio.h>
main()
{
    int i=0, a=0;
    for(i;i<=200;i++){
        if (i%3==0 && i%2==0) {
                printf("%5d", i);a++;
                if(a==5){
                    printf("\n");a=0;
                }
        }
    }
}
