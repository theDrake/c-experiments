/******************************************************************************
   Filename: palindrome2.c

     Author: David C. Drake (http://davidcdrake.com)

Description: Contains a function for determining whether an array of characters
             is a palindrome (by means of pointers).
******************************************************************************/

/******************************************************************************
   Function: is_palindrome2

Description: Determines if an array of characters is a palindrome by means of
             pointers.

     Inputs: phrase - Pointer to the first character of the phrase to be
                      tested.
             length - Number of characters in the phrase.

    Outputs: Returns 1 (true) if the phrase is a palindrome, 0 (false) if it is
             not a palindrome.
******************************************************************************/
int is_palindrome2(const char *phrase, int length)
{
  const char *pChar1 = phrase;                /* Pointer to the first char.  */
  const char *pChar2 = phrase + (length - 1); /* Pointer to the last char.   */

    /*
     * Starting at both ends of the array, check for equality between the pair
     * of characters, then move inward and repeat. If an unequal pair is found,
     * the phrase is not a palindrome.
     */
  while (pChar1 < pChar2)
  {
    if (*pChar1 != *pChar2)
    {
      return 0;
    }
    pChar1++;
    pChar2--;
  }

    /*
     * If we made it through the for loop without finding an unequal pair, the
     * phrase is a palindrome.
     */
  return 1;
}
