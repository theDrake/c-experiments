#include <stdio.h> /* printf */

#define MIN 100
#define MAX 999

void print_cubes ()
{
  int x, d1, d2, d3, c1, c2, c3, cubeSum;
	for (x = MIN; x <= MAX; x++)
	{
		d1 = x / 100;
		d2 = (x - d1 * 100) / 10;
		d3 = x - d1 * 100 - d2 * 10;
		c1 = d1 * d1 * d1;
		c2 = d2 * d2 * d2;
		c3 = d3 * d3 * d3;
		cubeSum = c1 + c2 + c3;
		if (cubeSum == x)
		{
			printf("%d has the cube property. (%d + %d + %d)\n", x, c1, c2, c3);
		}
	}
}

void print_pythagorean_triples(int low, int high)
{
  int n1, n2, n3, s1, s2, s3, tripleCounter = 0;
  for (n1 = low; n1 < high; n1++)
  {
    for (n2 = n1 + 1; n2 < high; n2++)
    {
      for (n3 = n2 + 1; n3 < high; n3++)
      {
        s1 = n1 * n1;
        s2 = n2 * n2;
        s3 = n3 * n3;
        if (s1 + s2 == s3)
        {
          printf("Triple #%3d:%4d,%3d,%3d", ++tripleCounter, n1, n2, n3);
          printf(" -->%5d +%5d =%5d\n", s1, s2, s3);
        }
      }
    }
  }
}
