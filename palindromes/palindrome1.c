/******************************************************************************
filename palindrome1.c
author   David C. Drake
email    david@davidcdrake.com

Brief Description:
  Contains a function for determining whether an array of characters is a
  palindrome (by means of array subscripting).

******************************************************************************/


/******************************************************************************
   Function: is_palindrome1

Description: Determines if an array of characters is a palindrome by means of
             array subscripting.

     Inputs: phrase - An array of characters to be tested (technically, a
                      pointer to the first element of said array).
             length - Number of characters in the array.

    Outputs: Returns 1 (true) if the phrase is a palindrome, 0 (false) if it is
             not a palindrome.
******************************************************************************/
int is_palindrome1(const char phrase[], int length)
{
  int i, j; /* for loop variables */

    /*
     * Starting at both ends of the array, check for equality between the pair
     * of characters, then move inward and repeat. If an unequal pair is found,
     * the phrase is not a palindrome.
     */
  for (i = 0, j = length - 1; i < j; i++, j--)
  {
    if (phrase[i] != phrase[j])
    {
      return 0;
    }
  }

    /*
     * If we made it through the for loop without finding an unequal pair, the
     * phrase is a palindrome.
     */
  return 1;
}
