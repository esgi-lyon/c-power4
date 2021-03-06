#include <stdio.h>
#include <stdlib.h>
#include "model.h"

GridMap create_grid() {
  GridMap grid = (GridMap) {
    .matrix = {
      {case_empty, case_empty, case_empty, case_empty, case_empty, case_empty},
      {case_empty, case_empty, case_empty, case_empty, case_empty, case_empty},
      {case_empty, case_empty, case_empty, case_empty, case_empty, case_empty},
      {case_empty, case_empty, case_empty, case_empty, case_empty, case_empty},
      {case_empty, case_empty, case_empty, case_empty, case_empty, case_empty},
      {case_empty, case_empty, case_empty, case_empty, case_empty, case_empty},
      {case_empty, case_empty, case_empty, case_empty, case_empty, case_empty}
    }
  };

  return grid;
}

enum Case get_case(GridMap* grid, unsigned int x, unsigned int y) {
  return grid->matrix[x][y];
};

GridMap* append_case(
  GridMap* grid,
  enum Case grid_case,
  unsigned int x,
  unsigned int y
) {
    grid->matrix[x][y] = grid_case;
    return grid;
}

void free_grid(GridMap* grid) {
  free(grid);
};
