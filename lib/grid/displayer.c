#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "displayer.h"
#include "colors.h"

char separator[] = "---------------------------------------------------------";

const char* get_case_char(enum Case grid_case) {
   switch (grid_case) {
      case case_empty: return "\t";
      case case_red: return KRED PLAYER_CHAR RESET;
      case case_yellow: return KYEL PLAYER_CHAR RESET;
      default: return "\t";
   }
}

void print_grid(GridMap* grid) {
  int y, x;
  printf("\n%s", separator);
  for (y = Y_SIZE - 1; y >= 0; y--) {
    printf("\n");
    for (x = 0; x < X_SIZE; x++) {
      printf("| %s", get_case_char(grid->matrix[x][y]));
      if (x == 6) printf("|");
    }
    printf("\n%s", separator);
  }
  printf("\n");
}
