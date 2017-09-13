/*By 九条涼果 @enihsyou*/
#include <math.h>
#include "sdl2game.h"
#include "util.h"
#include "queue.h"


#define SCREEN_HEIGHT  512
#define SCREEN_WIDTH 288
#define BIRD_HEIGHT 24
#define BIRD_WIDTH 34
#define BIRD_X_DEFAULT_OFFSET 60
#define BIRD_Y_DEFAULT_OFFSET 180
#define PIPE_HEIGHT 320
#define PIPE_WIDTH 52
#define FONT_WIDTH 24
#define SMALL_FONT_WIDTH 12
#define BASE_OFFSET (SCREEN_HEIGHT - 112)
#define PIPE_GAP_SIZE 100
#define PIPE_X_GAP ((SCREEN_WIDTH + PIPE_WIDTH) / 2)

typedef Image *ImageP;
typedef Sound *SoundP;
typedef Thread *ThreadP;
typedef enum {
    PREPARING, GAMING, DEAD, QUITING
} GAME_STATE;

/*程序用变量*/
ImageP
    img_background, img_scoreboard, img_base, img_bird, img_pipe, img_splash, img_replay,
    img_medal_bronze, img_medal_silver, img_medal_gold, img_medal_platinum,
    N_0, N_1, N_2, N_3, N_4, N_5, N_6, N_7, N_8, N_9,
    N_M_0, N_M_1, N_M_2, N_M_3, N_M_4, N_M_5, N_M_6, N_M_7, N_M_8, N_M_9;
SoundP
    sfx_wing, sfx_swooshing, sfx_hit, sfx_die, sfx_score;

ThreadP threadLoop;

/*备选项*/
ImageP
    _img_background_day, _img_background_night,
    _img_pipe_green, _img_pipe_red,
    _img_bird_blue_downflap, _img_bird_blue_midflap, _img_bird_blue_upflap,
    _img_bird_red_downflap, _img_bird_red_midflap, _img_bird_red_upflap,
    _img_bird_yellow_downflap, _img_bird_yellow_midflap, _img_bird_yellow_upflap;
SoundP
    _sfx_hit1, _sfx_hit2,
    _sfx_die1, _sfx_die2;

/*常量和变量*/
GAME_STATE current_state = PREPARING;

const double GRAVITY = 0.4;
const int PIPE_MOVE_INTERVAL = 3, JUMPING_ABILITY = 5;

double velocity = 0.0, position = BIRD_Y_DEFAULT_OFFSET, base_offset = 0.0;
int rotation = 0, score = 0, high_score = 0, base_shift = 336 - 288;
SDL_Rect player_collision_box, pipe_collision_box;
//Uint8 opacity = 255;

Image *getImageFromNumber(int integer) {
    switch (integer) {
        case 0:
            return N_0;
        case 1:
            return N_1;
        case 2:
            return N_2;
        case 3:
            return N_3;
        case 4:
            return N_4;
        case 5:
            return N_5;
        case 6:
            return N_6;
        case 7:
            return N_7;
        case 8:
            return N_8;
        case 9:
            return N_9;
        default:
            return NULL;
    }
}

Image *getSmallImageFromNumber(int integer) {
    switch (integer) {
        case 0:
            return N_M_0;
        case 1:
            return N_M_1;
        case 2:
            return N_M_2;
        case 3:
            return N_M_3;
        case 4:
            return N_M_4;
        case 5:
            return N_M_5;
        case 6:
            return N_M_6;
        case 7:
            return N_M_7;
        case 8:
            return N_M_8;
        case 9:
            return N_M_9;
        default:
            return NULL;
    }
}

/*随机管子数据的生成器*/
Pipe getRandomPipe() {
    Pipe result;
    result.gap_size = PIPE_GAP_SIZE;
    result.pipe_x = SCREEN_WIDTH;
    result.pipe_y = SCREEN_HEIGHT - PIPE_HEIGHT + random_int(-70, 70);
    result.passed = SDL_FALSE;
    return result;
}

/*deprecated画面元素淡入*/
int easeInTransition(void *ptr) {
    Uint8 *opacity = (Uint8 *) ptr;
    while (*opacity < 245) {
        *opacity += 15;
        delay(1000 / 60);
    }
    *opacity = 255;
    return 0;
}

/*deprecated画面元素淡出*/
int easeOutTransition(void *ptr) {
    Uint8 *opacity = (Uint8 *) ptr;
    while (*opacity > 10) {
        *opacity -= 15;
        delay(1000 / 60);
    }
    *opacity = 0;
    return 0;
}

