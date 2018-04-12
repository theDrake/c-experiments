#include <stdio.h>  /* fopen, fgetc, ungetc, fclose */

#define BOOL  int
#define FALSE 0
#define TRUE  1

void strip(const char *filename) {
  FILE *infile;
  int c1, c2;
  BOOL readingComment = FALSE;
  BOOL readingString = FALSE;

  infile = fopen(filename, "rt");
  if (infile == NULL) {
    return;
  }

  while (!feof(infile)) {
    if (readingComment) {
      c1 = fgetc(infile);
      if (c1 == '*') {  /* Check for end of comment. */
        c2 = fgetc(infile);
        if (c2 == '/') {
          readingComment = FALSE;
        } else {
          ungetc(c2, infile);
        }
      }
    } else if (readingString) {
      c1 = fgetc(infile);
      if (c1 != '\\') {  /* Check for end of string. */
        c2 = fgetc(infile);
        if (c2 == '"') {
          readingString = FALSE;
        }
        printf("%c%c", c1, c2);
      } else {
        printf("%c", c1);
      }
    } else {  /* Not reading comment/string. */
      c1 = fgetc(infile);
      if (c1 != '\\') {
        c2 = fgetc(infile);
        if (c2 == '"') {  /* Check for string. */
          readingString = TRUE;
          printf("%c%c", c1, c2);
        } else if (c1 == '/' && c2 == '*') {  /* Check for comment. */
          readingComment = TRUE;
        } else {
          printf("%c", c1);
          ungetc(c2, infile);
        }
      } else {
        printf("%c", c1);
      }
    }
  }

  fclose(infile);
}
