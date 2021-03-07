#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "hello/test.h"

int main()
{
  printf("%s", "Hello World");
  int a = Sum(2, 3);
  printf("%d", a);
  printf("%s", test());
  return 0;
}
