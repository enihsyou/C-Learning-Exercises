#include<stdio.h>
#define N 5
main() {
    int a[N];
    int i,j,t;
    for(i=0; i<N; i++)
        scanf("%d",&a[i]);
    scanf("%d",&t);
    for(i=0; i<N; i++)
        if(t == a[i]) {
            for(j=i; j<N-1; j++)
                a[j]=a[j+1];
            //__________;
        }
    for(i=0; i<N-1; i++)
        printf("%d  ",a[i]);
}
