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
   int x, y;
   printf("\n%s", separator);
   for (x = 0; x < 6; x++) {
      printf("\n");
      for (y = 0; y < 7; y++) {
        printf("| %s", get_case_char(grid->matrix[x][y]));
        if (y == 6) printf("|");
      }
      printf("\n%s", separator);
   }
   printf("\n");
}
