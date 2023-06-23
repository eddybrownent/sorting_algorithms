#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);
int partitioner(int *array, size_t size, int low, int high);
void sorter(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);

/**
 * swap - swaps two integers
 * @x: the first integer
 * @y: the second integer
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}


/**
 * partitioner - this function follows the Lomunto
 *		partition scheme
 * @array: the array of integers to sort
 * @low: index of the first integer
 * @high: index of the last integer
 * @size: size of the array
 *
 * Return: the position of the pivot in the rearranged array
 */
int partitioner(int *array, size_t size, int low, int high)
{
	int *pivot, i, j;

	pivot = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}


/**
 * sorter - partitions the array and sorts the array
 * @array: the array to be sorted
 * @size: size of trhe array
 * @low: index of the first element
 * @high: index of the first element
 */
void sorter(int *array, size_t size, int low, int high)
{
	int half;

	if (high - low > 0)
	{
		half = partitioner(array, size, low, high);
		sorter(array, size, low, half - 1);
		sorter(array, size, half + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers using quick sort
 * @array: the array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sorter(array, size, 0, size - 1);
}
