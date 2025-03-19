#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h>
#include <cstdio> 
#include "Point.h"

class Console 
{

public:
    static void txtPlot(point item, unsigned char Color);

private:
    static void gotoxy(int x, int y);
    static void setcolor(WORD color);
};

#endif 
