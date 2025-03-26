#pragma once

#include <cstdlib>
#include <ctime>
#include "Point.h"

class Mouse
{
private:
    Point position;

public:
    
    Mouse();
    void Move(int maxWidth = 80, int maxHeight = 20);
    void Draw() const;

    Point getPosition() const
    {
        return position;
    }
};
