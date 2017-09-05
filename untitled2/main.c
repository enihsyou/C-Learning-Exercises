#include <math.h>
#include "sdl2game.h"

Image *heart;

// 初始化
void setup() {
    title("💕忽明忽暗的爱心斑马线❤");
    size(640, 480);
    bgcolor(69, 69, 69);
    bgimage("../image/road.png");
    cursor("../image/Cur_Select_1_1.png");
    heart = loadimage("../image/Checkered_Heart_PNG_Clipart-1013_resize.png");
}

// 界面绘图
void draw(float stateTime) {
    for (int i = 0; i < 9; ++i)
        coloredfillrect(360, 70 + 40 * i, 151, 20, 252, 253, 248, 251, 175, 40);
    printf("%f\n", stateTime);
    imagea(heart, 100, 100,(Uint8)(128 + 128 *cosf(stateTime)));
}

// 鼠标事件处理
void mousePress() {
}

void mouseMove() {
}

void mouseRelease() {
}

// 键盘事件处理函数
void keyDown() {
}

void keyUp() {
}

// 程序结束时回收游戏资源
void close() {
    unloadimage(heart);
}

