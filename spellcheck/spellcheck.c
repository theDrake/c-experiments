/******************************************************************************
   Filename: spellcheck.c

     Author: David C. Drake (http://davidcdrake.com)

Description: Contains the following functions for analyzing and utilizing
             dictionary files: "words_starting_with", "word_lengths", "info",
             and "spell_check". Also contains a "mystrupr" function for
             converting a string to uppercase.
******************************************************************************/

#include <string.h> /* strlen, strcmp                        */
#include <stdio.h>  /* FILE, fopen, feof, fgets, fclose      */

  /* FILE_OK, FILE_ERR_OPEN, WORD_OK, WORD_BAD, LONGEST_WORD */
#include "spellcheck.h"

/******************************************************************************
   Function: mystrupr

Description: Converts all lowercase letters in a given string to uppercase.

     Inputs: string - Pointer to the first character of the string of interest.

    Outputs: Pointer to the modified string.
******************************************************************************/
char *mystrupr(char *string)
{
  char *c;

  for (c = string; *c != '\0'; c++)
  {
    if (*c >= 'a' && *c <= 'z')
    {
      *c += ('A' - 'a');
    }
  }

  return string;
}

/******************************************************************************
   Function: words_starting_with

Description: Counts the number of words that start with a given letter within
             a dictionary indicated by a given filename.

     Inputs: dictionary - String containing the dictionary's filename.
             letter     - Letter of interest.

    Outputs: The number of words that start with "letter" (or FILE_ERR_OPEN if
             the dictionary can't be opened).
******************************************************************************/
int words_starting_with(const char *dictionary, char letter)
{
  int wordCount = 0;             /* Number of words starting with "letter".  */
  char buffer[LONGEST_WORD + 2]; /* To hold each word from the dictionary.   */
  FILE *infile;                  /* To open and read from the dictionary.    */

  if (letter >= 'a' && letter <= 'z')
  {
    letter += ('A' - 'a');
  }

  infile = fopen(dictionary, "rt");
  if (infile != NULL)
  {
    while (!feof(infile))
    {
      fgets(buffer, LONGEST_WORD + 1, infile); /* Read in the next word.     */
      mystrupr(buffer);
      if (buffer[0] == letter)
      {
        wordCount++;      /* Word starting with "letter" found.              */
      }
      else if (buffer[0] > letter)
      {
        break;            /* Stop searching (assumes alphabetical ordering). */
      }
    }
    fclose(infile);
  }
  else
  {
    return FILE_ERR_OPEN;
  }

  return wordCount;
}

/******************************************************************************
   Function: word_lengths

Description: Given the filename of a dictionary, counts the number of words of
             length 1 to "count" and stores each total in the "lengths" array.

     Inputs: dictionary - String containing the dictionary's filename.
             lengths    - Array of integers for storing the number of words of
                          lengths 1 to "count" (inclusive). Format: length[n]
                          will record the number of words of length "n".
             count      - Maximum length of interest (words longer than this
                          are ignored).

    Outputs: FILE_OK, or FILE_ERR_OPEN if the file can't be opened.
******************************************************************************/
int word_lengths(const char *dictionary, int lengths[], int count)
{
  int i;                         /* for loop variable                        */
  int wordLength;                /* To hold the length of each word read.    */
  char buffer[LONGEST_WORD + 2]; /* To hold each word from the dictionary.   */
  FILE *infile;                  /* To open and read from the dictionary.    */

    /* Clear all values in the array from 0 to "count", inclusive.           */
  for (i = 0; i <= count; i++)
  {
    lengths[i] = 0;
  }

  infile = fopen(dictionary, "rt");
  if (infile != NULL)
  {
    while (!feof(infile))
    {
      fgets(buffer, LONGEST_WORD + 1, infile); /* Read in the next word.     */
      wordLength = strlen(buffer);
      if (!feof(infile))
      {
        buffer[wordLength - 1] = '\0';         /* Replace '\n' with NULL.    */
        wordLength--;
        if (wordLength <= count)
        {
          lengths[wordLength]++;
        }
      }
    }
    fclose(infile);
  }
  else
  {
    return FILE_ERR_OPEN;
  }

  return FILE_OK;
}

/******************************************************************************
   Function: info

Description: Provides some basic information about a given dictionary file via
             three out parameters.

     Inputs: dictionary - String containing the dictionary's filename.
             shortest   - Length of the shortest word in the file.
             longest    - Length of the longest word in the file.
             num_words  - Total number of words in the file.

    Outputs: FILE_OK, or FILE_ERR_OPEN if the file can't be opened. (Also
             provides output via three out parameters.)
******************************************************************************/
int info(const char *dictionary, int *shortest, int *longest, int *num_words)
{
  int wordLength;                /* To hold the length of each word read.    */
  int wordCount = 0;             /* Number of words read from dictionary.    */
  char buffer[LONGEST_WORD + 2]; /* To hold each word from the dictionary.   */
  FILE *infile;                  /* To open and read from the dictionary.    */

    /* Initialize the out parameters.                                        */
  *shortest = LONGEST_WORD + 1;
  *longest  = 0;

  infile = fopen(dictionary, "rt");
  if (infile != NULL)
  {
    while (!feof(infile))
    {
      fgets(buffer, LONGEST_WORD + 1, infile); /* Read in the next word.     */
      wordLength = strlen(buffer);
      if (!feof(infile))
      {
        buffer[wordLength - 1] = '\0';         /* Replace '\n' with NULL.    */
        wordLength--;
        if (wordLength < *shortest && wordLength > 0)
        {
          *shortest = wordLength;
        }
        else if (wordLength > *longest)
        {
          *longest = wordLength;
        }
        wordCount++;
      }
    }
    *num_words = wordCount;
    fclose(infile);
  }
  else
  {
    return FILE_ERR_OPEN;
  }

  return FILE_OK;
}

/******************************************************************************
   Function: spell_check

Description: Looks for a given word in a dictionary indicated by a given
             filename.

     Inputs: dictionary - String containing the dictionary's filename.
             word       - String containing the word of interest.

    Outputs: WORD_OK if the word is found, WORD_BAD if the word is not found,
             or FILE_ERR_OPEN if the dictionary can't be opened.
******************************************************************************/
int spell_check(const char *dictionary, const char *word)
{
  char buffer[LONGEST_WORD + 2];    /* To hold each word from the file.      */
  char upperWord[LONGEST_WORD + 2]; /* To hold UPPERCASE version of "word".  */
  int wordLength;                   /* To hold the length of each word read. */
  FILE *infile;                     /* To open and read from the dictionary. */

  strcpy(upperWord, word);
  mystrupr(upperWord);
  infile = fopen(dictionary, "rt");
  if (infile != NULL)
  {
    while (!feof(infile))
    {
      fgets(buffer, LONGEST_WORD + 1, infile); /* Read in the next word.     */
      wordLength = strlen(buffer);
      buffer[wordLength - 1] = '\0';           /* Replace '\n' with NULL.    */
      wordLength--;
      if (strcmp(mystrupr(buffer), upperWord) == 0)
      {
        fclose(infile);

        return WORD_OK;   /* The word has been found.                        */
      }
      if (buffer[0] > upperWord[0])
      {
        break;            /* Stop searching (assumes alphabetical ordering). */
      }
    }
    fclose(infile);
  }
  else
  {
    return FILE_ERR_OPEN;
  }

  return WORD_BAD; /* If we reach this point, the word was not in the file.  */
}
