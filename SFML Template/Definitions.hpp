#pragma once

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 920

#define SPLASH_STATE_SHOW_TIME 3.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"

#define MAIN_STATE_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"

#define GAME_FONT_ARIAL_FILEPATH "Resources/fonts/arial.ttf"

#define GAME_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_START_TIME	0.5f

#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"
#define GAME_OVER_PLAY_FILEPATH "Resources/res/PlayButton.png"

#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png"

#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 1.25f

#define LAND_FILEPATH "Resources/res/Land.png"

#define BIRD_FRAME_1_FILEPATH "Resources/res/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "Resources/res/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "Resources/res/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "Resources/res/bird-04.png"

#define BIRD_ANIMATION_DURATION 0.25f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define BIRD_SCALE 0.8f

#define BIRD_GRAVITY 350.0f
#define BIRD_FLYING_SPEED 350.0f
#define BIRD_FLYING_DURATION 0.25f
#define BIRD_ROTATION_SPEED 100.0f

enum GameStates {
    STATE_READY,
    STATE_PLAYING,
    STATE_GAME_OVER
};

#define GAME_OVER_FLASH_SPEED 1000.0f