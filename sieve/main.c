#include <stdio.h> /* printf                                         */
#include "sieve.h" /* sieve, twin_primes, brun_constant, TRUE, FALSE */

#define SIZE 10001 /* Size of the array */

int main(void) {
  int array[SIZE], /* Array of 0's and 1's         */
      count = 0,   /* Number of primes/twins found */
      i;           /* For-loop counter             */
  double bruns;    /* Brun's Constant              */

    /* Mark prime/non-prime numbers using the array  */
  sieve(array, SIZE - 1);

    /* Count the number of primes and print each one */
  for (i = 0; i < SIZE; i++) {
    if (array[i] == TRUE) {
      count++;
      printf("Prime #%04i:  %4i\n", count, i);
    }
  }

    /* Print the total number of primes that were found */
  printf("%i primes found between 0 and %i.\n", count, SIZE - 1);

    /* Find the number of twin primes and print it */
  count = twin_primes(array, SIZE - 1);
  printf("%i twin primes found between 0 and %i.\n", count, SIZE - 1);

    /* Get Brun's Constant and print it */
  bruns = brun_constant(array, SIZE - 1);
  printf("Brun's constant with %i twin primes is %1.12f.\n", count, bruns);

  return 0;
}
