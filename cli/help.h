/**
 * @brief Help.c header file
 * Here manage the display of manual to learn to play the game
 */
#ifndef HELP_H_INCLUDED
#define HELP_H_INCLUDED

/**
 * @brief Wrap help info texts
 *
 * @return int
 */
void help();

/**
 * @brief small description of game
 */
void desc();

/**
 * @brief print all commands available
 * read sibling files because in cli/ folder, one file == one command
 */
void commands();

#endif
