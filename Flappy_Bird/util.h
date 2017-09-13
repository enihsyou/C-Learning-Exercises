#ifndef SDL_DEMO_UTIL_H
#define SDL_DEMO_UTIL_H

#include <stdlib.h>


typedef struct {
    int pipe_x;
    int pipe_y;
    int gap_size;
    SDL_bool passed;
} Pipe;
typedef struct {
    Image* upflap, *midflap, *downflap;
} BirdSprites;
int random_int(int min, int max) {
    return min + rand() % (max + 1 - min);
}
#endif //SDL_DEMO_UTIL_H
