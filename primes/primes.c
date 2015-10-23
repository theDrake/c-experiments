#include <stdio.h> /* printf */

#define FALSE 0
#define TRUE 1

int is_prime(int number) {
  int i;

    /* Make negative input positive. */
  if (number < 0) {
    number *= -1;
  }

    /* The number 2 is prime by definition. */
  if (number == 2) {
    return TRUE;
  }

    /* The number 1 and all even numbers other than 2 are not prime. */
  if (number == 1 || number % 2 == 0) {
    return FALSE;
  }

    /* Check all odd numbers above 1 to see if they are prime. */
  for (i = 3; i <= (number / 2); i++) {
    if (number % i == 0) {
      return FALSE;
    }
  }

  return TRUE;
}

void conjecture(int low, int high) {
  int i, j, k,
      primeSumFound = FALSE;  /* Ensures one sum is printed per even number. */

  for (i = low; i <= high; i++) {
    if (i % 2 == 0) {
      for (j = 2; j < high; j++) {
        if (is_prime(j)) {
          for (k = j; k < high; k++) {
            if (k + j == i && is_prime(k)) {
              primeSumFound = TRUE;
              printf("%3i = %3i + %3i\n", i, j, k);
              break;
            }
          }
        }
        if (primeSumFound) {
          primeSumFound = FALSE;
          break;
        }
      }
    }
  }
}
