#include "stdio.h"
main ()
{
    double fahrenheit,celsius ;
    printf("ÊäÈë»ªÊÏÎÂ¶È£º");
    scanf("%lf", &fahrenheit);
    printf("%.2lfF = %.2lfC", fahrenheit, (fahrenheit - 32)*5/9);
}
