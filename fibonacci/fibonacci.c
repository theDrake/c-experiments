/*
 * Prints "n + 1" rows of Fibonacci numbers and Fibonacci quotients, where "n"
 * is between 2 and 46, inclusive.
 */

#include <stdio.h> /* printf, scanf */

int main (void)
{
  int n;                    /* To store user input.                          */
  int x;                    /* A for loop counter.                           */
  int fibonacciNumber;      /* To store Fibonacci numbers in a for loop.     */
  int previousFibNum1;      /* To store previous Fibonacci numbers (x - 1).  */
  int previousFibNum2;      /* To store previous Fibonacci numbers (x - 2).  */
  double fibonacciQuotient; /* To store Fibonacci quotients.                 */

  do
  {
    /* Prompt the user for appropriate input. */
    printf ("Enter the Fibonacci number to calculate.\n"
            "Must be an integer between 2 and 46. (Enter 1 to quit): ");
    scanf ("%d", &n);

    /* If the user enters "1" as input, end the program. */
    if (n == 1)
    {
      return 0;
    }
  }while (n < 2 || n > 46);

  /* Print the header for the table. */
  printf ("\n           Fibonacci        Fibonacci\n N           number       "
          "  quotient\n-------------------------------------\n");

  /* Print the first two rows of data. */
  printf ("%2d%14d                  N/A\n", 0, 0);
  printf ("%2d%14d                  N/A\n", 1, 1);

  /*
   * Initialize the "previousFibNum" variables with the values of the first two
   * Fibonacci numbers.
   */
  previousFibNum2 = 0;
  previousFibNum1 = 1;

  /* Print the remaining rows of data up to and including "n". */
  for (x = 2; x <= n; x++)
  {
    /* Calculate the new Fibonacci number based on the last two values. */
    fibonacciNumber = previousFibNum1 + previousFibNum2;

    /* Calculate the quotient based on current and previous numbers. */
    fibonacciQuotient = (double) fibonacciNumber / (double) previousFibNum1;
    printf ("%2d%14d%21.16f\n", x, fibonacciNumber, fibonacciQuotient);

    /* Update the previous Fibonacci numbers. */
    previousFibNum2 = previousFibNum1;
    previousFibNum1 = fibonacciNumber;
  }

  return 0;
}
