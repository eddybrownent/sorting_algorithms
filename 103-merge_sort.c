#include "sort.h"
/**
 * merge - merge two subarrats into sorted array
 * @array: the array having integers
 * @left: the left subarray
 * @left_size: the size of the left subarray
 * @right: the right subarray
 * @right_size: size of the right subarray
 *
 */
void merge(int *array, int *left, size_t left_size, int *right,
		size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, left_size + right_size);
	printf("\n");

}

/**
 * merge_sort - sorts an array of ints using merge sort
 * @array: the array containg the integers
 * @size: thes size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	size_t mid = size / 2;
	size_t left_size = mid;
	size_t right_size = size - mid;
	int *temp = malloc(size * sizeof(int));

	if (array == NULL || size < 2)
		return;

	if (temp == NULL)
		return;

	if (size < 2)
		return;

	merge_sort(array, left_size);
	merge_sort(array + mid, right_size);
	merge(temp, array, left_size, array + mid, right_size);

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	free(temp);
}
