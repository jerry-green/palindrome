// gcc is_palindrome_number_3.c -o is_palindrome_number_3_g611 -O3
// Times for 10 000 000 numbers
// Fedora 24, gcc 6.1.1: 0.156 sec

#include <stdio.h>

#define PALINDROME_MAX 1000000

int is_palindrome(unsigned int num)
{
  // if num ends with 0, then is not palindrome
  // num 0 is palindrome
  if ((num % 10) || (num == 0))
  {
    static unsigned int num_prev;
    unsigned int rev = 0;

    // first half of num assigned to num
    // reversed second half of num assigned to rev
    while (num > rev)
    {
      rev = 10 * rev + num % 10;
      num_prev = num;
      num /= 10;
    }

    // if num has even number of digits, then compare rev == num
    // if num has odd number of digits, then compare rev == num_prev
    if ((rev == num) || (rev == num_prev))
      return 1;
  }

  return 0;

}

int main()
{
  unsigned int count = 0;

  for (unsigned int i = 0; i < PALINDROME_MAX; i++)
    if (is_palindrome(i))
      count++;

  printf("Number of palindromes: %d\n", count);

  return 0;

}
