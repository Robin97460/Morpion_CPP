#include "Row.h"
#include <iostream>

using namespace std;

Row::Row() : x(0) {}

Row::Row(int xCoord) : x(xCoord)
{
    for (int y = 0; y < 3; y++)
    {
        square_list[y] = Square(xCoord, y);
    }
}

int Row::getX() const { return x; }

void Row::display()
{
    cout << "|";
    for (int i = 0; i < square_list.size(); ++i)
    {
        square_list[i].display();
    }
    cout << "|" << endl;
}

Square &Row::getSquare(int yCoord)
{
    return square_list[yCoord];
};

int Row::getSquareNumber()
{
    return square_list.size();
}

bool Row::squareExist(int yCoord)
{
    return yCoord >= 0 && yCoord < square_list.size();
}