/*显示初始屏幕，并将数据重置*/
void drawSplash();
/*在游戏中屏幕上部绘制大号的分数数字*/
void drawScore();
/*在画面中绘制管道*/
void drawPipes();
/*游戏结束后绘制分数版*/
void drawHighScore();
/*游戏结束，设置最高分，设置结束时的画面*/
void birdDead();
/*处理鸟撞到管子上的事件*/
void birdHit();
/*处理鸟掉落到地上的事件*/
void birdDrop();
/*处理玩家得分事件*/
void birdScore();
/*小鸟向上跳一下*/
void birdJump();
/*处理元素的线程函数*/
int gameLoop(void *ptr);
/*循环切换鸟图*/
int birdSpriteRoll(void *ptr);
/*玩家决定开始游戏*/
void startGame();
/*玩家决定再次进行游戏*/
void restartGame();


void drawSplash() {
    image(img_splash, (SCREEN_WIDTH - 184) / 2, (SCREEN_HEIGHT - 267) / 2);
    image(img_bird, BIRD_X_DEFAULT_OFFSET, BIRD_Y_DEFAULT_OFFSET);
}

void drawScore() {
    int digits = score > 9 ? (int) log10(abs(score)) + 1 : 1;
    int total_width = FONT_WIDTH * digits; // 数字1的宽度是16，不做特殊处理了
    int x_offset = (SCREEN_WIDTH - total_width) / 2;
    for (int i = digits - 1, div = score; i >= 0; --i, div /= 10) {
        image(getImageFromNumber(div % 10), x_offset + FONT_WIDTH * i, SCREEN_HEIGHT / 10);
    }
}

void birdDead() {
    current_state = DEAD;
    if (score > high_score) high_score = score;
}

void birdHit() {
    playsound(sfx_hit);
    birdDead();
}

void birdDrop() {
    playsound(sfx_die);
    birdDead();
}

void birdScore() {
    playsound(sfx_score);
    score += 1;
}


int gameLoop(void *ptr) {
    pipeEnqueue(getRandomPipe());
    Pipe pipe2 = getRandomPipe();
    pipe2.pipe_x += PIPE_X_GAP;
    pipeEnqueue(pipe2);

    while (current_state == GAMING) {
        velocity += GRAVITY;
        position += velocity;

        rotation = (int) (min(8 * velocity, 90));

        const double rad = rotation * M_PI / 180.0;
#ifdef DEBUG_MODE
        printf("%d, %f \n", rotation, rad);
#endif
        const int
            bird_box_width = (int) (BIRD_WIDTH - sin(rad) * 8),
            bird_box_height = (int) (BIRD_HEIGHT + sin(rad) * 8),
            bird_box_left = (BIRD_WIDTH - bird_box_width) / 2 + BIRD_X_DEFAULT_OFFSET,
            bird_box_top = (int) ((BIRD_HEIGHT - bird_box_height) / 2 + position),
            bird_box_right = bird_box_left + bird_box_width,
            bird_box_bottom = bird_box_top + bird_box_height;
        player_collision_box = (SDL_Rect)
            {bird_box_left, bird_box_top, bird_box_width, bird_box_height};

        /*鸟碰到了地面，游戏结束*/
        if (bird_box_bottom >= BASE_OFFSET) {
            birdDrop();
            goto terminate_process;
        }
//        /*鸟碰到了天顶，不再继续上升*/
//        if (bird_box_top <= CEILING_HEIGHT) {
//            position = 0;
//        }
        /*获取到下一个没有穿越过去的tunnel*/
        struct PipeQueueNode *temp_node = frontElement();
        while (temp_node->ptr && temp_node->info.passed) {
            temp_node = temp_node->ptr;
        }
        Pipe *next_pipe = &(temp_node->info);
        /*这是管道之间的矩形空间，进行碰撞判断*/
        const int
            pipe_box_top = next_pipe->pipe_y - PIPE_GAP_SIZE,
            pipe_box_left = next_pipe->pipe_x,
            pipe_box_right = pipe_box_left + PIPE_WIDTH,
            pipe_box_bottom = next_pipe->pipe_y;
        pipe_collision_box = (SDL_Rect)
            {pipe_box_left, pipe_box_top, PIPE_WIDTH, next_pipe->gap_size};

        //计划不使用SDL_IntersectRectAndLine()
        /*已经在判定框内了，只能从中间通过*/
        if (bird_box_right > pipe_box_left) {
            /*鸟撞到了上下边框*/
            if (bird_box_top <= pipe_box_top || bird_box_bottom >= pipe_box_bottom) {
                birdHit();
                // thread(easeInTransition, (void *) opacity);
                while (position < BASE_OFFSET - bird_box_height) {
                    velocity += GRAVITY;
                    position += velocity;
                    delay(1000 / 60);
                }
                goto terminate_process;
            }
        }
        /*鸟已经通过了管道，计算得分*/
        if (bird_box_left > pipe_box_right) {
            next_pipe->passed = SDL_TRUE;
            birdScore();
        }
        /*把所有管道都左移一段距离*/
        if (!isQueueEmpty()) {
            struct PipeQueueNode *pipe = frontElement();
            while (1) {
                pipe->info.pipe_x -= PIPE_MOVE_INTERVAL;
                if (!pipe->ptr) break;
                pipe = pipe->ptr;
            }
        }
        base_offset = -((int) (-base_offset + PIPE_MOVE_INTERVAL) % base_shift);
        /*已经从左边出屏幕的管道会被移除*/
        if (!isQueueEmpty() && frontElement()->info.pipe_x < -5 - PIPE_WIDTH) {
            pipeDeque();
            pipeEnqueue(getRandomPipe());
        }
        SDL_Delay(1000 / 60);
    }
terminate_process:
    current_state = DEAD;
    threadLoop = NULL;
    return 0;
}

