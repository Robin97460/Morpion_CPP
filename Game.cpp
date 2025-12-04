#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() : p1(), p2(), grid()
{
    srand(time(0));
    currentPlayer = (rand() % 2 == 0) ? &p1 : &p2;
}

void Game::SelectNames()
{
    cout << "Veillez saisir le nom du joueur 1 :";
    string name1;
    cin >> name1;
    p1.setNom(name1);
    p1.setToken("X");
    cout << "Veillez saisir le nom du joueur 2 :";
    string name2;
    cin >> name2;
    p2.setNom(name2);
    p2.setToken("O");
}

void Game::start()
{
    int selectedCol, selectedRow;

    while (true)
    {
        grid.display();
        cout << "Joueur : " << currentPlayer->getNom() << endl;
        cout << "Choisissez une colonne entre 1 et 3 : ";
        cin >> selectedCol;
        selectedCol = selectedCol - 1;

        cout << "Choisissez une ligne entre 1 et 3 : ";
        cin >> selectedRow;
        selectedRow = selectedRow - 1;

        vector<array<Square *, 3>> combinaison_list = getCombinaisons(square);
        if (checkWin(combinaison_list))
        {
            grid.display();
            break;
        }

        if (currentPlayer == &p1)
            currentPlayer = &p2;
        else
            currentPlayer = &p1;
    }
    cout << "Vainqueur : " << currentPlayer->getNom() << endl;
    cout << "Partie terminée" << endl;
    system("pause");
}

bool Game::play(int col, int row)
{
    if (!grid.rowExist(row) || !grid.getRow(row).squareExist(col))
    {
        cout << "Position invalide (hors limites)" << endl;
        return false;
    }
    Square &selectedSquare = grid.getRow(row).getSquare(col);

    if (selectedSquare.hasToken())
    {
        cout << "Cette case est deja prise" << endl;
        return false;
    }

    selectedSquare.setToken(currentPlayer->getToken());
    return true;
}

vector<array<Square *, 3>> Game::getCombinaisons(Square square)
{
    vector<array<Square *, 3>> combinaison_list;
    for (int index = -2; index <= 0; index++)
    {
        int i = 0;
        array<Square *, 3> combinaison;
        bool exist = true;
        for (int x = square.getX() + index; x <= square.getX() + index + 2; x++)
        {
            if (grid.rowExist(x) && grid.getRow(x).squareExist(square.getY()))
            {
                combinaison[i++] = &grid.getRow(x).getSquare(square.getY());
            }
            else
            {
                exist = false;
                break;
            }
        }
        if (exist)
        {
            combinaison_list.push_back(combinaison);
        }
    }
    for (int index = -2; index <= 0; index++)
    {
        int i = 0;
        array<Square *, 3> combinaison;
        bool exist = true;
        for (int y = square.getY() + index; y <= square.getY() + index + 2; y++)
        {
            if (grid.rowExist(square.getX()) && grid.getRow(square.getX()).squareExist(y))
            {
                combinaison[i++] = &grid.getRow(square.getX()).getSquare(y);
            }
            else
            {
                exist = false;
                break;
            }
        }
        if (exist)
        {
            combinaison_list.push_back(combinaison);
        }
    }
    for (int index = -2; index <= 0; index++)
    {
        int i = 0;
        array<Square *, 3> combinaison;
        bool exist = true;
        for (int xy = index; xy <= index + 2; xy++)
        {
            if (grid.rowExist(square.getX() - xy) && grid.getRow(square.getX() - xy).squareExist(square.getY() - xy))
            {
                combinaison[i++] = &grid.getRow(square.getX() - xy).getSquare(square.getY() - xy);
            }
            else
            {
                exist = false;
                break;
            }
        }
        if (exist)
        {
            combinaison_list.push_back(combinaison);
        }
    }
    for (int index = -2; index <= 0; index++)
    {
        int i = 0;
        array<Square *, 3> combinaison;
        bool exist = true;
        for (int xy = index; xy <= index + 2; xy++)
        {
            if (grid.rowExist(square.getX() - xy) && grid.getRow(square.getX() - xy).squareExist(square.getY() + xy))
            {
                combinaison[i++] = &grid.getRow(square.getX() - xy).getSquare(square.getY() + xy);
            }
            else
            {
                exist = false;
                break;
            }
        }
        if (exist)
        {
            combinaison_list.push_back(combinaison);
        }
    }
    return combinaison_list;
}

void Game::drawCombinaison()
{
    auto combinaison_list = getCombinaisons(grid.getRow(1).getSquare(1));
    for (int c = 0; c <= combinaison_list.size() - 1; c++)
    {
        for (int s = 0; s <= combinaison_list[c].size() - 1; s++)
        {
            combinaison_list[c][s]->setToken("x");
        }
        grid.display();
        system("pause");
        grid.reset();
    }
}

bool Game::checkWin(vector<array<Square *, 3>> combinaison_list)
{
    for (int index = 0; index < combinaison_list.size(); index++)
    {

        array<Square *, 3> combinaison = combinaison_list[index];
        if (combinaison[0]->getToken().has_value() &&
            combinaison[1]->getToken().has_value() &&
            combinaison[2]->getToken().has_value())
        {
            string token = combinaison[0]->getToken().value_ref();
            if (token == combinaison[1]->getToken().value_ref() &&
                token == combinaison[2]->getToken().value_ref())
            {

                return true;
            }
        }
    }
    return false;
}