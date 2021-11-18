#include "sort.h"

/**
 * swap - Function to swap the the position of two elements
 * @a: element a
 * @b: element b
 * Return: always void
 **/

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * heapify - convert array into a heap
 * @array: array to convert into a heap
 * @size: size of the array
 * @i: largest point
 * @t_size: size of the array
 * Return: Always void
 **/

void heapify(int *array, int size, int i, int t_size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;
	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, t_size);
		heapify(array, size, largest, t_size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array to order
 * @size: size of the array
 * Return: Always void
 **/

void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i > 0; i--)
	{
		if (array[0] >= array[i])
		{
			swap(&array[0], &array[i]);
			print_array(array, size);
		}
		heapify(array, i, 0, size);
	}
}
