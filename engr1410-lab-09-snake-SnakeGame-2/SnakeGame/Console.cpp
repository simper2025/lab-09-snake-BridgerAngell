#include "Console.h"

void Console::txtPlot(int x, int y, char ch)
{
    gotoxy(x, y);
    cout << ch;
}

void Console::gotoxy(int x, int y)
{
    COORD coord;
    coord.X = static_cast<SHORT>(x);
    coord.Y = static_cast<SHORT>(y);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Console::setcolor(int colorCode)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}
