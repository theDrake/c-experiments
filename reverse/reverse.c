#include <string.h>

#define BOOL  int
#define FALSE 0
#define TRUE  1

static BOOL IsWhitespace(const char c)
{
  return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

  /* Helper function to reverse a range of characters. */
void ReverseSegment(char *start, char *end)
{
  char temp;

  while (start < end)
  {
    temp   = *start;
    *start = *end;
    *end   = temp;
    start++;
    end--;
  }
}

static void ReverseString(char string[])
{
  char *cp = string;

  if (cp)
  {
    while (*cp)
    {
      cp++;
    }
    ReverseSegment(string, cp - 1);
  }
}

int strtoint(const char string[])
{
  int result     = 0;
  int digit      = 0;
  const char *cp = string;
  BOOL negative  = FALSE;

  if (cp)
  {
    if(*cp == '-')
    {
      negative = TRUE;
      cp++;
    }

    while (*cp != 0 && *(cp + 1) != 0)
    {
      digit   = *cp - '0';
      result += digit;
      result *= 10;
      cp++;
    }
    if (*cp)
    {
      digit   = *cp - '0';
      result += digit;
    }

    if (negative)
    {
      result *= -1;
    }
  }

  return result;
}

void inttostr(int number, char string[])
{
  int i;  /* for loop variable */
  char *cp      = string;
  BOOL negative = FALSE;

  if (number == 0)
  {
    *cp       = '0';
    *(cp + 1) = 0;
    return;
  }

  if (number < 0)
  {
    negative = TRUE;
    number  *= -1;
  }

    /* Add digits to the string, starting with the one's place. */
  for (i = 1; i <= number; i *= 10)
  {
    *cp = ((number % (i * 10)) / i) + '0';
    cp++;
  }

    /* If negative, we need to add a '-' sign. */
  if (negative)
  {
    *cp = '-';
    cp++;
  }

    /* Null-terminate the string. */
  *cp = '\0';

    /* Now reverse the string. */
  ReverseSegment(string, cp - 1);
}

void reverse_words1(const char input[], char output[])
{
  const char *cp1, *cp2, *cp3;

  cp1 = input;
  while (*cp1)
  {
    cp1++;
  }
  cp1--;

  while (cp1 >= input)
  {
      /* Add whitespace to output (if any). */
    while (cp1 >= input && IsWhitespace(*cp1))
    {
      *output = *cp1;
      output++;
      cp1--;
    }
    cp2 = cp1;

      /* If a word has been found, find its origin and mark it. */
    while (cp1 >= input && !IsWhitespace(*cp1))
    {
      cp1--;
    }
    cp3 = cp1;

      /* Add the word to the output string. */
    while (cp1 < cp2)
    {
      cp1++;
      *output = *cp1;
      output++;
    }
    cp1 = cp3;
  }
  cp1++;

    /* Null-terminate the string. */
  *output = '\0';
}

void reverse_words2(char string[])
{
  char *cp;
  ReverseString(string);

  while (*string)
  {
      /* Skip over whitespace (if any). */
    while (IsWhitespace(*string))
    {
      string++;
    }
      /* If null was reached, exit. */
    if (!*string)
    {
      return;
    }
      /* Mark the beginning of the word. */
    cp = string;
    while (*string && !IsWhitespace(*string))
    {
      string++;
    }
      /* Pointer "string" now points just past the word. Reverse the word. */
    ReverseSegment(cp, string - 1);
  }
}
