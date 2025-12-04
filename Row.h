#ifndef ROW_H
#define ROW_H

#include <array>
#include "Square.h"

class Row
{
private:
    int x;
    array<Square, 3> square_list;

public:
    Row();
    Row(int xCoord);
    int getX() const;
    void display();
    Square &getSquare(int yCoord);
    int getSquareNumber();
    bool squareExist(int yCoord);
};

#endif