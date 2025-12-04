//
// Created by hugol on 04/12/2025.
//

#ifndef MORPION_CPP_GRID_H
#define MORPION_CPP_GRID_H


class Grid {
private:
    array<Column,3> column_list;
public:
    Grid();
    void display();
    Column& getColumn(int xCoord);
    void reset();
    bool columnExist(int xCoord);
};



#endif //MORPION_CPP_GRID_H