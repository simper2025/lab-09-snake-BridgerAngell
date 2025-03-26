#pragma once

#include <Windows.h>
#include <iostream>
using namespace std;

class Console
{
public:
    // Public static function to plot text at a given coordinate
    static void txtPlot(int x, int y, char ch);

private:
    // Moves the cursor to a position (x,y) on the console
    static void gotoxy(int x, int y);

    // Optional function to set color (example usage: setcolor(12))
    // Not currently used, but you can add calls if desired
    static void setcolor(int colorCode);
};
