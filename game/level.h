#include "grid/model.h"

#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

const enum Case red_player = case_red;
const enum Case yellow_player = case_yellow;

void build_level();

int calculate_win();

void init();

#endif
