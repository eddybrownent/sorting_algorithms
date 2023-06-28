#include "sort.h"
/**
 * swap - swaps two integers in an array
 * @i: the first integer
 * @j: the second integer
 */
void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * merge_bitonic - Merges two subarrays in a bitonic sequence
 * @array: the array of integers
 * @size: the size of the array
 * @start: the starting index of the first subarray
 * @size_seq: the size of the subarray
 * @dir: the direction to sort
 */
void merge_bitonic(int *array, size_t size, size_t start, size_t size_seq,
		char dir)
{
	size_t i, mid;

	mid = size_seq / 2;
	if (size_seq > 1)
	{

		for (i = start; i < start + mid; i++)
		{
			if ((dir == 1 && array[i] > array[i + mid]) ||
					(dir == 0 && array[i] < array[i + mid]))
				swap(array + i, array + i + mid);
		}

		merge_bitonic(array, size, start, mid, dir);
		merge_bitonic(array, size, start + mid, mid, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursive function to do Bitonic sort
 * @array: the array having the integers
 * @size: the size of the array
 * @start: starting index of the array
 * @size_seq: the size of the subarray
 * @dir: the direction to sort
 */
void bitonic_sort_recursive(int *array, size_t size, size_t start,
		size_t size_seq, char dir)
{
	size_t mid;
	char *order = (dir == 1) ? "UP" : "DOWN";

	mid = size_seq / 2;
	if (size_seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", size_seq, size, order);
		print_array(array + start, size_seq);

		bitonic_sort_recursive(array, size, start, mid, 1);
		bitonic_sort_recursive(array, size, start + mid, mid, 0);
		merge_bitonic(array, size, start, size_seq, dir);

		printf("Result [%lu/%lu] (%s):\n", size_seq, size, order);
		print_array(array + start, size_seq);

	}
}

/**
 * bitonic_sort - sorts an array of integers using Bitonic sort
 * @array: the array of integers
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, size, 0, size, 1);
}
