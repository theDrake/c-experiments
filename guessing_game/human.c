#include <stdio.h>  /* printf, scanf, getchar */
#include <stdlib.h> /* rand, srand, atoi      */
#include <time.h>   /* time                   */

/* flush out bad input */
void myfflush(void)
{
  int c;

  while((c = getchar()) != '\n' && c != EOF)
    /* discard */ ;
}

/* generate random numbers between low and high */
int RandomInt(int low, int high)
{
  return rand() % (high - low + 1) + low;
}

int main(int argc, char **argv)
{
  int low;   /* the lower bound          */
  int high;  /* the upper bound          */
  int num;   /* computer's chosen number */
  int input; /* user's input             */
  int tries; /* number of tries/guesses  */

    /* If the user didn't provide any arguments, quit */
  if (argc < 2)
  {
    printf("Usage: %s low high\n", argv[0]);
    printf("       low  - the lower bound\n");
    printf("       high - the upper bound\n\n");

    return -1;
  }

    /* Convert strings to integers */
  low  = atoi(argv[1]);
  high = atoi(argv[2]);

  srand((unsigned)time(0));

  do
  {
    num   = RandomInt(low, high);
    tries = 0;
    do
    {
      printf("Guess the number I'm thinking of (between %d and %d, 0=quit): ",
             low,
             high);
      scanf("%d", &input);
      myfflush();
      if (input == 0)
        return 0;
    }while(input < low || input > high);
    tries++;
    while (input != num)
    {
      if (input < num)
        printf ("Too low. ");
      else
        printf ("Too high. ");
      printf ("Guess again: ");
      scanf("%d", &input);
      myfflush();
      tries++;
    }
    printf("You guessed the number in %d ", tries);
    if (tries == 1)
      printf("try!\n");
    else
      printf("tries!\n");
    printf("Play again? (1=yes, 0=no): ");
    scanf("%d", &input);
    myfflush();
  }while(input != 0);

  return 0;
}
