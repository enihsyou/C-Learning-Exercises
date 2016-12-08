#include<stdio.h>
void main() {
    char str[81];
    int n2=0,i;
    gets(str);
    for ( i = 0; str[i] !='\0'; i++ ) {
        if (str[i]>='0' && str[i] <= '9' )
            n2 ++;
    }
    printf( "NUMBER_LETTERS=%d\n", n2 );
}