void birdJump() {
    playsound(sfx_wing);
    velocity = -JUMPING_ABILITY;
}

void startGame() {
    playsound(sfx_swooshing);
    current_state = GAMING;

    threadLoop = thread(gameLoop, NULL);
//    thread(easeOutTransition, (void *) &opacity);
    birdJump();
}

BirdSprites birdSprites[3];
int bird_sprite_index = 0;

// 初始化
void setup() {
    srand(timetick());

    size(SCREEN_WIDTH, SCREEN_HEIGHT);
    title("Flappy Bird");
    bgcolor(0, 0, 0);
    cursor("image/cursor.png");
    Bitmap *b = loadbitmap("image/yellowbird-midflap.png");
    SDL_SetWindowIcon(_window, b);
    SDL_FreeSurface(b);

    _img_background_day = loadimage("image/background-day.png");
    _img_background_night = loadimage("image/background-night.png");
    _img_pipe_green = loadimage("image/pipe-green.png");
    _img_pipe_red = loadimage("image/pipe-red.png");
    _img_bird_blue_downflap = loadimage("image/bluebird-downflap.png");
    _img_bird_blue_midflap = loadimage("image/bluebird-midflap.png");
    _img_bird_blue_upflap = loadimage("image/bluebird-upflap.png");
    _img_bird_red_downflap = loadimage("image/redbird-downflap.png");
    _img_bird_red_midflap = loadimage("image/redbird-midflap.png");
    _img_bird_red_upflap = loadimage("image/redbird-upflap.png");
    _img_bird_yellow_downflap = loadimage("image/yellowbird-downflap.png");
    _img_bird_yellow_midflap = loadimage("image/yellowbird-midflap.png");
    _img_bird_yellow_upflap = loadimage("image/yellowbird-upflap.png");
    birdSprites[0] = (BirdSprites)
        {.upflap=_img_bird_yellow_upflap, .midflap=_img_bird_yellow_midflap, .downflap = _img_bird_yellow_downflap};
    birdSprites[1] = (BirdSprites)
        {.upflap=_img_bird_blue_upflap, .midflap=_img_bird_blue_midflap, .downflap = _img_bird_blue_downflap};
    birdSprites[2] = (BirdSprites)
        {.upflap=_img_bird_red_upflap, .midflap=_img_bird_red_midflap, .downflap = _img_bird_red_downflap};

    img_background = _img_background_day;
    img_bird = _img_bird_yellow_midflap;
    img_pipe = _img_pipe_green;
    img_scoreboard = loadimage("image/scoreboard.png");
    img_base = loadimage("image/base.png");
    img_splash = loadimage("image/message.png");
    img_replay = loadimage("image/replay.png");

    img_medal_bronze = loadimage("image/medal_bronze.png");
    img_medal_silver = loadimage("image/medal_silver.png");
    img_medal_gold = loadimage("image/medal_gold.png");
    img_medal_platinum = loadimage("image/medal_platinum.png");

    N_0 = loadimage("image/0.png");
    N_1 = loadimage("image/1.png");
    N_2 = loadimage("image/2.png");
    N_3 = loadimage("image/3.png");
    N_4 = loadimage("image/4.png");
    N_5 = loadimage("image/5.png");
    N_6 = loadimage("image/6.png");
    N_7 = loadimage("image/7.png");
    N_8 = loadimage("image/8.png");
    N_9 = loadimage("image/9.png");
    N_M_0 = loadimage("image/font_small_0.png");
    N_M_1 = loadimage("image/font_small_1.png");
    N_M_2 = loadimage("image/font_small_2.png");
    N_M_3 = loadimage("image/font_small_3.png");
    N_M_4 = loadimage("image/font_small_4.png");
    N_M_5 = loadimage("image/font_small_5.png");
    N_M_6 = loadimage("image/font_small_6.png");
    N_M_7 = loadimage("image/font_small_7.png");
    N_M_8 = loadimage("image/font_small_8.png");
    N_M_9 = loadimage("image/font_small_9.png");

    _sfx_hit1 = loadsound("sound/sfx_hit.ogg");
    _sfx_die1 = loadsound("sound/sfx_die.ogg");
    _sfx_hit2 = loadsound("sound/fart.mp3");
    _sfx_die2 = loadsound("sound/squeak.mp3");
    sfx_wing = loadsound("sound/sfx_wing.ogg");
    sfx_swooshing = loadsound("sound/sfx_swooshing.ogg");
    sfx_score = loadsound("sound/sfx_point.ogg");
    sfx_hit = _sfx_hit1;
    sfx_die = _sfx_die1;

    createPipeQueue();
    current_state = PREPARING;
    thread(birdSpriteRoll, NULL);
}

