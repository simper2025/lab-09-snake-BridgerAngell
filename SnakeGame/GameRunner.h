#ifndef GAMERUNNER_H
#define GAMERUNNER_H

#include "KeyCommand.h"
#include "Mouse.h"

class GameRunner 
{
private:
    float repeatInterval;
    KeyCommand keypress;
    Mouse mouse;

public:
    GameRunner(float interval);
    void RunGame();
};

#endif 
