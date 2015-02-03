/******************************************************************************
   Filename: pi.c

     Author: David C. Drake (http://davidcdrake.com)

Description: Contains two functions for approximating the value of pi:
             "circle_pi" and "leibniz_pi".
******************************************************************************/

#include <math.h>      /* sqrt                */
#define RADIUS 1.0     /* Used in circle_pi.  */
#define NUMERATOR 1.0  /* Used in leibniz_pi. */

/******************************************************************************
   Function: circle_pi

Description: Given a number of rectangles N, estimate the area of a quarter
             circle by calculating the area of N rectangles that approximate as
             closely as possible the area of that quarter circle. Use this
             value to estimate the value of pi/4 (and thereby, pi).

     Inputs: rectangles - The number of rectangles to be used in estimating the
                          area of a quarter circle.

    Outputs: An approximation of the value of pi (double format).
******************************************************************************/
double circle_pi(int rectangles)
{
  int x;                  /* for loop counter.                */
  double width     = 0.0; /* Width of each rectangle.         */
  double area      = 0.0; /* Combined area of all rectangles. */
  double piFourths = 0.0; /* Approximated value of pi/4.      */

  if (rectangles > 0)
  {
    width = RADIUS / rectangles;  /* Same for every rectangle. */
  }
  for (x = 1; x <= rectangles; x++)
  {
    double midpoint;
    double height;

    midpoint = (width * x) - (width / 2);
    height   = sqrt(RADIUS * RADIUS - midpoint * midpoint);
    area    += width * height;
  }
  if (RADIUS > 0)
  {
    piFourths = area / (RADIUS * RADIUS);
  }

  return piFourths * 4; /* Returns an approximation of pi. */
}

/******************************************************************************
   Function: leibniz_pi

Description: Given a number of iterations N, estimate the value of pi/4 (and
             thus also pi) by carrying out N steps of the following pattern:
              1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + ...

     Inputs: iterations - Number of steps to carry out in follwoing Leibniz's
                          algorithm. (Should actually be infinite, ideally).

    Outputs: An approximation of the value of pi (double format).
******************************************************************************/
double leibniz_pi(int iterations)
{
  int counter      = 1;    /* while loop counter.                  */
  int denominator  = 1;    /* For Leibniz's fractions. Always odd. */
  double piFourths = 0.0;  /* Approximated value of pi/4.          */

  while (counter <= iterations)
  {
    if (counter % 2 > 0 && denominator > 0) /* Odd iterations. */
    {
      piFourths += NUMERATOR / denominator;
    }
    else if (denominator > 0) /* Even iterations. */
    {
      piFourths -= NUMERATOR / denominator;
    }
    counter++;
    denominator += 2; /* Increase denominator to the next odd value. */
  }

  return piFourths * 4; /* Returns an approximation of pi. */
}
