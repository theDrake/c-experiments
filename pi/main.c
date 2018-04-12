/*
 * For testing the "circle_pi" and "leibniz_pi" functions in "pi.c".
 */

#include <stdio.h>  /* scanf, printf */

double circle_pi(int rectangles);   /* Calculates PI using a quarter circle. */
double leibniz_pi(int iterations);  /* Calculates PI using a series.         */

int main(void) {
  int i;

  printf("Approximations for pi\n"
         "Iterations      Circle Method   Leibniz Method\n"
         "----------------------------------------------\n");
  for (i = 1; i <= 1000000; i *= 10) {
    double pi_circle = circle_pi(i),
           pi_leibniz = leibniz_pi(i);
    printf("%10i%20.12f%16.12f\n", i, pi_circle, pi_leibniz);
  }

  return 0;
}
