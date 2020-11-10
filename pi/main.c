#include <stdio.h>
#include <stdlib.h>
#include "sin.h"
#include "leibniz.h"
#include "eq.h"

void sinExo() {
  printf("Pi step : \n");
  for (int n = 10; n <= 100000000; n*=10) {
    printf("\t n = %7i : pi= %.14f\n", n, Leibniz(n));
  }

  printf("sin step : \n");
  printf("\t n = %7i : sin= %.2f\n", 3, userSin(3, 12));
}


/**
 * @brief Main
 *
 * @return int
 */
int main()
{
  printf("Exo Sinus\n");
  sinExo();

  printf("\nExo equation 2nd degree\n");
  equation(1, 9, 4);

  return 0;
}
