#include "stdio.h"
#include "math.h"
main ()
{
    double a,b,c,d,x1,x2;
    printf(" ‰»Îa,b,c\n>>>");
    scanf("%lf%lf%lf", &a,&b,&c);
    printf("\ta=%.2lf, b=%.2lf, c=%.2lf\n", a,b,c);
    d = b*b - 4*a*c;
    if(d>0)
    {
        d=sqrt(d);
        x1= (-b+d)/a/2;
        x2= (-b-d)/a/2;
        printf("\n\tx1=%.2lf\n\tx2=%.2lf",x1,x2);
    }
    else
    {
        printf(" ‰»Î”–ŒÛ");
    }
}
