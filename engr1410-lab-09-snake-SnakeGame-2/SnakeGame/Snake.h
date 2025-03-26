#pragma once

#include <vector>
#include "Point.h"
#include "KeyCommand.h"
using namespace std;

class Snake
{
private:
    Point head;            
    vector<Point> tail;    
    int headColor;         
    int bodyColor;         
    int dx;                
    int dy;                
    Point lastTailPos;

public:
    Snake(int headC = 10, int bodyC = 2);

    void Draw() const;
    int getLength() const;

    void Update(KeyCommand cmd, int width, int height);
    bool checkCollision(int width, int height);
    bool checkEat(const Point& mousePos);

private:
    void setDirection(KeyCommand cmd);
};