int birdSpriteRoll(void *ptr) {
    Uint32 delay_ms = 1000 / 10;
    while (current_state != DEAD) {
        img_bird = birdSprites[bird_sprite_index].upflap;
        delay(delay_ms);
        img_bird = birdSprites[bird_sprite_index].midflap;
        delay(delay_ms);
        img_bird = birdSprites[bird_sprite_index].downflap;
        delay(delay_ms);
    }
    return 0;
}

void drawPipes() {
    if (!isQueueEmpty()) {
        struct PipeQueueNode *pipe = frontElement();
        while (1) {
            image(img_pipe,
                  pipe->info.pipe_x,
                  pipe->info.pipe_y);
            imagerotated(img_pipe,
                         pipe->info.pipe_x,
                         pipe->info.pipe_y - PIPE_HEIGHT - pipe->info.gap_size, 180);
            if (!pipe->ptr) break;
            pipe = pipe->ptr;
        }
    }
}

void drawHighScore() {
    image(img_scoreboard, (SCREEN_WIDTH - 236) / 2, (SCREEN_HEIGHT - 280) / 2);
    image(img_replay, (SCREEN_WIDTH - 115) / 2, (SCREEN_HEIGHT + 280) / 2);
    int digits = score > 9 ? (int) log10(abs(score)) + 1 : 1;
    int total_width = SMALL_FONT_WIDTH * digits;
    int x_offset = 236 - total_width;
    for (int i = digits - 1, div = score; i >= 0; --i, div /= 10) {
        image(getSmallImageFromNumber(div % 10), x_offset + SMALL_FONT_WIDTH * i, 228);
    }
    digits = high_score > 9 ? (int) log10(abs(high_score)) + 1 : 1;
    total_width = SMALL_FONT_WIDTH * digits;
    x_offset = 236 - total_width;
    for (int i = digits - 1, div = high_score; i >= 0; --i, div /= 10) {
        image(getSmallImageFromNumber(div % 10), x_offset + SMALL_FONT_WIDTH * i, 270);
    }
    if (score < 10) return;
    ImageP medal = NULL;
    if (score >= 10) medal = img_medal_bronze;
    if (score >= 20) medal = img_medal_silver;
    if (score >= 30) medal = img_medal_gold;
    if (score >= 40) medal = img_medal_platinum;
    image(medal, 58, 230);
}

