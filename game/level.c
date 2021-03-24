#include <stdio.h>
#include <stdlib.h>
#include "grid/model.h"
#include "grid/displayer.h"
#include "grid/controller.h"

GridMap game_grid;
int turn_counter = 0;

/**
 * @brief Given cli input, init the game in a switch
 * - case 1 begin game
 * - case 2 play and calculate win
 * - case 3 a player winned
 */
void build_level() {
  printf("Starting game...\n");
  game_grid = create_grid();

  print_grid(&game_grid);
}

int calculate_win() {
  printf("%s", "TODO calculate_win function");

  return 0;
}

void init() {
  build_level();
}
