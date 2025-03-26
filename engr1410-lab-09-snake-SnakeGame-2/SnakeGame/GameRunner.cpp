#include "GameRunner.h"
#include "Console.h"
#include <windows.h>  
#include <iostream>
using namespace std;

GameRunner::GameRunner(float fractionOfSecond)
{
    delaySeconds = fractionOfSecond;
    gameOver = false;
    keyPress = KeyCommand::none;
}

void GameRunner::RunGame()
{
    system("cls");

    while (!gameOver)
    {
        
        drawBorder();

        
        mouse.Draw();
        snake.Draw();

        
        Console::txtPlot(0, HEIGHT, 'L');
        cout << "ength = " << snake.getLength();

        
        keyPress = Keyboard::getKeyCommand();
        if (keyPress == KeyCommand::quit)
        {
            gameOver = true;
            continue;
        }

        //Move/update snake
        snake.Update(keyPress, WIDTH, HEIGHT);

        //Check if snake ate 
        if (snake.checkEat(mouse.getPosition()))
        {
            mouse.Move(WIDTH, HEIGHT);
        }

        //check collision
        if (snake.checkCollision(WIDTH, HEIGHT))
        {
            gameOver = true;
            continue;
        }

        //Sleep ----- This is slug, not snake.
        Sleep(static_cast<DWORD>(delaySeconds * 1000.0f));

        //Clear console
        system("cls");
    }

}

void GameRunner::drawBorder()
{
    //Top row
    for (int x = 0; x < WIDTH; x++)
    {
        Console::txtPlot(x, 0, '-');
    }
    //Bottom row
    for (int x = 0; x < WIDTH; x++)
    {
        Console::txtPlot(x, HEIGHT - 1, '-');
    }
    //Left column
    for (int y = 0; y < HEIGHT; y++)
    {
        Console::txtPlot(0, y, '|');
    }
    //Right column
    for (int y = 0; y < HEIGHT; y++)
    {
        Console::txtPlot(WIDTH - 1, y, '|');
    }
}