// 界面绘图
void draw(float stateTime) {
    image(img_background, 0, 0);

    switch (current_state) {
        case PREPARING:
            image(img_base, base_offset, BASE_OFFSET);
            drawSplash();
            break;
        case GAMING:
//            if (0 < opacity < 255) drawSplash();
            drawPipes();
            imagerotated(img_bird, BIRD_X_DEFAULT_OFFSET, position, rotation);
            image(img_base, base_offset, BASE_OFFSET);
            drawScore();

            /*在DEBUG模式下，用红线框描绘出碰撞检测边框*/
#ifdef DEBUG_MODE
        color(255, 0, 0);
        SDL_RenderDrawRect(_canvas, &player_collision_box);
        SDL_RenderDrawRect(_canvas, &pipe_collision_box);
#endif
            break;
        case DEAD:
//            if (0 < opacity < 255) drawHighScore();
            drawPipes();
            imagerotated(img_bird, BIRD_X_DEFAULT_OFFSET, position, rotation);
            image(img_base, base_offset, BASE_OFFSET);
            drawHighScore();
            break;
        default:
            break;
    }
}

void restartGame() {
    playsound(sfx_swooshing);
    if (threadLoop != NULL) waitfor(threadLoop);
    velocity = 0;
    position = BIRD_Y_DEFAULT_OFFSET;
    rotation = 0;
    score = 0;
    clearQueue();
    img_background = rand() % 2 ? _img_background_day : _img_background_night;
    img_pipe = rand() % 2 ? _img_pipe_green : _img_pipe_red;
    bird_sprite_index = rand() % 3;
    img_bird = birdSprites[bird_sprite_index].midflap;
    sfx_hit = rand() % 2 ? _sfx_hit1 : _sfx_hit2;
    sfx_die = rand() % 2 ? _sfx_die1 : _sfx_die2;
    current_state = GAMING;
    threadLoop = thread(gameLoop, NULL);
    thread(birdSpriteRoll, NULL);

//    thread(easeOutTransition, (void *) &opacity);
    birdJump();
}

// 鼠标事件处理
void mousePress() {
    switch (current_state) {
        case PREPARING:
            startGame();
            break;
        case GAMING:
            birdJump();
            break;
        case DEAD:
            if (inbound(mouseX, mouseY, (SCREEN_WIDTH - 115) / 2 + 5, (SCREEN_HEIGHT + 280) / 2 + 2, 105, 60))
                restartGame();
            break;
        default:
            return;
    }
}

void mouseMove() { }

void mouseRelease() { }

// 键盘事件处理函数
void keyDown() {
    switch (key) {
        case KEY_SPACE:
            if (current_state == PREPARING) startGame();
            if (current_state == GAMING) birdJump();
            if (current_state == DEAD) restartGame();
            break;
        case KEY_ESC:
            current_state = QUITING;
            return;
        case KEY_R:
            restartGame();
            break;
        default:
            return;
    }
}

void keyUp() {}

// 程序结束时回收游戏资源
void close() {
    unloadimage(_img_background_day);
    unloadimage(_img_background_night);
    unloadimage(_img_pipe_green);
    unloadimage(_img_pipe_red);
    unloadimage(_img_bird_blue_downflap);
    unloadimage(_img_bird_blue_midflap);
    unloadimage(_img_bird_blue_upflap);
    unloadimage(_img_bird_red_downflap);
    unloadimage(_img_bird_red_midflap);
    unloadimage(_img_bird_red_upflap);
    unloadimage(_img_bird_yellow_downflap);
    unloadimage(_img_bird_yellow_midflap);
    unloadimage(_img_bird_yellow_upflap);
    unloadimage(img_scoreboard);
    unloadimage(img_base);
    unloadimage(img_splash);
    unloadimage(img_replay);
    unloadimage(img_medal_bronze);
    unloadimage(img_medal_silver);
    unloadimage(img_medal_gold);
    unloadimage(img_medal_platinum);
    unloadimage(N_0);
    unloadimage(N_1);
    unloadimage(N_2);
    unloadimage(N_3);
    unloadimage(N_4);
    unloadimage(N_5);
    unloadimage(N_6);
    unloadimage(N_7);
    unloadimage(N_8);
    unloadimage(N_9);
    unloadimage(N_M_0);
    unloadimage(N_M_1);
    unloadimage(N_M_2);
    unloadimage(N_M_3);
    unloadimage(N_M_4);
    unloadimage(N_M_5);
    unloadimage(N_M_6);
    unloadimage(N_M_7);
    unloadimage(N_M_8);
    unloadimage(N_M_9);
    unloadsound(_sfx_hit1);
    unloadsound(_sfx_die1);
    unloadsound(_sfx_hit2);
    unloadsound(_sfx_die2);
    unloadsound(sfx_wing);
    unloadsound(sfx_swooshing);
    unloadsound(sfx_score);
}

