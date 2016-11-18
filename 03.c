#include <stdio.h>
main()
{
    int i=0, a=1;
    for(i;i<10;i++){
        a += 1;
        a *= 2;
    }
    printf("%d", a);
    return 0;
}
