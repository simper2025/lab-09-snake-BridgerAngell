#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "KeyCommand.h"
#include <conio.h>

class Keyboard 
{
public:
    static KeyCommand GetKeyPress();
};

#endif // KEYBOARD_H
