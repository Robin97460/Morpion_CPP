#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() : p1(), p2(), grid()
{
    currentPlayer = &p1;
}

void Game::SelectNames()
{
    cout << "Veillez saisir le nom du joueur 1 :";
    string name1;
    cin >> name1;
    p1.setNom(name1);
    cout << "Veillez saisir le nom du joueur 2 :";
    string name2;
    cin >> name2;
    p2.setNom(name2);
}