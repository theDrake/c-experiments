#include <stdio.h>  /* printf, sprintf, fopen, fread, fclose */

#define MIN_ASCII 32
#define MAX_ASCII 126

/******************************************************************************
   Function: format

Description: Given an array of characters, formats the characters as a line of
             hexadecimal numbers, including file offset and ASCII letters. Only
             the printable ASCII characters are displayed. Non-printable
             characters are displayed as a period. The file offset is shown
             as hexadecimal numbers.

     Inputs: inbuf  - The array of characters to format.
             outbuf - The formatted array, including offset and ASCII letters.
             count  - Number of characters in the input array.
             start  - Starting value of the 6-digit offset.

    Outputs: None. However, the outbuf parameter has been modified for the
             client.
******************************************************************************/
static void format(const char* inbuf, char *outbuf, int count, int start)
{
  int i;                    /* for loop variable                             */
  const char *pIn = inbuf;  /* To read through the input buffer twice.       */

    /* Add the 6-digit file offset in hexadecimal format.                    */
  sprintf(outbuf, "%.6X ", (unsigned int) start);
  outbuf += 7;

    /* Add input characters in hexadecimal format.                           */
  for (i = 0; i < count; i++, pIn++)
  {
    sprintf(outbuf, "%.2X ", (unsigned char) *pIn);
    outbuf += 3;
    if (i == 7)
    {
      sprintf(outbuf++, " ");  /* Extra space added after the 8th byte.      */
    }
  }
  for (i = count; i < 16; i++) /* Extra spaces if count < 16.                */
  {
    sprintf(outbuf, "   ");
    outbuf += 3;
    if (i == 7)
    {
      sprintf(outbuf++, " ");
    }
  }
  sprintf(outbuf, "  ");       /* Extra spaces added after the 16th byte.    */
  outbuf += 2;
  pIn = inbuf;                 /* Point pIn at the beginning of inbuf again. */

    /* Add input characters again, this time in ASCII format.                */
  for (i = 0; i < count; i++, pIn++)
  {
    if (*pIn < MIN_ASCII || *pIn > MAX_ASCII)
    {
      sprintf(outbuf++, ".");
    }
    else
    {
      sprintf(outbuf++, "%c", *pIn);
    }
  }
}

/******************************************************************************
   Function: dump

Description: Given the name of a file, formats each 16 bytes of that file as a
             hexadecimal number.

     Inputs: filename - Name of the file of interest.

    Outputs: None.
******************************************************************************/
void dump(const char *filename)
{
  FILE *infile;         /* File pointer for input                    */
  char inbuf[16] = {0}; /* Read/format 16 bytes at a time            */
  char outbuf[75];      /* The longest formatted string              */
  int bytes      = 0;   /* Number of bytes read in one call of fread */
  int totalBytes = 0;   /* Total number of bytes read from the file  */

  infile = fopen(filename, "rb");
  if (infile == NULL)
  {
    return;
  }
  printf("%s:\n", filename);

  while (!feof(infile))
  {
    bytes = fread(inbuf, 1, 16, infile);
    format(inbuf, outbuf, bytes, totalBytes);
    printf("%s\n", outbuf);
    totalBytes += bytes;
  }

  fclose(infile);
}
