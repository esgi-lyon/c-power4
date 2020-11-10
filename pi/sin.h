#ifndef PI_INCLUDED
#define PI_INCLUDED

int factorial(int x)
{
  int i, sum = 1;
  for (i = 1; i <= x; i++)
  {
    sum = sum * i;
  }

  return sum;
}

int power(int x, int y)
{
  unsigned long long int i, sum = 1;
  for (i = 1; (int) i <= y; i++)
  {
    sum = sum * x;
  }

  return sum;
}

double userSin(int z, int ieration)
{
  int i = 1;
  double sum = 0;

  for (i = 1; i < ieration; i += 2)
  {
    double value, pow, fact = 0;

    pow = power(z, i);
    fact = factorial(i);
    value = pow / fact;

    if (((i - 1) / 2) % 2 != 0) {
      sum = sum - value; // ((power(x,i)) / factorial(i));
    } else {
      sum = sum + value;
    }
  }

  return sum;
}

#endif
