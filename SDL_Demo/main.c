#include "sdl2game.h"
#include <stdbool.h>


#define MAX_NODES 200
typedef Image *ImageP;
typedef Sound *SoundP;
typedef Thread *ThreadP;
ImageP backGround, board, keyBlack, keyBlack_down, keyPlay, keyPlay_down, keyRecord, keyRecord_down, keyWhite,
    keyWhite_down;
SoundP C, CS, D, DS, E, F, FS, G, GS, A, AS, B;
int node_pressed = 0; // 当前按下的🎵，0为无效键；
int nodes_key[MAX_NODES]; // 记录按下的键，按顺序
Uint32 nodes_delay[MAX_NODES]; // 播放一个键之后需要暂停的毫秒数，等待之后才可以播放下一个应付
Uint32 nodes_last_time = 0; // 记录上一个键按下的时间毫秒数
Uint32 nodes_num = 0; // 已录入的音符数量
bool recording = false, playing = false;
ThreadP replay_thread = NULL;

int threadDoReplay(void *data) {
    for (int i = 0; i < nodes_num; ++i) {
        if (!playing) break;
        delay(nodes_delay[i]);
        switch (nodes_key[i]) {
            case -1:
                playtimedsound(CS, 1000);
                break;
            case -2:
                playtimedsound(DS, 1000);
                break;
            case -4:
                playtimedsound(FS, 1000);
                break;
            case -5:
                playtimedsound(GS, 1000);
                break;
            case -6:
                playtimedsound(AS, 1000);
                break;
            case 1:
                playtimedsound(C, 1000);
                break;
            case 2:
                playtimedsound(D, 1000);
                break;
            case 3:
                playtimedsound(E, 1000);
                break;
            case 4:
                playtimedsound(F, 1000);
                break;
            case 5:
                playtimedsound(G, 1000);
                break;
            case 6:
                playtimedsound(A, 1000);
                break;
            case 7:
                playtimedsound(B, 1000);
                break;
            default:
                break;
        }
    }
    playing = false;
    replay_thread = NULL;
    return 0;
}
// 初始化
void setup() {
//    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "操作说明", "上下键增减速度\n左右键移动车辆\n空格暂停。", _window);

    size(640, 480);
    title("酷炫迷你钢琴🎼");
    bgcolor(0, 0, 0);
    cursor("../image/Cur_Select_1_1.png");

    backGround = loadimage("../image/bg.png");
    board = loadimage("../image/board.png");
    keyBlack = loadimage("../image/keyblack.png");
    keyBlack_down = loadimage("../image/keyblackdown.png");
    keyPlay = loadimage("../image/keyplay.png");
    keyPlay_down = loadimage("../image/keyplaydown.png");
    keyRecord = loadimage("../image/keyrecord.png");
    keyRecord_down = loadimage("../image/keyrecorddown.png");
    keyWhite = loadimage("../image/keywhite.png");
    keyWhite_down = loadimage("../image/keywhitedown.png");

    C = loadsound("../sound/1.wav");
    CS = loadsound("../sound/1#.wav");
    D = loadsound("../sound/2.wav");
    DS = loadsound("../sound/2#.wav");
    E = loadsound("../sound/3.wav");
    F = loadsound("../sound/4.wav");
    FS = loadsound("../sound/4#.wav");
    G = loadsound("../sound/5.wav");
    GS = loadsound("../sound/5#.wav");
    A = loadsound("../sound/6.wav");
    AS = loadsound("../sound/6#.wav");
    B = loadsound("../sound/7.wav");

    bgimage("../image/bg.png");
}

// 界面绘图
void draw(float stateTime) {
    image(board, 0, 0);
    // White keys
    for (int i = 0; i < 7; ++i) {
        if (i == node_pressed - 1)
            image(keyWhite_down, 30 + 83 * i, 105);
        else
            image(keyWhite, 30 + 83 * i, 105);
    }
    // Black keys
    for (int i = 0; i < 6; ++i) {
        if (i == 2)continue;
        if (i == -node_pressed - 1)
            image(keyBlack_down, 90 + 83 * i, 105);
        else
            image(keyBlack, 90 + 83 * i, 105);
    }
    if (recording) {
        image(keyRecord_down, 340, 20);
    } else {
        image(keyRecord, 340, 20);
    }
    if (playing) {
        image(keyPlay_down, 200, 20);
    } else {
        image(keyPlay, 200, 20);
    }

}

void togglePlayState() {
    playing = !playing;
    if (playing && nodes_num > 0) { // 转入重播过程
        recording = false;
        if (replay_thread == NULL)
            replay_thread = thread(threadDoReplay, NULL);
    } else playing = false;
}

