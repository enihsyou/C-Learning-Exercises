#include "stdio.h"
main ()
{
    int a,b,c,temp;
    printf("Please input a,b,c: ");
    scanf("%d%d%d",&a,&b,&c);
    temp = a;
    a=c;
    c=b;
    b=temp;
    printf("a=%d b=%d c=%d\n",a,b,c);
}
