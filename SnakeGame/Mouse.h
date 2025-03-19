#ifndef MOUSE_H
#define MOUSE_H

#include "Point.h"
#include "Console.h"
#include <cstdlib>
#include <ctime>

class Mouse 
{
private:
    point location;

public:
    Mouse();
    void Move();
    void Draw() const;
    point GetLocation() const;
};

#endif // MOUSE_H
