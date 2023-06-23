#include "sort.h"
/**
 * selection_sort - this function sorts an array of integers
 *			using selction sort algorithm
 * @array: points to the array of integers
 * @size: the size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	print_array(array, size);
	}
}
