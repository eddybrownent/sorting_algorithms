#include "sort.h"
/**
 * shell_sort - sorts aon array of integers using the shell sort
 *
 * @array: the array to be sorted
 * @size: the size of the array to sort
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t interval;
	size_t i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	interval = 1;
	while (interval <= size / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}

}
