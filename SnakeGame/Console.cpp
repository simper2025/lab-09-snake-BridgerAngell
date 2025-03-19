#include "Console.h"

void Console::txtPlot(point item, unsigned char Color) 
{
    setcolor(Color);
    gotoxy(item.x * 2, item.y);
    _cprintf("  ");
}

void Console::gotoxy(int x, int y) 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Console::setcolor(WORD color) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
