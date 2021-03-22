#include <stdio.h>
#include <stdlib.h>
#include "model.h"

GridMap* create_grid() {
  GridMap *grid = (GridMap*)malloc(sizeof(GridMap));

  return grid;
}

Case* create_case() {
    Case *grid_case = (Case *)malloc(sizeof(Case));

  return grid_case;
}

Case* get_case(GridMap* grid, unsigned int x, unsigned int y)
{
  printf("%s", "TODO interact function");
  printf("x %d | y %d", x, y);
  printf("%p", &grid);

  return NULL;
}

GridMap* append_case(GridMap* grid, Case* grid_case, unsigned int x, unsigned int y) {
  printf("%s", "TODO interact function");
  printf("x %d | y %d", x, y);
  printf("%p", &grid_case);
  printf("%p", &grid);

  return NULL;
}
