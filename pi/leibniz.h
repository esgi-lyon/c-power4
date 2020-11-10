#ifndef LEIBNIZ_INCLUDED
#define LEIBNIZ_INCLUDED

double myPow(int x, int y)
{
  unsigned long long int i, sum = 1;
  for (i = 1; (int)i <= y; i++)
  {
    sum = sum * x;
  }
  return sum;
}

double Leibniz(int n)
{
  double pi = 1.0;
  for (int i = 1; i <= n; ++i)
    // (i & 1) ? -1.0 : 1.0 : Moins Un Puissance N
    pi += ((i & 1) ? -1.0 : 1.0) / ((2 * i) + 1);

  return 4 * pi;
}

#endif
