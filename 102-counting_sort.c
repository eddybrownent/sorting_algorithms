#include "sort.h"
/**
 * counting_sort - sorts an array of ints using the counting sort
 *
 * @array: the array having integers
 * @size: the size of the array
 *
 */
void counting_sort(int *array, size_t size)
{
	int max, *count, *temp = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	count = (int *)malloc((max + 1) * sizeof(int));
	if (count == NULL)
	{
		free(temp);
		return;
	}
	for (i = 0; i < ((size_t)max + 1); i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	temp = (int *)malloc(size * sizeof(int));
	if (temp == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		temp[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = temp[i];
	free(count);
	free(temp);
}
