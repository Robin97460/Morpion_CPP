#include <iostream>
#include <array>
#include "Square.h"
#include "Row.h"
#include "Grid.h"
#include "player.h"
#include "Game.h"
using namespace std;

int main()
{
    Game game;
    game.SelectNames();
    game.start();
    cout << "Une autre partie ? (o/n) : ";
    char response;
    cin >> response;
    if (response == 'o' || response == 'O')
    {
        system("cls");
        main();
    }
    return 0;
}