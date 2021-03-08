#include "model.h"
#include "displayer.h"

/**
 * @brief Grid launcher
 * --> Controller component in grid MVC pattern
 * interact with model, dispatch actions and print grid
 */
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

struct Grid* actual_grid;

/**
 * @brief Launcher function, do :
 * - data (structure)
 * - echo the data
 * 
 * call : displayer build function
 */
struct Grid* spawn_grid();

void read_grid(struct Grid* model);

struct Grid* update_grid(int x, int y);

void free_grid(struct Grid* model);

#endif