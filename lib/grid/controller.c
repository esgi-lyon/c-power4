#include <stdio.h>
#include <stdlib.h>
#include "model.h"

GridMap* spawn_grid() {
  printf("%s", "TODO spawn_grid function");

  return NULL;
}

void read_grid(GridMap* grid) {
  printf("%s", "TODO read_grid function");
  printf("%p", &grid);
}

GridMap* update_grid(double x, double y){
  printf("x %0.2f / y %0.2f", x , y);
  printf("%s", "TODO update_grid function");

  return NULL;
}

void free_grid(GridMap* grid) {
  printf("%p", &grid);
  printf("%s", "TODO free_grid function");
};
