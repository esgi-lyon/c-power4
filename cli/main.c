#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "help.h"

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

        if (opt == -1) {
            help();
            break;
        }

        switch (opt) {
          case 's':
              help();
              break;
          case 'h':
              fprintf(stdout, "Got bar\n");
              break;
          default:
              help();
              return 1;
        }
    }
    return 0;
}
