#include <stdio.h>
#include <stdlib.h>
#include "model.h"

GridMap* create_grid() {
  GridMap *grid = (GridMap*) malloc(sizeof(GridMap));

  return grid;
}

Case* get_case(GridMap* grid, unsigned int x, unsigned int y) {
  return grid->matrix[x][y];
};

GridMap* append_case(
  GridMap* grid,
  Case* grid_case,
  unsigned int x,
  unsigned int y
) {
  if (x >= 0 && y >= 0)
    grid->matrix[x][y] = grid_case;

  return grid;
}
