/*
 * Prints "n + 1" rows of Fibonacci numbers and Fibonacci quotients, where "n"
 * is between 2 and 46, inclusive.
 */

#include <stdio.h> /* printf, scanf */

int main(void) {
  int n, i, fibonacciNumber, previousFibNum1, previousFibNum2;
  double fibonacciQuotient;

  do {
    printf("Enter an integer between 2 and 46, inclusive (or 0 to quit): ");
    scanf ("%d", &n);
    if (n == 0) {
      return 0;
    }
  }while (n < 2 || n > 46);

  printf("\n           Fibonacci        Fibonacci\n N           number        "
         "  quotient\n-------------------------------------\n");
  printf("%2d%14d                  N/A\n", 0, 0);
  printf("%2d%14d                  N/A\n", 1, 1);
  previousFibNum2 = 0;
  previousFibNum1 = 1;
  for (i = 2; i <= n; i++) {
    fibonacciNumber = previousFibNum1 + previousFibNum2;
    fibonacciQuotient = (double) fibonacciNumber / (double) previousFibNum1;
    printf("%2d%14d%21.16f\n", i, fibonacciNumber, fibonacciQuotient);
    previousFibNum2 = previousFibNum1;
    previousFibNum1 = fibonacciNumber;
  }

  return 0;
}
