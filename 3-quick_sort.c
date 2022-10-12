#include "sort.h"

/**
 * partition - finds the pivot index of an array
 *
 * @array: Array to be partitioned
 * @size: size of the array
 * @low: lower bound of the array
 * @high: upper bound of the array
 *
 * Return: position index
 */
int partition(int *array, size_t size, int low, int high)
{
	int temp, i, pi, pivot;

	pivot = array[high];
	pi = low;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[pi];
			array[pi] = array[i];
			array[i] = temp;
			pi++;
			print_array(array, size);
		}
	}
	temp = array[high];
	array[high] = array[pi];
	array[pi] = temp;

	return (pi);
}

/**
 * quicksort - sorts an array using quicksort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 * @low: lower bound of the array
 * @high: upper bound of the array
 */
void quicksort(int *array, size_t size, int low, int high)
{
	int pi;

	if (low >= high || low < 0)
		return;

	pi = partition(array, size, low, high);

	quicksort(array, size, low, pi - 1);
	quicksort(array, size, pi + 1, high);
}

/**
 * quick_sort - sorts an array using quicksort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
}
