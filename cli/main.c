#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

/**
 * Main entry of game
 * start it from here and consult manual
 */
int main(int argc, char* argv[])
{
  int start_cmd = 0;
  int help_cmd = 0;
  char *cvalue = NULL;
  int index;
  int c;

  while ((c = getopt(argc, argv, "h:")) != -1)
    switch (c) {
      case 'h':
        help_cmd = 1;
        break;
      case '?':
        fprintf(stderr, "Error using arg : %c | check help", c);
        return 1;
      default:
        abort();
    }

  printf ("aflag = %d, bflag = %d, cvalue = %s\n",
          start_cmd, help_cmd, cvalue);

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);

  return 0;
}
