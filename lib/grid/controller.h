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
 * @brief Create a grid empty struct
 *
 * @return GridMap*
 */
GridMap create_grid();

/**
 * @brief Given coordinates, give the case to interact with
 *
 * @param grid
 * @param x
 * @param y
 * @return enum Case
 */
enum Case get_case(GridMap* grid, unsigned int x, unsigned int y);

/**
 * @brief add case in grid, error if already exist in coords
 *
 * @param grid
 * @param grid_case
 * @param x
 * @param y
 * @return struct Grid*
 */
GridMap* append_case(
  GridMap* grid,
  enum Case grid_case,
  unsigned int x,
  unsigned int y
);

void free_grid(GridMap* grid);

#endif
