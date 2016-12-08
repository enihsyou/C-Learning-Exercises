#include <stdio.h>
main()
{int n=100, a[n], i, j, k, t;
  int min,max;
  for (i=0;i<n;i++)
     scanf("%d",&a[i]);  //ÊäÈë
  max=0;
  min=0;
  for (i=0;i<n;i++)
    {  if(a[i]>max)  max=a[i];
       else if(a[i]<min) min=a[i];
    }
   printf("the max is %d\n",max);
   printf("the min is %d\n",min);  //Êä³ö
}
