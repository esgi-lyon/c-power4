#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "help.h"
#include "level.h"

/**
 * Main entry of game
 * start it from here and consult manual
 */
int main(int argc, char* argv[])
{
    static const struct option longopts[] = {
        {.name = "start", .has_arg = no_argument, .val = 's'},
        {.name = "help", .has_arg = no_argument, .val = 'h'}
    };
    for (;;) {
        int opt = getopt_long(argc, argv, "sh", longopts, NULL);

        switch (opt) {
          case 's':
              loop_level();
              return 0;
          case 'h':
              help(0);
              return 0;
          default:
              help(1);
              return 1;
        }
    }
    return 0;
}
