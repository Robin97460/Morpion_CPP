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
    system("pause");
    return 0;
}