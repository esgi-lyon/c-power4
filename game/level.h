#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#define case_empty = '|\t|';

#define red = 'x';
#define yellow = 'o';

void init();

void build_level();

int calculate_win();

#endif
