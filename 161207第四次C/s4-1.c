#include "stdio.h"
main()
{
float x[100],sum=0.0,ave,a;
int n=0,i;
printf("enter mark:\n");
while(a>0.0&&n<100)
{
scanf("%f",&a);x[n]=a;
sum=sum+a;
n++;
}
ave=sum/n;
printf("%f\n",ave);
printf("output:\n");
for(i=0;i<n;i++){
if (ave>x[i])
printf("%f\n",x[i]);}
}
