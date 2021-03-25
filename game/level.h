#include "grid/model.h"

#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

void switch_player();

int determine_x_in_col(GridMap* grid);

void set_column(enum Case grid_case, unsigned int y);

int calculate_win();

void loop_level();

void init();

#endif
