/**
 * @brief View component in grid MVC pattern
 * Print a grid from the model
 */
#ifndef DISPLAYER_H_INCLUDED
#define DISPLAYER_H_INCLUDED

const char* get_case_char(enum Case grid_case);

void print_grid(GridMap* grid_map);

#endif
