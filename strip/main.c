#include <stdio.h> /* printf */

void strip(const char *filename); /* defined in strip.c */

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s filename\n", argv[0]);

    return -1;
  }

  strip(argv[1]);

  return 0;
}
