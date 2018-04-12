/*******************************************************************************
   Filename: numbers.c

     Author: David C. Drake (http://davidcdrake.com)

Description: Prompts the user for three numbers between 0 and 9.999 then prints
             their sin, cos, tan, and atan values.
*******************************************************************************/

#include <math.h>   /* sin, cos, tan, atan */
#include <stdio.h>  /* scanf, printf       */

int main(void) {
  float input1, input2, input3;

  printf("Enter 3 numbers between 0 and 9.999: ");
  scanf("%f%f%f", &input1, &input2, &input3);
  printf("\nNumber      sin      cos      tan      atan\n"
         "-------------------------------------------\n");
  printf("%.5f %8.3f %8.3f %8.3f %8.3f\n",
         input1, sin(input1), cos(input1), tan(input1), atan(input1));
  printf("%.5f %8.3f %8.3f %8.3f %8.3f\n",
         input2, sin(input2), cos(input2), tan(input2), atan(input2));
  printf("%.5f %8.3f %8.3f %8.3f %8.3f\n",
         input3, sin(input3), cos(input3), tan(input3), atan(input3));

  return 0;
}
