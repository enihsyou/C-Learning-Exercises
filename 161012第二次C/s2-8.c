#include "stdio.h"
main ()
{
    double fahrenheit,celsius ;
    printf("���뻪���¶ȣ�");
    scanf("%lf", &fahrenheit);
    printf("%.2lfF = %.2lfC", fahrenheit, (fahrenheit - 32)*5/9);
}
