#include "Mouse.h"
#include "Console.h"

using namespace std;

Mouse::Mouse()
{
    //position 
    srand((unsigned)time(nullptr));
    Move();
}

void Mouse::Move(int maxWidth, int maxHeight)
{
    position.x = rand() % maxWidth;
    position.y = rand() % maxHeight;
}

void Mouse::Draw() const
{
    //Draw the mouse
    Console::txtPlot(position.x, position.y, '#');
}
