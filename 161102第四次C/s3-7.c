#include <stdio.h>
main() {
    int i, j, tab = 25;
    int map[5][10];
    for (i = 0; i < 10; i++){
        for (j = i; j < 10; j++){
            if (i == 0) map[i][j] = 1;
            if (i == j) map[i > 4 ? 9 - i : i][j] = 1;
        }
    }
    for (i = 0; i < 5; i++){
        for (tab; tab > 0; tab--) putchar(' ');
        tab = 25;
        for (j = 0; j < 10; j++){
            if (map[i][j] == 1) putchar('*');
            else putchar(' ');
        }
        putchar('\n');
    }
}
