#include <stdio.h> /* printf */

int is_prime(int n);
void conjecture(int low, int high);

void check_primes(int count)
{
  int i;          /* loop counter           */
  int primes = 0; /* number of primes found */

  for (i = 1; i <= count; i++)
  {
    if (is_prime(i))
    {
      primes++;
      printf("#%3i: %3i is prime.\n", primes, i);
    }
  }
}

int main(void)
{
  check_primes(1000);
  conjecture(2, 2000);

  return 0;
}
