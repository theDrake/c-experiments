/******************************************************************************
   Filename: jumble.c

     Author: David C. Drake (http://davidcdrake.com)

Description: Contains two string-related functions: "mystrlen" and "jumble".
             The former determines the length of a given string, the latter
             encodes/decodes a given string.
******************************************************************************/

#include "jumble.h" /* mystrlen, jumble, ENCODE, DECODE                      */
#define NULL 0      /* Value of the NULL-termination character.              */

/******************************************************************************
   Function: mystrlen

Description: Returns the length of a given NULL-terminated string (i.e., the
             number of characters in the string), excluding NULL. Returns -1 if
             the string's length is too large for a signed int variable.

     Inputs: string - A pointer to a constant unsigned character, which should
                      in turn be the first character of a NULL-terminated
                      string. (The character may be NULL, in which case the
                      string's length is 0.)

    Outputs: The number of characters in the string, up to but not including
             its NULL-terminator, in integer format. (Or -1 if the string
             length is too long to be encoded as a signed integer.)
******************************************************************************/
int mystrlen(const unsigned char *string)
{
  int length              = 0;      /* To count characters in the string.   */
  const unsigned char *cp = string; /* To examine the string.                */

  if (cp)
  {
    while (*cp != NULL)
    {
      length++;
      cp++;
        /*
         * If the string is too long to be encoded as a signed integer,
         * "length" will eventually become negative due to overflow. In such
         * cases, the value -1 will be returned.
         */
      if (length < 0)
      {
        return -1;
      }
    }
  }

  return length;
}

/******************************************************************************
   Function: jumble

Description: Encodes or decodes a given string (by adding to or subtracting
             from its characters the values of corresponding characters in a
             given  password).

     Inputs: string   - The string to be altered (encoded or decoded).
             password - Used in the encoding/decoding process.
             method   - Either ENCODE or DECODE.
             passes   - Number of times to run through the encoding/decoding
                        algorithm.

    Outputs: None (but the input string is altered).
******************************************************************************/
void jumble(unsigned char *string,
            const unsigned char *password,
            enum CODE_METHOD method,
            int passes)
{
  int i;                              /* for loop variable                   */
  unsigned char *strPointer;          /* Pointer for overwriting "string".   */
  const unsigned char *pwPointer;     /* Pointer for reading the "password". */
  int strLength = mystrlen(string);   /* Number of characters in "string".   */
  int pwLength  = mystrlen(password); /* Number of characters in "password". */

    /*
     * Encoding/decoding should proceed only if both "string" and "password"
     * contain at least one non-NULL character and are not extremely long. If
     * either of these conditions is not met, the value returned by mystrlen
     * will be 0 or -1 respectively.
     */
  if (strLength > 0 && pwLength > 0)
  {
      /*
       * The number of times to pass through the encoding/decoding algorithm is
       * determined by the parameter "passes".
       */
    for (i = 0; i < passes; i++)
    {
      strPointer = string;
      pwPointer  = password;
      if (strPointer && pwPointer)
      {
        do
        {
          if (method == ENCODE)
          {
              /*
               * To encode, add to each char in "string" the value of a
               * corresponding char in "password".
               */
            *strPointer += *pwPointer;
          }
          else /* method == DECODE */
          {
              /*
               * To decode, subtract from each char in "string" the value of a
               * corresponding char in "password".
               */
            *strPointer -= *pwPointer;
          }
          strPointer++;
          pwPointer++;
            /*
             * If the end of "password" has now been reached, point to its
             * first element again.
             */
          if (pwPointer - password >= pwLength)
          {
            pwPointer = password;
          }
        }while (strPointer - string < strLength);
      }
    }
  }
}
