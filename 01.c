#include <stdio.h>
main()
{
    int i=2, j=1,k=3;
    printf("%d", i&&((i+j)&&k||i+j));
}
