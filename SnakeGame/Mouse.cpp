#include "Mouse.h"

Mouse::Mouse() 
{
    srand(static_cast<unsigned>(time(0)));
    Move();
}

void Mouse::Move() 
{
    location.x = rand() % 40;
    location.y = rand() % 20;
}

void Mouse::Draw() const 
{
    Console::txtPlot(location, 12);
}

point Mouse::GetLocation() const 
{
    return location;
}
