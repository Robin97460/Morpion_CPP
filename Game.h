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
    Player *currentPlayer;
    Grid grid;

public:
    Game();
    void start();
    void SelectNames();
    bool play(int col, int row);
    vector<array<Square *, 3>> getCombinaisons(Square square);
    bool checkWin(vector<array<Square *, 3>> combinaison_list);
    void drawCombinaison();
};

#endif