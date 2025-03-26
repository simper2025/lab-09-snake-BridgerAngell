#include "Keyboard.h"

KeyCommand Keyboard::getKeyCommand()
{
    if (!_kbhit())
    {
        return KeyCommand::none;
    }

    int ch = _getch();
    switch (ch)
    {
        
    case 224:
    {
        ch = _getch();
        if (ch == 72) return KeyCommand::up;       
        if (ch == 80) return KeyCommand::down;    
        if (ch == 75) return KeyCommand::left;    
        if (ch == 77) return KeyCommand::right;   
        break;
    }
   
    case 27:
    {
        return KeyCommand::quit;
    }
    // WASD
    case 'w': case 'W':
    {
        return KeyCommand::up;
    }
    case 's': case 'S':
    {
        return KeyCommand::down;
    }
    case 'a': case 'A':
    {
        return KeyCommand::left;
    }
    case 'd': case 'D':
    {
        return KeyCommand::right;
    }
    
    case 'q': case 'Q':
    {
        return KeyCommand::quit;
    }
    }

    return KeyCommand::none;
}
