#include <string.h>

void remove_newline(char *input)
{
  if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n'))
    input[strlen(input) - 1] = '\0';
}