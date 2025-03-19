#include "Keyboard.h"

KeyCommand Keyboard::GetKeyPress() 
{
    if (_kbhit()) 
    {
        int key = _getch();

        switch (key) {
        case 75: return KeyCommand::Left;
        case 77: return KeyCommand::Right;
        case 72: return KeyCommand::Up;
        case 80: return KeyCommand::Down;
        case 27: return KeyCommand::Quit;
        default: return KeyCommand::None;
        }
    }
    return KeyCommand::None;
}
