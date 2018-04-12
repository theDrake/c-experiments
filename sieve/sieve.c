#include <stdio.h>  /* printf      */
#include <math.h>   /* sqrt        */
#include "sieve.h"  /* TRUE, FALSE */

void sieve(int array[], int size) {
  int i, j, squareRootOfSize = sqrt(size);

  for (i = 0; i <= size; i++) {
    array[i] = TRUE;
  }

    /* Zero and one are non-prime by defintion. */
  array[0] = FALSE;
  array[1] = FALSE;

    /*
     * For each prime index value, starting with two, set all elements located
     * at index values that are multiples of that number to FALSE because those
     * values are not prime.
     */
  for (i = 2; i <= squareRootOfSize; ++i) {
    if (array[i] == TRUE) {
      for (j = i + 1; j <= size; ++j) {
        if (j % i == 0) {
          array[j] = FALSE;
        }
      }
    }
  }
}

int twin_primes(const int primes[], int size) {
  int i, twinPrimes = 0;

    /*
     * For every TRUE value in the array (i.e., every index value that is
     * prime), check for a TRUE value at that index value + 2. If found, those
     * index values constitute a twin prime.
     */
  for (i = 0; i <= size - 2; ++i) {
    if (primes[i] == TRUE && primes[i + 2] == TRUE) {
      twinPrimes++;
      printf("twin prime #%4i: %4i and %4i\n", twinPrimes, i, i + 2);
    }
  }

  return twinPrimes;
}

double brun_constant(const int primes[], int size) {
  int i;
  double result = 0.0;

    /* Add the inverse of each twin prime value. */
  for (i = 0; i <= size - 2; ++i) {
    if (primes[i] == TRUE && primes[i + 2] == TRUE) {
      result += (1.0 / i) + (1.0 / (i + 2));
    }
  }

  return result;
}
