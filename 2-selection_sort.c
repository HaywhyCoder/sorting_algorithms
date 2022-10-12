#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort algorithm
 *
 * @array: Points to the array to be sorted
 * @size: Size of the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	int i, min, j, temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
