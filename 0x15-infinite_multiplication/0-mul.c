#include "holberton.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_result - Prints an array of integers like a unique number
 * @nums3: Array of integers
 * @size: Size of the array of integers
 */

void print_result(int *nums3, int size)
{
	int i = 0;

	if (!nums3 && !size)
	{
		printf("0\n");
		exit(0);
	}
	while (nums3[i] == 0)
		i++;
	for (; i < size; i++)
	{
		printf("%d", nums3[i]);
	}
	printf("\n");
}

/**
 * multiply - Multiplies two numbers
 * @num1: String representation of num1 a large integer
 * @num2: string representation of num2 a large integer
 * Return: 1 on success, 0 on failure
 */

int multiply(char *num1, char *num2)
{
	int i, j;
	int len1, len2, sum, n1, n2 = 0;
	int *nums3;

	len1 = strlen(num1);
	len2 = strlen(num2);
	nums3 = calloc(len1 + len2, sizeof(len1 + len2));
	if (!nums3)
		return (0);
	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = (n1 * n2) + nums3[i + j + 1];
			nums3[i + j] += sum / 10;
			nums3[i + j + 1] = sum % 10;
		}
	}
	print_result(nums3, len1 + len2);
	free(nums3);
	return (1);
}

/**
 * main - Entry point: Multiplies two positive numbers
 * @argc: Number of arguments passed
 * @argv: Arguments passed
 * Return: 0 in success, 1 on failure
 */

int main(int argc, char **argv)
{
	int i, j = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = 1; argv[i]; i++)
	for (j = 0; argv[i][j]; j++)
		if (argv[i][j] < '0' || argv[i][j] > '9')
		{
			printf("Error\n");
			exit(98);
		}
	if (*argv[1] == '0' || *argv[2] == '0')
		print_result(NULL, 0);
	if (!multiply(argv[1], argv[2]))
		return (1);
	return (0);
}