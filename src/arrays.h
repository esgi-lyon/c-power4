#include <stdlib.h>
#include <stdio.h>

#ifndef ARRAYS_INCLUDED
#define ARRAYS_INCLUDED

void arraysPlay() {
  int k = 3, n = 1;
  int **tab;
  tab = (int**) malloc(n * sizeof(int));

  for(int i = 0; i < k; i++) {
    printf("Tab index : %d\n", i);
    tab[i] = (int *) malloc(sizeof(tab[i]));
    printf("Tab pointer value : %d\n", *tab[i]);
    free(tab[i]);
  }

  free(tab);
}

#endif
