#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid/model.h"
#include "grid/displayer.h"
#include "grid/controller.h"
#include "colors/ansi_escapes.h"
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
    printTextColor(BLUE_TXT, "\n %s \n", separator);
    printTextColor(BLUE_TXT, " ==== %s ", get_case_char(player));
    printTextColor(BLUE_TXT, "WINNED ====");
    printTextColor(BLUE_TXT, "\n %s \n", separator);

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
  int x = 0;
  int max_x = (int) round(X_SIZE / 2) + 1;
  enum Case previous;
  int line = 0;

  for (; x < max_x; ++x) {
    int tmp_y = 0;
    int tmp_x = x;

    if (player == grid->matrix[tmp_x][tmp_y]) {
      previous = grid->matrix[tmp_x][tmp_y];
    }

    while (tmp_y < Y_SIZE && tmp_x < max_x) {
      tmp_y++;
      tmp_x++;

      if (
        player == grid->matrix[tmp_x][tmp_y] &&
        previous == grid->matrix[tmp_x][tmp_y]
      ) {
        line++;
      }

      if (line == 3)return line;

      previous = grid->matrix[tmp_x][tmp_y];
    }
    // reset for next diagonal test
    line = 0;
  }

  return line;
}

int win_diagonal_bottom_reverse(GridMap* grid, enum Case player) {
  int x;
  x = (int) round(X_SIZE / 2) + 1;
  enum Case previous;
  int line = 0;

  for (; x > 0; --x) {
    int tmp_y = 0;
    int tmp_x = x;

    if (player == grid->matrix[tmp_x][tmp_y]) {
      previous = grid->matrix[tmp_x][tmp_y];
    }

    while (tmp_y < Y_SIZE && tmp_x > 0) {
      tmp_y++;
      tmp_x--;

      if (
        player == grid->matrix[tmp_x][tmp_y] &&
        previous == grid->matrix[tmp_x][tmp_y]
      ) {
        line++;
      }

      if (line == 3) return line;

      previous = grid->matrix[tmp_x][tmp_y];
    }
    // reset for next diagonal test
    line = 0;
  }

  return line;
}

int win_diagonal_top(GridMap* grid, enum Case player) {
  int x = 0;
  int max_x = (int) round(X_SIZE / 2) + 1;
  enum Case previous;
  int line = 0;

  for (; x < max_x; ++x) {
    int tmp_y = Y_SIZE - 1;
    int tmp_x = x;

    if (player == grid->matrix[tmp_x][tmp_y]) {
      previous = grid->matrix[tmp_x][tmp_y];
    }

    while (tmp_y > 0 && tmp_x < max_x) {
      tmp_y++;
      tmp_x++;

      if (
        player == grid->matrix[tmp_x][tmp_y] &&
        previous == grid->matrix[tmp_x][tmp_y]
      ) {
        line++;
      }

      if (line == 3) return line;

      previous = grid->matrix[tmp_x][tmp_y];
    }
    // reset for next diagonal test
    line = 0;
  }

  return line;
}

int win_diagonal_top_reverse(GridMap* grid, enum Case player) {
  int x;
  x = (int) round(X_SIZE / 2) + 1;
  enum Case previous;
  int line = 0;

  for (; x > 0; --x) {
    int tmp_y = Y_SIZE - 1;
    int tmp_x = x;

    if (player == grid->matrix[tmp_x][tmp_y]) {
      previous = grid->matrix[tmp_x][tmp_y];
    }

    while (tmp_y > 0 && tmp_x > 0) {
      tmp_y++;
      tmp_x--;

      if (
        player == grid->matrix[tmp_x][tmp_y] &&
        previous == grid->matrix[tmp_x][tmp_y]
      ) {
        line++;
      }

      if (line == 3) {
        return line;
      }

      previous = grid->matrix[tmp_x][tmp_y];
    }
    // reset for next diagonal test
    line = 0;
  }

  return line;
}

void calculate_win(GridMap* grid, enum Case player) {
  if (
      is_win(win_horizontal(grid, player), player) != NULL ||
      is_win(win_vertical(grid, player), player) != NULL ||
      is_win(win_diagonal_bottom(grid, player), player) != NULL ||
      is_win(win_diagonal_bottom_reverse(grid, player), player) != NULL ||
      is_win(win_diagonal_bottom_reverse(grid, player), player) != NULL ||
      is_win(win_diagonal_top(grid, player), player) != NULL ||
      is_win(win_diagonal_top_reverse(grid, player), player) != NULL
  ) return;
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

int scan_int_secure() {
  char input_col[CHAR_MAX] = "";
  scanf("%s", input_col);

  return atoi(input_col);
}

/**
 * @brief on start game input from, cli build and loop levels
 * - case 1 begin game
 * - case 2 play and calculate win
 * - case 3 a player winned
 */
void loop_level() {
  printTextColor(GREEN_TXT, "Starting game...");
  game_grid = create_grid();
  int turn_counter = 0;

  while (win_status != 1) {
    int input_col;
    // Choose first player
    if (turn_counter == 0) {
      switch_player();
      turn_counter++;
      print_grid(&game_grid);
      continue;
    };

    printf("%s : Enter a column from 1 to 7 \n", get_case_char(current_player));
    input_col = scan_int_secure();
    printf("%d", input_col);
    input_col--;

    if (input_col >= 0) {
      int success = set_column(current_player, input_col);
      if (success == 1) {
        printTextColor(RED_TXT, "Column not available\n");
        continue;
      }
      calculate_win(&game_grid, red_player);
      calculate_win(&game_grid, yellow_player);
      switch_player();
      turn_counter++;
      print_grid(&game_grid);
    } else {
      printTextColor(RED_TXT, "Column not available\n");
    }
  }
}
