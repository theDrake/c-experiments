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
  int low;        /* the lower bound                      */
  int high;       /* the upper bound                      */
  int input;      /* user input                           */
  int num;        /* number for computer to guess         */
  int guess;      /* computer's current guess             */
  int lowerBound; /* lower bound deduced through guessing */
  int upperBound; /* upper bound deduced through guessing */
  int tries;      /* number of tries/guesses              */

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
    lowerBound = low - 1;
    upperBound = high + 1;
    tries      = 0;
    do
    {
      printf("Pick a number for me to guess (between %d and %d, 0=quit): ",
             low,
             high);
      scanf("%d", &input);
      myfflush();
      if (input == 0)
      {
        printf("Bye.\n");
        return 0;
      }
    }while(input < low || input > high);
    num = input;
    do
    {
      guess = (upperBound - lowerBound) / 2 + lowerBound;
      printf("Is the number %d? (1=too low, 2=too high, 3=correct, 0=quit)",
             guess);
      tries++;
      do
      {
        scanf("%d", &input);
        myfflush();
      }while (input < 0 || input > 3);
      switch (input)
      {
        case 1:
          if (guess == num)
            printf("What? You think you can get away with that?\n");
          else
            lowerBound = guess;
          break;
        case 2:
          if (guess == num)
            printf("What? You think you can get away with that?\n");
          else
            upperBound = guess;
          break;
        case 3:
          if (guess != num)
          {
            printf("I know that I didn't guess it yet.\n");
            guess = num;
          }
          break;
        case 0:
          printf("Bye.\n");
          return 0;
        default:
          break;
      }
    }while (guess != num);
    printf("I guessed your number in %d ", tries);
    if (tries == 1)
      printf("guess!\n");
    else
      printf("guesses!\n");
    printf("Play again? (1=yes, 0=no): ");
    scanf("%d", &input);
    myfflush();
  }while(input != 0);
  printf("Bye.\n");

  return 0;
}
