#pragma once
#include <iostream>
using namespace std;

struct Point
{
public:
    int x;
    int y;

    Point(int xPos = 0, int yPos = 0)
    {
        x = xPos;
        y = yPos;
    }
};
