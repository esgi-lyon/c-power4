#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "types.h"
#include "pointers.h"
#include "bit.h"
#include "arrays.h"

int main(int argc, char **argv)
{
  // Fetch args
  char const *option = argv[0];
  char argvArr[argc];
  printf("file running : %s", option);
  if (argc > 1) {
    printf("%c", argvArr[0]);
  }
  // Address / use functions lib
  int p = 4;
  printf("\nAddress of var p is: %p", &p);
  printf("\n%d", Sum(p, 4));
  // Structs
  struct Books Book1;
  strcpy(Book1.author, "Benjamin aucul");
  Book1.id = 1;
  // User enum
  printf("\nWeektype day id : %d", Mon);
  // Pointers
  memoryPlay();
  // bits
  bitPlay();
	// Arrays
	arraysPlay();
  // Multidim test
  testMultidimInt();

  return TRUE;
}
