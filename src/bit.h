#ifndef BIT_H_INCLUDED
#define BIT_H_INCLUDED

typedef struct
{
  int unsigned pret  : 1; // unsigned => -16 + 15
  int unsigned ok1   : 5;
  int                : 2; // Unused bits
  int          data1 : 1;
      unsigned ok2   : 12;
  int          data2 : 5;
} state;

/**
 * @brief Bit example
 *
 */
void bitPlay()
{
  state st;
  st.ok1 = 1;
  // TODO try to print struct
}

#endif
