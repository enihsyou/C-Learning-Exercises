#include <stdio.h>
main()
{
    int i=0, a=0,sum=0,piv=10;
    printf("输入一个整数");
    scanf("%d", &i);
    for(a;a<10;a++){
        sum += i % piv;
        i /= piv;
        if(i == 0) break;
    }
    printf("%d", sum);
    return 0;
}
