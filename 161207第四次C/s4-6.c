#include<stdio.h>
#include<string.h>
#define  ARR_SIZE   80
main() {
    char a[ARR_SIZE],temp;
    int   len, i, j;
    printf("Please enter a string: ");
    gets(a);
    len = strlen(a);//strlen�������������ַ���a�п���������ַ�����
    for ( i=0,j=len-1; i<j;  i++, j-- ) {
        temp = a[i];
        a[i]=a[j];
        a[j] = temp;
    }
    printf("The inversed string is: ");
    puts(a);
}
