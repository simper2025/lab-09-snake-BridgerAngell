#include "Snake.h"
#include "Console.h"

Snake::Snake(int headC, int bodyC)
{
    //Start 
    head.x = 40;
    head.y = 10;
    headColor = headC;
    bodyColor = bodyC;

    //Default direction is 0,0
    dx = 0;
    dy = 0;
}

void Snake::Draw() const
{
    
    Console::txtPlot(head.x, head.y, 'O');

    
    for (auto& segment : tail)
    {
        Console::txtPlot(segment.x, segment.y, 'o');
    }
}

void Snake::Update(KeyCommand cmd, int width, int height)
{
    
    if (!tail.empty())
    {
        lastTailPos = tail.back();
    }
    else
    {
        
        lastTailPos = head;
    }

    
    setDirection(cmd);

    if (!tail.empty())
    {
        for (int i = tail.size() - 1; i > 0; i--)
        {
            tail[i] = tail[i - 1];
        }
        tail[0] = head;
    }

    
    head.x += dx;
    head.y += dy;
}

int Snake::getLength() const
{
    
    return 1 + static_cast<int>(tail.size());
}

bool Snake::checkCollision(int width, int height)
{
   
    if (head.x < 0 || head.x >= width || head.y < 0 || head.y >= height)
    {
        return true;
    }

   
    for (auto& segment : tail)
    {
        if (segment.x == head.x && segment.y == head.y)
        {
            return true;
        }
    }
    return false;
}

bool Snake::checkEat(const Point& mousePos)
{
    //If hit the mouse
    if (head.x == mousePos.x && head.y == mousePos.y)
    {
        //Push the old tail position to grow the snake
        tail.push_back(lastTailPos);
        return true;
    }
    return false;
}

void Snake::setDirection(KeyCommand cmd)
{
    int newDx = dx;
    int newDy = dy;

    switch (cmd)
    {
    case KeyCommand::up:
        newDx = 0;
        newDy = -1;
        break;
    case KeyCommand::down:
        newDx = 0;
        newDy = 1;
        break;
    case KeyCommand::left:
        newDx = -1;
        newDy = 0;
        break;
    case KeyCommand::right:
        newDx = 1;
        newDy = 0;
        break;
    default:
        
        return;
    }

    //Prevent going backwars
    if ((dx == 1 && newDx == -1) || (dx == -1 && newDx == 1))
        return;
    if ((dy == 1 && newDy == -1) || (dy == -1 && newDy == 1))
        return;

    dx = newDx;
    dy = newDy;
}
