#include "sort.h"

/**
 * swap - swaps two integers
 * @x: the first integer
 * @y: the second integer
 *
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
 *
 */
int partitioner(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				i++;
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * sorter - partitions the array and sorts the array
 * @array: the array to be sorted
 * @size: size of trhe array
 * @low: index of the first element
 * @high: index of the first element
 *
 */
void sorter(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partitioner(array, low, high, size);

		sorter(array, low, pivot - 1, size);
		sorter(array, pivot + 1, high, size);
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

	sorter(array, 0, size - 1, size);
}
