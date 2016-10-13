#include "stdio.h"
main()
{
	char x,y,z;
	x='a';
	y='\t';   //请阅读书上19页表1-1
	z='b';
	printf("第1行为：%c%c%c\n",x,y,z);
    printf("第2行为：%c%c%c%c\n",x,y,y,z);
}
