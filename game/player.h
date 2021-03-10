#include "grid/controller.h"
#include "grid/model.h"

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

struct Player
{
    Case** cases;
};

int count_in_diagonal(Grid* grid);

int count_in_x(Grid* grid);

int count_in_y(Grid* grid);

#endif
