#include <stdio.h>
#include <stdlib.h>
#include "help.h"
#include "colors/ansi_escapes.h"

void desc() {
  printf("c-power4 Game \nHelp with usage of this simple program");
  printf("\n-------------------------\n");
  printf("\tUsage : ./c-power4 from any shel\n");
}

void commands() {
  printf("\tStart a game : --start -s\n");
  printf("\tPrint help : --help -h\n");
}

void error_usage() {
  printTextColor(RED_TXT, "Error : Wrong usage of the cli, printing help...\n");
}

void help(int error) {
  if (error == 1) error_usage();

  desc();
  commands();
}