void toggleRecordState() {
    recording = !recording;
    if (recording) { // 转入录制过程
        playing = false;
        nodes_last_time = timetick(); // 记录下开始的时间
        nodes_num = 0; // 将以前记录清零
    } else { // 录制结束
        nodes_delay[nodes_num] = 0; // 把最后一个延迟设为0
    }
}
// 鼠标事件处理
void mousePress() {
    if (inbound(mouseX, mouseY, 200, 20, 97, 51)) { // Play button
        togglePlayState();
    } else if (inbound(mouseX, mouseY, 340, 20, 97, 51)) { // Record button
        toggleRecordState();
    } else if (!inbound(mouseX, mouseY, 30, 105, 83 * 7, 345)) {
        // unused area
    } else {
        int X = mouseX - 30, Y = mouseY - 105;
        if (Y <= 200) { //Black
            int t = (X + 23) / 83;
            switch (t > 0 && 83 * t + 28 >= X ? t : 0) {
                case 1:
                    node_pressed = -1;
                    playtimedsound(CS, 1000);
                    break;
                case 2:
                    node_pressed = -2;
                    playtimedsound(DS, 1000);
                    break;
                case 4:
                    node_pressed = -4;
                    playtimedsound(FS, 1000);
                    break;
                case 5:
                    node_pressed = -5;
                    playtimedsound(GS, 1000);
                    break;
                case 6:
                    node_pressed = -6;
                    playtimedsound(AS, 1000);
                    break;
                default:
                    goto SoundWhite;
            }
        } else { // White
SoundWhite:
            switch (X / 83) {
                case 0:
                    node_pressed = 1;
                    playtimedsound(C, 1000);
                    break;
                case 1:
                    node_pressed = 2;
                    playtimedsound(D, 1000);
                    break;
                case 2:
                    node_pressed = 3;
                    playtimedsound(E, 1000);
                    break;
                case 3:
                    node_pressed = 4;
                    playtimedsound(F, 1000);
                    break;
                case 4:
                    node_pressed = 5;
                    playtimedsound(G, 1000);
                    break;
                case 5:
                    node_pressed = 6;
                    playtimedsound(A, 1000);
                    break;
                case 6:
                    node_pressed = 7;
                    playtimedsound(B, 1000);
                    break;
                default:
                    return;
            }
        }
        if (recording) {
            nodes_key[nodes_num] = node_pressed;
            const Uint32 i = timetick(); // 当前时间
            nodes_delay[nodes_num] = i - nodes_last_time; // 和上一个音符之间的延迟
            nodes_last_time = i;
            if (++nodes_num == MAX_NODES) {
                recording = false;
            }
        }
    }
}


void mouseMove() {
}

void mouseRelease() {
    node_pressed = 0;
}

// 键盘事件处理函数
void keyDown() {
    switch (key) {
        case KEY_1:
            node_pressed = 1;
            playtimedsound(C, 1000);
            break;
        case KEY_2:
            node_pressed = 2;
            playtimedsound(D, 1000);
            break;
        case KEY_3:
            node_pressed = 3;
            playtimedsound(E, 1000);
            break;
        case KEY_4:
            node_pressed = 4;
            playtimedsound(F, 1000);
            break;
        case KEY_5:
            node_pressed = 5;
            playtimedsound(G, 1000);
            break;
        case KEY_6:
            node_pressed = 6;
            playtimedsound(A, 1000);
            break;
        case KEY_7:
            node_pressed = 7;
            playtimedsound(B, 1000);
            break;
        default:
            break;
    }
    if (recording) {
        nodes_key[nodes_num] = node_pressed;
        const Uint32 i = timetick(); // 当前时间
        nodes_delay[nodes_num] = i - nodes_last_time; // 和上一个音符之间的延迟
        nodes_last_time = i;
        if (++nodes_num == MAX_NODES) {
            recording = false;
        }
    }
}

void keyUp() {
    node_pressed = 0;
}

// 程序结束时回收游戏资源
void close() {
    playing = false;
    recording = false;
    if (replay_thread != NULL) waitfor(replay_thread);
    unloadimage(backGround);
    unloadimage(board);
    unloadimage(keyBlack);
    unloadimage(keyBlack_down);
    unloadimage(keyPlay);
    unloadimage(keyPlay_down);
    unloadimage(keyRecord);
    unloadimage(keyRecord_down);
    unloadimage(keyWhite);
    unloadimage(keyWhite_down);
    unloadsound(C);
    unloadsound(CS);
    unloadsound(D);
    unloadsound(DS);
    unloadsound(E);
    unloadsound(F);
    unloadsound(FS);
    unloadsound(G);
    unloadsound(GS);
    unloadsound(A);
    unloadsound(AS);
    unloadsound(B);
}

