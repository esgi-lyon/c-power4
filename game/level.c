#include <stdio.h>
#include <stdlib.h>
#include "grid/model.h"
#include "grid/displayer.h"
#include "grid/controller.h"
#include "colors.h"

GridMap game_grid;
int turn_counter = 0;
int win_status = 0;

const enum Case red_player = case_red;
const enum Case yellow_player = case_yellow;
enum Case current_player;

void switch_player() {
  if (current_player == red_player)
    current_player = yellow_player;
  else if (current_player == yellow_player)
    current_player = red_player;
  else
    // FIXME not random player
    if ((rand() % (30 + 1 - 1) + 1) % 2 == 1)
      current_player = red_player;
    else
      current_player = yellow_player;
}

int calculate_win() {
  printf("%s", "TODO calculate_win function");

  return 0;
}

void build_level() {
  game_grid = create_grid();

  while (win_status != 1) {
    // Choose first player
    if (turn_counter == 0) {
      switch_player();
      turn_counter++;
      continue;
    };

    print_grid(&game_grid);

    int input_col;
    printf("%s : Enter a column from 0 to 7 \n", get_case_char(current_player));
    scanf("%d", &input_col);

    if (input_col >= 0) {
      printf("toto");
      //append_case();
      switch_player();
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
  build_level();
}
