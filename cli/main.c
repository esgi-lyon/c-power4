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
  int aflag = 0;
  int bflag = 0;
  char *cvalue = NULL;
  int index;
  int c;

  while ((c = getopt (argc, argv, "abc:")) != -1)
    switch (c)
      {
      case 'a':
        aflag = 1;
        break;
      case 'b':
        bflag = 1;
        break;
      case 'c':
        cvalue = optarg;
        break;
      case '?':
        fprintf(stderr, "Error using arg : %c | check help", c);
        return 1;
      default:
        abort();
      }

  printf ("aflag = %d, bflag = %d, cvalue = %s\n",
          aflag, bflag, cvalue);

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);

  return 0;
}
