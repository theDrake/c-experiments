#include <stdio.h>   /* printf, scanf, getchar */
#include <stdlib.h>  /* rand, srand, atoi      */
#include <time.h>    /* time                   */

#define QUIT 0
#define CONTINUE 1
#define PLAYER_CHOOSES_NUMBER 1
#define COMPUTER_CHOOSES_NUMBER 2
#define TOO_LOW 1
#define TOO_HIGH 2
#define CORRECT 3

void FlushInput(void) {
  int c;

  while((c = getchar()) != '\n' && c != EOF)
    /* discard */ ;
}

int RandomInt(int low, int high) {
  return rand() % (high - low + 1) + low;
}

int main(int argc, char **argv) {
  int low,         /* the lower bound                      */
      high,        /* the upper bound                      */
      input,       /* user input                           */
      num,         /* number to be guessed                 */
      guess,       /* computer's current guess             */
      lowerBound,  /* lower bound deduced through guessing */
      upperBound,  /* upper bound deduced through guessing */
      tries;       /* number of tries/guesses              */

  if (argc < 2) {
    printf("Usage: %s low high\n"
           "       low  - the lower bound\n"
           "       high - the upper bound\n\n", argv[0]);

    return -1;
  }

  printf("Welcome to the Guessing Game!\n");
  low = atoi(argv[1]);
  high = atoi(argv[2]);
  srand((unsigned) time(0));
  do {
    lowerBound = low - 1;
    upperBound = high + 1;
    tries = 0;
    do {
      printf("Who shall pick a number? (%d=player, %d=computer, %d=quit) ",
             PLAYER_CHOOSES_NUMBER, COMPUTER_CHOOSES_NUMBER, QUIT);
      scanf("%d", &input);
      FlushInput();
    }while (input != PLAYER_CHOOSES_NUMBER &&
            input != COMPUTER_CHOOSES_NUMBER &&
            input != QUIT);
    if (input == PLAYER_CHOOSES_NUMBER) {
      do {
        printf("Pick a number for me to guess (between %d and %d, %d=quit): ",
               low, high, QUIT);
        scanf("%d", &input);
        FlushInput();
      }while (input != QUIT && (input < low || input > high));
      if (input != QUIT) {
        num = input;
        do {
          guess = (upperBound - lowerBound) / 2 + lowerBound;
          tries++;
          printf("Is the number %d? (%d=too low, %d=too high, %d=correct, "
                 "%d=quit) ", guess, TOO_LOW, TOO_HIGH, CORRECT, QUIT);
          do {
            scanf("%d", &input);
            FlushInput();
          }while (input != TOO_LOW && input != TOO_HIGH && input != CORRECT &&
                  input != QUIT);
          switch (input) {
            case TOO_LOW:
              if (guess == num)
                printf("What? You think you can get away with that?\n");
              else
                lowerBound = guess;
              break;
            case TOO_HIGH:
              if (guess == num)
                printf("What? You think you can get away with that?\n");
              else
                upperBound = guess;
              break;
            case CORRECT:
              if (guess != num) {
                printf("(Hey! I know I didn't really guess it yet.)\n");
                guess = num;
              }
              break;
            default:
              break;
          }
        }while (guess != num && input != QUIT);
      }
      if (input != QUIT) {
        printf("I guessed your number in %d ", tries);
        if (tries == 1) {
          printf("guess!\n");
        } else {
          printf("guesses!\n");
        }
      }
    } else if (input == COMPUTER_CHOOSES_NUMBER) {
      num = RandomInt(low, high);
      printf("Guess the number I'm thinking of (between %d and %d, %d=quit): ",
             low, high, QUIT);
      scanf("%d", &input);
      FlushInput();
      tries++;
      while (input != num && input != QUIT) {
        if (input < num) {
          printf ("Too low. ");
        } else {
          printf ("Too high. ");
        }
        printf ("Guess again: ");
        scanf("%d", &input);
        FlushInput();
        tries++;
      }
      if (input != QUIT) {
        printf("You guessed the number in %d ", tries);
        if (tries == 1) {
          printf("try!\n");
        } else {
          printf("tries!\n");
        }
      }
    }
    if (input != QUIT) {
      printf("Play again? (%d=yes, %d=no) ", CONTINUE, QUIT);
      scanf("%d", &input);
      FlushInput();
    }
  }while (input != QUIT);
  printf("Bye.\n");

  return 0;
}
