#include "Player.h"
#include <iostream>
#include "SelectName.h"
#include "Game.h"

using namespace std;

string nom = AskName();

int main() {
    Game game;
    game.SelectNames();
    return 0;

    
}