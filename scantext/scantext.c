/*******************************************************************************
   Filename: scantext.c

     Author: David C. Drake (https://davidcdrake.com)

Description: Contains six functions: "is_whitespace", "mystrlen",
             "calculate_lengths", "count_words", count_tabs", and
             "substitute_char". All are string-related except "is_whitespace",
             which takes a single character as its parameter. The first two
             functions ("is_whitespace" and "mystrlen") are static.
*******************************************************************************/

/*******************************************************************************
   Function: is_whitespace

Description: Determines whether a given character is a whitespace character
             (space, tab, new line, or carriage return).

     Inputs: c - The character of interest.

    Outputs: Returns "true" if the argument is a whitespace character.
*******************************************************************************/
static int is_whitespace(const char c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

/*******************************************************************************
   Function: mystrlen

Description: Returns the length of a given NULL-terminated string (i.e., the
             number of characters in the string excluding the NULL-terminator).
             Returns -1 if the string's length is too large for a signed int
             variable.

     Inputs: string - Pointer to the string of interest.

    Outputs: The number of characters in the string.
*******************************************************************************/
static int mystrlen(const char *string) {
  int length = 0;

  while (*string++) {
    length++;
  }

  return length;
}

/*******************************************************************************
   Function: calculate_lengths

Description: Calculates a string's actual length (the number of characters in
             the string) as well as its "display length" or "printing length,"
             which accounts for substitution of spaces for tabs according to a
             designated tab size.

     Inputs: string         - Pointer to the string of interest.
             tabsize        - Number of spaces each tab will (presumably) be
                              converted to if printed to the screen.
             string_length  - Pointer to an integer that will be assigned the
                              string's actual length (no. of characters).
             display_length - Pointer to an integer that will be assigned the
                              string's display length (substituting spaces for
                              tabs).

    Outputs: None, but two out parameters are modified.
*******************************************************************************/
void calculate_lengths(const char *string,
                       int tabsize,
                       int *string_length,
                       int *display_length) {
  *string_length = 0;
  *display_length = 0;
  while (*string) {
    *string_length++;
    if (*string++ == '\t') {
      *display_length += tabsize;
    } else {
      *display_length++;
    }
  }
}

/*******************************************************************************
   Function: count_words

Description: Counts the number of words in a given string (where a word is
             defined as a continuous sequence of one or more non-whitespace
             characters).

     Inputs: string - Pointer to the string of interest.

    Outputs: The number of words found in the string.
*******************************************************************************/
int count_words(const char *string) {
  int words = 0;

  while (*string) {
    while (is_whitespace(*string)) {
      string++;
    }
    if (*string) {
      words++;
    }
    do {
      if (!*string) {
        return words;
      }
    }while !is_whitespace(*string++);
  }

  return words;
}

/*******************************************************************************
   Function: count_tabs

Description: Counts the number of tab characters in a string.

     Inputs: string - Pointer to the string of interest.

    Outputs: The number of tabs found in the string.
*******************************************************************************/
int count_tabs(const char *string) {
  int tabs = 0;

  while (*string) {
    if (*string++ == '\t') {
      tabs++;
    }
  }

  return tabs;
}

/*******************************************************************************
   Function: substitute_char

Description: Replaces all instances of one character with another in a given
             string.

     Inputs: string   - Pointer to the string to be modified.
             old_char - Character to be replaced.
             new_char - Character to replace each instance of "old_char".

    Outputs: The number of substitutions made.
*******************************************************************************/
int substitute_char(char *string, char old_char, char new_char) {
  int substitutions = 0;

  while (*string) {
    if (*string == old_char) {
      *string = new_char;
      substitutions++;
    }
    string++;
  }

  return substitutions;
}
