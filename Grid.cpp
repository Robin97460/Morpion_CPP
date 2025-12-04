#include "Grid.h"
#include "Row.h"
#include <iostream>

using namespace std;

Grid::Grid()
{
    for (int x = 0; x < 3; x++)
    {
        row_list[x] = Row(x);
    }
}

void Grid::display()
{
    system("cls");
    cout << "---0--1--2--------------" << endl;
    for (int line = 0; line < row_list.size(); line++)
    {
        row_list[line].display();
    }
    cout << "------------------------" << endl;
}

Row &Grid::getRow(int xCoord)
{
    return row_list[xCoord];
};

void Grid::reset()
{
    for (int line = 0; line < row_list.size(); line++)
    {
        for (int x = 0; x < 3; x++)
        {
            row_list[line].getSquare(x).getToken().reset();
        }
    }
}

bool Grid::rowExist(int xCoord)
{
    return xCoord >= 0 && xCoord < row_list.size();
}