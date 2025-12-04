#ifndef GRID_H
#define GRID_H

#include <array>
#include "Row.h"

class Grid
{
private:
    array<Row, 3> row_list;

public:
    Grid();
    void display();
    Row &getRow(int xCoord);
    void reset();
    bool rowExist(int xCoord);
};

#endif