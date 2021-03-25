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

  *line = 1;
  previous = NULL;

  return NULL;
}

void calculate_win(GridMap* grid, enum Case player) {
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
    return;
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
    return;
  }

  return;

  // diagonal
  // Sud-Ouest -> Nord-Est
  for (x = 0; x <= 3; x++)
  {
    for (y = 0; y <= 3; y++)
    {
      if (
          player == grid->matrix[x][y] &&
          (
            grid->matrix[x + 1][y + 1] == previous ||
            grid->matrix[x + 2][y + 2] == previous ||
            grid->matrix[x + 3][y + 3] == previous
          )
        ) {
          printf(KMAG "\nline count : %d" RESET, line);
          printf("\nx : %d", x + 1);
          printf("\ny : %d", y + 1);
          printf("\n%s", get_case_char(grid->matrix[x + 1][y + 1]));
          line++;
      }

      previous = grid->matrix[x + 1][y + 1];
    }
  }

  if (reset_or_win(&line, &previous, player)) {
    return;
  }

  // Sud-Est -> Nord-Ouest
  for (x = 6; x >= 3; x--)
  {
    for (y = 0; y <= 3; y++)
    {
      if (
          player == grid->matrix[x][y] &&
          (
            grid->matrix[x - 1][y + 1] == previous ||
            grid->matrix[x - 2][y + 2] == previous ||
            grid->matrix[x - 3][y + 3] == previous
          )
        ) {
          printf(KMAG "\nline count : %d" RESET, line);
          printf("\nx : %d", x + 1);
          printf("\ny : %d", y + 1);
          printf("\n%s", get_case_char(grid->matrix[x - 1][y + 1]));
          line++;
        }
      previous = grid->matrix[x - 1][y + 1];
    }
  }

  if (reset_or_win(&line, &previous, player)) {
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
