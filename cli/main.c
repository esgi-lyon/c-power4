// Console libs
#ifdef _WIN32
#define  _CRT_SECURE_NO_WARNINGS 1
#include <windows.h>
  #if __has_include("<getopt.h>")
    #include <getopt.h>
  #endif
#else
#include <termios.h>
#include <getopt.h>
#endif
// standard libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// internal
#include "help.h"
#include "level.h"
#include "colors/ansi_escapes.h"

/**
 * Main entry of game
 * start it from here and consult manual
 */
int main(int argc, char* argv[])
{
    setupConsole();

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

    restoreConsole();
    return 0;
}
