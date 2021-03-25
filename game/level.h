#include "grid/model.h"

#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

void switch_player();

void set_column(enum Case grid_case, unsigned int y);

int calculate_win(GridMap* grid);

void loop_level();

void init();

#endif
