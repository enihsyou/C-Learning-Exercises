#include <string.h>
#include <stdio.h>
main() {
    char names[5][20], temp[20];
    int i,j;
    for(i=0; i<5; i++)
        gets(names[i]);
    for(i=0; i<5; i++)
    for(j=i; j<5; j++){
        if(strcmp(names[i], names[j]) > 0){
            strcpy(temp,names[i]);
            strcpy(names[i],names[j]);
            strcpy(names[j],names[i]);
        }
    }
    for(i=0; i<5; i++)
        puts(names[i]);
}
