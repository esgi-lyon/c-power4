#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef EQ_H_INCLUDED
#define EQ_H_INCLUDED

/**
 * @brief Ecrire en C le programme solutionnant l’équation suivante
 *        -----------------------
 *        ax^2 + bx + c = 0
 *        Δ= b2 -4ac
 *        X0 = (-b +/- √ Δ) /2a
 * @param a
 * @param b
 * @param c
 */
void equation(int a, int b, int c) {
  printf("equation ax^2 + bx + c: \n");
  if (a <= 0) {
    printf("Not a 2nd degree equation\n");
    exit(1);
  }

  printf("Δ = b2 -4ac: \n");
  double delta = pow(b, 2) - (4 * a * c);

  if (delta < 0) {
    printf("delta : %.4f is negative or null (exiting...)\n", delta);
    exit(0);
  } else if (delta == 0) {
    double x = -b / 2 * a;
    printf("One result : %.4f \n", x);
  } else {
    printf("X0 = (-b +/- √ Δ) /2a: \n");
    double XO = (- b) - sqrt(delta) / 2 * a;
    double X1 = (- b) + sqrt(delta) / 2 * a;
    printf("Solutions : %0.4f; %0.4f", XO, X1);
  }
}

#endif
