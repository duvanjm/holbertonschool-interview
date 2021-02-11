#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given integer is a palindrome.
 * @n: is the number to be checked
 * Return: return 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
    int aux = 0, i, aux_2 = n;

	while (n != 0)
	{
		i = n % 10;
		aux = aux * 10 + i;
		n /= 10;
	}
	if (aux_2 == aux)
		return (1);
	else
		return (0);
}
