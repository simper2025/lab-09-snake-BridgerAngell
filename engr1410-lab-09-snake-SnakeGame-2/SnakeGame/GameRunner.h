#pragma once

#include "Keyboard.h"
#include "Snake.h"
#include "Mouse.h"

class GameRunner
{
private:
    bool gameOver;
    float delaySeconds;  // fraction of a second to sleep each loop
    Snake snake;
    Mouse mouse;
    KeyCommand keyPress;

    static const int WIDTH = 80;
    static const int HEIGHT = 20;

public:
    GameRunner(float fractionOfSecond);
    void RunGame();

private:
    void drawBorder();
};
