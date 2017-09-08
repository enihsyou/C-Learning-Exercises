#include "sdl2game.h"
#include <math.h>
#include <stdbool.h>


typedef Image *ImageP;
typedef Sound *SoundP;
SDL_Surface *car_surface;
ImageP car, road, scene, front_wheel, rear_wheel;
SoundP horn, engine;
double angel;
int carSpeed = 2, carPosition = 200, foreground_offset, background_offset;
bool isDriving = TRUE;

// 初始化
void setup() {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "操作说明", "上下键增减速度\n左右键移动车辆\n空格暂停。", _window);
    car_surface = IMG_Load("../image/car.png");
    car = SDL_CreateTextureFromSurface(_canvas, car_surface);

    size(640, 200);
    title("欢快小跑车🚕");
    bgcolor(0, 0, 0);
    road = loadimage("../image/road.png");
    scene = loadimage("../image/scene2.png");
    front_wheel = loadimage("../image/wheel2.png");
    rear_wheel = loadimage("../image/wheel1.png");
    horn = loadsound("../sound/horn.wav");
    engine = loadsound("../sound/enginestart.mp3");
    SDL_SetWindowIcon(_window, car_surface);
    playsound(engine);
    bgmusic("../sound/driving.mp3");
}

// 界面绘图
void draw(float stateTime) {
    const int WIDTH = 1280;

    image(road, foreground_offset, 115);
    if (carSpeed > 0)
        image(road, WIDTH + foreground_offset, 115); // 2 buffer
    if (carSpeed < 0)
        image(road, -WIDTH + foreground_offset, 115); // 2 buffer

    image(scene, background_offset, 0);
    if (foreground_offset <= 640 - WIDTH) foreground_offset = 0;
    if (foreground_offset > 0) foreground_offset = -640;
    if (background_offset <= 640 - WIDTH) background_offset = 0;
    if (background_offset > 0) background_offset = -640;


    image(car, carPosition, 70);
    imagerotated(front_wheel, carPosition + 29, 70 + 51, angel);
    imagerotated(rear_wheel, carPosition + 167, 70 + 51, angel);

    if (isDriving) {
        foreground_offset -= carSpeed;
        background_offset -= carSpeed / 2;
        angel = fmod(angel + carSpeed / (M_PI * 39 / 360), 360);
    }
}

// 鼠标事件处理
void mousePress() {
    if (!inbound(mouseX, mouseY, carPosition, 70, 226, 110))
        return;

    // 鼠标下的像素
    Uint32 pixel = *(Uint32 *) (car_surface->pixels + (mouseY - 70) * car_surface->pitch + (mouseX - carPosition) * 4);
    Uint8 r, g, b, a;
    SDL_GetRGBA(pixel, car_surface->format, &r, &g, &b, &a);
    if (a > 224 ||
        inbound(mouseX, mouseY, carPosition + 29, 70 + 51, 29, 29) ||
        inbound(mouseX, mouseY, carPosition + 167, 70 + 51, 29, 29))
        playsound(horn);
}

void mouseMove() {
}

void mouseRelease() {
}

// 键盘事件处理函数
void keyDown() {
    switch (key) {
        case KEY_SPACE:
            isDriving = !isDriving;
            break;
        case KEY_RIGHT:
            if (carPosition < 640 - 226) {
                carPosition += 3;
                angel = fmod(angel + carSpeed, 360);
            }
            break;
        case KEY_LEFT:
            if (carPosition > 0) {
                carPosition -= 3;
                angel = fmod(angel - carSpeed, 360);
            }
            break;
        case KEY_UP:
            if (carSpeed < 20)
                carSpeed++;
            break;
        case KEY_DOWN:
            if (carSpeed > -20)
                carSpeed--;
            break;
        default:
            break;
    }
}

void keyUp() {
}

// 程序结束时回收游戏资源
void close() {
    unloadimage(car);
    unloadimage(road);
    unloadimage(scene);
    unloadimage(front_wheel);
    unloadimage(rear_wheel);
    unloadsound(horn);
    unloadsound(engine);
    SDL_FreeSurface(car_surface);
}

