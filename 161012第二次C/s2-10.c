#include "stdio.h"
#include "math.h"
main ()
{
    int a, mod, i, mul = 1000,sum = 0;
    printf("����һ����λ����");
    scanf("%d", &a);
    for(i = 0; i<4; i++)
    {
        sum += a/mul;
        a = a%mul;
        mul /= 10;
    }
    printf("\n%d", sum);
}
