#include "sort.h"
/**
 * swap - swaps two integers
 * @a: pints to the first integer
 * @b: points to the second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - moves the element down the heap to its
 *		correct position
 * @array: the array having integers
 * @size: size of the array
 * @index: index of the element to sift down
 * @heap_size: size of the heap
 */
void sift_down(int *array, size_t size, size_t index, size_t heap_size)
{
	size_t max = index;
	size_t left_child = 2 * index + 1;
	size_t right_child = 2 * index + 2;

	if (left_child < heap_size && array[left_child] > array[max])
		max = left_child;

	if (right_child < heap_size && array[right_child] > array[max])
		max = right_child;

	if (max != index)
	{
		swap(&array[index], &array[max]);
		print_array(array, size);
		sift_down(array, size, max, heap_size);
	}
}

/**
 * heap_sort - sorts an array of integers using the heap sort
 * @array: the array having integers
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	/* Build max heap */
	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	/* Heap sort */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}
