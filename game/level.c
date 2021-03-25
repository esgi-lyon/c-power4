#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid/model.h"
#include "grid/displayer.h"
#include "grid/controller.h"
#include "colors.h"

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

enum Case* reset_or_win(int* line, enum Case* previous, enum Case player) {
  if (*line == 4) {
    win_status = 1;
    const char separator[] = "=======================";
    printf(KNRM "\n %s \n" RESET, separator);
    printf(KBLU " ==== %s WINNED ====" RESET, get_case_char(player));
    printf(KNRM "\n %s \n" RESET, separator);
    return (enum Case*) player;
  }

  line = 0;
  previous = NULL;

  return NULL;
}

int calculate_win(GridMap* grid, enum Case player) {
  // line vertical
  int x, y;
  enum Case previous;
  int line = 1;

  // horizontal
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

  if (reset_or_win(&line, &previous, player) != NULL) {
    return 0;
  }

  // vertical
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

  if (reset_or_win(&line, &previous, player)) {
    return 0;
  };
  // diagonal

  return 0;
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

void loop_level() {
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

/**
 * @brief on start game input from, cli build and loop levels
 * - case 1 begin game
 * - case 2 play and calculate win
 * - case 3 a player winned
 */
void init() {
  printf(KGRN "Starting game..." RESET);
  loop_level();
}
