#include "GameRunner.h"
#include "Keyboard.h"
#include "Console.h"
#include <chrono>
#include <thread>

using namespace std;


GameRunner::GameRunner(float interval) : repeatInterval(interval), keypress(KeyCommand::None), mouse() {}

void GameRunner::RunGame() 

{
    auto runTime = std::chrono::system_clock::now();
    point playerloc = { 0, 10 };
    point direction = { 1, 0 };
    int length = 5;

    while (keypress != KeyCommand::Quit) 
    {
        keypress = Keyboard::GetKeyPress();

        if (keypress == KeyCommand::Quit) 
        {
            break;
        }

        auto currentTime = chrono::system_clock::now();
        double elapsedTime = chrono::duration_cast<chrono::milliseconds>(currentTime - runTime).count();

        if (elapsedTime > repeatInterval * 1000) 
        {
            runTime = std::chrono::system_clock::now();

            mouse.Move();
            mouse.Draw();

            Console::txtPlot(playerloc, 31);

            Console::txtPlot({ 1, 21 }, 15);
            _cprintf("Length: %i", length);
        }

        this_thread::sleep_for(chrono::milliseconds(10));
    }
}
