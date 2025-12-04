#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Grid.h"
#include <array>
#include <vector>

class Game
{
    private:
        Player p1;
        Player p2;
        Player * currentPlayer;
        Grid grid;
         
    public:
        Game();
        void start();
        void SelectNames();
};

#endif