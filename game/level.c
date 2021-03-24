#include <stdio.h>
#include <stdlib.h>
#include "grid/model.h"
#include "grid/displayer.h"

GridMap* game_grid;

/**
 * @brief Given cli input, init the game in a switch
 * - case 1 begin game
 * - case 2 play and calculate win
 * - case 3 a player winned
 */
int build_level() {
  game_grid = create_grid();

  return 0;
}

int calculate_win() {
  printf("%s", "TODO calculate_win function");

  return 0;
}
