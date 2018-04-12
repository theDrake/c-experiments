/*******************************************************************************
   Filename: palindrome.c

     Author: David C. Drake (http://davidcdrake.com)

Description: Contains two functions for determining whether a given array of
             characters constitutes a palindrome.
*******************************************************************************/

/*******************************************************************************
   Function: is_palindrome1

Description: Determines if an array of characters is a palindrome by means of
             array subscripting.

     Inputs: phrase - The array to be tested.
             length - Number of characters in the array.

    Outputs: Returns 1 if the phrase is a palindrome, 0 otherwise.
*******************************************************************************/
int is_palindrome1(const char phrase[], int length) {
  int i, j;

  for (i = 0, j = length - 1; i < j; i++, j--) {
    if (phrase[i] != phrase[j]) {
      return 0;
    }
  }

  return 1;
}

/*******************************************************************************
   Function: is_palindrome2

Description: Determines if an array of characters is a palindrome by means of
             pointers.

     Inputs: phrase - Pointer to the first character of the array.
             length - Number of characters in the array.

    Outputs: Returns 1 if the phrase is a palindrome, 0 otherwise.
*******************************************************************************/
int is_palindrome2(const char *phrase, int length) {
  const char *pChar1 = phrase,                 /* Pointer to first char. */
             *pChar2 = phrase + (length - 1);  /* Pointer to last char.  */

  while (pChar1 < pChar2) {
    if (*pChar1 != *pChar2) {
      return 0;
    }
    pChar1++;
    pChar2--;
  }

  return 1;
}
