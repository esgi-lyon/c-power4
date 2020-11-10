#include <stdlib.h>

#ifndef POINTERS_H_INCLUDED
#define POINTERS_H_INCLUDED

#define BUFF_SIZE 512

/**
 * @brief Terrible pointer example
 */
void memoryPlay()
{
  // Simple memory allocation
  float* p1 = malloc(sizeof(BUFF_SIZE));
  printf("\naddress pointed to by pointer 1 : %p", p1);
  printf("\npointer 1 address %p", &p1);
  printf("\npointer 1 pointed value %0.2f", *p1);

  // Allow a memory of max int authorized bits
  int* p2;
  p2 = (int*) malloc(sizeof(int));

  // complex calc
  int i = 1, j = 3;
  p2 = (int *) malloc(2 * sizeof(int));
  *p2 = i;
  *(p2 + 1) = j;
  printf("\np2 = %ld \t *p2=%d \t p2+1=%ld\t*(p2+1)=%d", (long) p2, *p2, (long) p2+1, *(p2+1));

  // dynamic allocation (avoid segmentation error)
  float* p3 = malloc(sizeof(*p3));
  if (p3 == NULL)
    printf("\npointer 3 is null");
    goto end; // WTF goto

  printf("\npointer address %p, %.6f", (void *) &p3, *p3);

  end:
    free(p1); free(p2); free(p3);

  return;
}

int** multiDimensionInt(int N) {

  int** a = malloc(sizeof *a *N);

  if (!a)
    return a;

  for(int i = 0; i < N; i++) {
    a[i] = malloc(sizeof *a[i]);
  }

  return a;
}

void testMultidimInt() {
  int dimension = 3;
  int** arr = multiDimensionInt(dimension);
  printf("\nMultidim pointer address: %p", *arr);
  // int depth = 0
  // for ()
}

/*
void pPP(char ch) {

  int res = 0;
  int* p = 0;
  // for (int i = 0; i < (int) strlen(ch); i++)
  //   *p++ = ch[i];

}
*/

#endif
