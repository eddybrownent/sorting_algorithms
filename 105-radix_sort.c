#include "sort.h"
/**
 * get_max - Returns the maximum value in an array
 * @array: the array of integers
 * @size: size of the array
 * Return: Maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radix_counting_sort - does counting sort based on the digit
 *			at a given place
 * @array: the array of integers
 * @size: size of the array
 * @place: current significant digit place
 */
void radix_counting_sort(int *array, size_t size, int place)
{
	const int radix = 10;
	int *count = malloc(sizeof(int) * radix);
	int *output = malloc(sizeof(int) * size);
	size_t i;

	if (count == NULL || output == NULL)
	{
		free(count);
		free(output);
		return;
	}

	for (i = 0; (int)i < radix; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / place) % radix]++;

	for (i = 1; (int)i < radix; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / place) % radix] - 1] = array[i];
		count[(array[i] / place) % radix]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}

/**
 * radix_sort - sorts an array of integers using Radix sort
 * @array: the array of integers
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, place;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (place = 1; max / place > 0; place *= 10)
	{
		radix_counting_sort(array, size, place);
		print_array(array, size);
	}
}
