#include "model.h"
#include "displayer.h"

/**
 * @brief Grid launcher
 * --> Controller component in grid MVC pattern
 * interact with model, dispatch actions and print grid
 */
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

/**
 * @brief Launcher function, do :
 * - data (structure)
 * - echo the data
 *
 * call : displayer build function
 */
GridMap* spawn_grid();

void read_grid(GridMap* model);

GridMap* update_grid(int x, int y);

void free_grid(GridMap* model);

void fill_case()

#endif
