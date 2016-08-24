#include <string.h>
#include <stdio.h>

#define PALINDROME_MAX 1000000

int is_palindrome(const char *s)
{
  unsigned int end = strlen(s) - 1;

  for (unsigned int i = 0; i <= end / 2; i++)
    if (s[i] != s[end - i])
      return 0;

  return 1;

}


int main()
{
  char s_number[8];
  unsigned int count = 0;

  for (unsigned int i = 0; i < PALINDROME_MAX; i++)
  {
    sprintf(s_number, "%d", i);
    if (is_palindrome(s_number))
      count++;
  }

  printf("Number of palindromes: %d\n", count);
  return 0;

}

