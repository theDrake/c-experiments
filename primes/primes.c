#include <stdio.h> /* printf */

#define FALSE 0
#define TRUE  1

int is_prime(int number)
{
  int x;  /* for loop counter */

    /* Make negative input positive. */
  if (number < 0)
  {
    number *= -1;
  }

    /* The number 2 is prime by definition. */
  if (number == 2)
  {
    return TRUE;
  }

    /* The number 1 and all even numbers other than 2 are not prime. */
  if (number == 1 || number % 2 == 0)
  {
    return FALSE;
  }

    /* Check all odd numbers above 1 to see if they are prime. */
  for (x = 3; x <= (number / 2); x++)
  {
    if (number % x == 0)
    {
      return FALSE;
    }
  }

  return TRUE;
}

void conjecture(int low, int high)
{
  int x, y, z;                /* for loop counters                           */
  int primeSumFound = FALSE;  /* Ensures one sum is printed per even number. */

  for (x = low; x <= high; x++)
  {
    if (x % 2 == 0)
    {
      for (y = 2; y < high; y++)
      {
        if (is_prime(y))
        {
          for (z = y; z < high; z++)
          {
            if (z + y == x && is_prime(z))
            {
              primeSumFound = TRUE;
              printf("%3i = %3i + %3i\n", x, y, z);
              break;
            }
          }
        }
        if (primeSumFound)
        {
          primeSumFound = FALSE;
          break;
        }
      }
    }
  }
}
