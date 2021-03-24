#include <stdio.h>
#include <stdlib.h>
#include "model.h"

const char* get_case_char(enum Case grid_case) {
   switch (grid_case) {
      case case_empty: return "\t";
      case case_red: return "o";
      case case_yellow: return "x";
      default: return "\t";
   }
}

void print_grid(GridMap* grid) {
   int x, y;
   printf("\n");
   for (x = 0; x <= 6; x++) {
      for (y = 0; y <= 7; y++) {
        printf("x %s", get_case_char(grid->matrix[x][y]));
      }
   }
   printf("\n");
}
