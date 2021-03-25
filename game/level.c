#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid/model.h"
#include "grid/displayer.h"
#include "grid/controller.h"
#include "colors.h"
#include <math.h>

GridMap game_grid;
int win_status = 0;

const enum Case red_player = case_red;
const enum Case yellow_player = case_yellow;
enum Case current_player;

void switch_player() {
  if (current_player == red_player)
    current_player = yellow_player;
  else if (current_player == yellow_player)
    current_player = red_player;
  else {
    // Init random using time
    srand(time(NULL));
    if ((rand() % (30 + 1 - 1) + 1) % 2 == 1)
      current_player = red_player;
    else
      current_player = yellow_player;
  }
}

enum Case* is_win(int line, enum Case player) {
  if (line == 3) {
    win_status = 1;
    const char separator[] = "=======================";
    printf(KBLU "\n %s \n", separator);
    printf(" ==== %s WINNED ====", get_case_char(player));
    printf("\n %s \n" RESET, separator);

    return (enum Case*) player;
  }

  return NULL;
}

int win_vertical(GridMap* grid, enum Case player) {
  int x, y;
  int line = 0;
  enum Case previous;

  for (x = 0; x < X_SIZE; x++) {
    for (y = Y_SIZE - 1; y >= 0; y--) {
      if (
        player == grid->matrix[x][y] &&
        grid->matrix[x][y] == previous
      ) {
        line++;
      }

      previous = grid->matrix[x][y];
    }
  }

  return line;
}

int win_horizontal(GridMap* grid, enum Case player) {
  int x, y;
  enum Case previous;
  int line = 0;

  // line horizontal
  for (y = Y_SIZE - 1; y >= 0; y--) {
    for (x = 0; x < X_SIZE; x++) {
      if (
        player == grid->matrix[x][y] &&
        grid->matrix[x][y] == previous
      ) {
        line++;
      }

      previous = grid->matrix[x][y];
    }
  }

  return line;
}

int win_diagonal_bottom(GridMap* grid, enum Case player) {
  int x, y;
  x = y = 0;
  enum Case previous;
  int line = 0;
  if (player == grid->matrix[x][y]) previous = grid->matrix[x][y];

  while (y < Y_SIZE || x < (int) round(X_SIZE / 2) + 1) {
    y++;
    x++;

    if (
      player == grid->matrix[x][y] &&
      previous == grid->matrix[x][y]
    ) {
      line++;
    }

    previous = grid->matrix[x][y];
  }

  return line;
}

int win_diagonal_bottom_reverse(GridMap* grid, enum Case player) {
  int x, y;
  y = 0;
  x = X_SIZE;
  enum Case previous;
  int line = 0;

  if (player == grid->matrix[x - 1][y])
    previous = grid->matrix[x -1][y];

  while (y < Y_SIZE || x > 0) {
    y++;
    x--;
    printf("x : %d / y : %d", x, y);

    if (
      player == grid->matrix[x][y] &&
      previous == grid->matrix[x][y]
    ) {
      printf("%s", get_case_char(grid->matrix[x][y]));
      line++;
    }
    printf("\n");

    previous = grid->matrix[x][y];
  }
  printf("\n\n");
  return line;
}

void calculate_win(GridMap* grid, enum Case player) {
  if (is_win(win_horizontal(grid, player), player) != NULL) {
    return;
  }

  if (is_win(win_vertical(grid, player), player) != NULL) {
    return;
  }

  if (is_win(win_diagonal_bottom(grid, player), player) != NULL) {
    return;
  }

  if (is_win(win_diagonal_bottom_reverse(grid, player), player) != NULL) {
    return;
  }
}

int determine_y_in_col(GridMap* grid, unsigned int x) {
  int y;
  for (y = 0; y < Y_SIZE; y++) {
    if (grid->matrix[x][y] == case_empty) {
      return y;
    }
  }

  return -1;
}

int set_column(enum Case grid_case, unsigned int x) {
  int y = determine_y_in_col(&game_grid, x);
  if (Y_SIZE > y && y >= 0 && X_SIZE > x && x >= 0) {
    append_case(&game_grid, grid_case, x, y);
    return 0;
  } else {
    return 1;
  }
}

/**
 * @brief on start game input from, cli build and loop levels
 * - case 1 begin game
 * - case 2 play and calculate win
 * - case 3 a player winned
 */
void loop_level() {
  printf(KGRN "Starting game..." RESET);
  game_grid = create_grid();
  int turn_counter = 0;

  while (win_status != 1) {
    // Choose first player
    if (turn_counter == 0) {
      switch_player();
      turn_counter++;
      continue;
    };

    print_grid(&game_grid);

    int input_col;

    printf("%s : Enter a column from 1 to 7 \n", get_case_char(current_player));
    scan: scanf("%d", &input_col);

    input_col--;

    if (input_col >= 0) {
      int success = set_column(current_player, input_col);
      if (success == 1) {
        printf(KRED "Column not available\n" RESET);
        goto scan;
      }
      calculate_win(&game_grid, red_player);
      calculate_win(&game_grid, yellow_player);
      switch_player();
    } else {
      printf(KRED "Column not available\n" RESET);
      goto scan;
    }

    turn_counter++;
  }
}
