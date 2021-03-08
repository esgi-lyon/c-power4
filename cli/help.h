/**
 * @brief Help.c header file
 * Here manage the display of manual to learn to play the game
 */
#ifndef HELP_H_INCLUDED
#define HELP_H_INCLUDED

/**
 * @brief small description of game
 */
int desc();

/**
 * @brief print all commands available
 * read sibling files because in cli/ folder, one file == one command
 */
int commands();

/**
 * @brief How to start the game and
 * check all possible interactions
 */
int game_start();

#endif
