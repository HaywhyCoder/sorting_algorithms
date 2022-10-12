#include "sort.h"

/**
 * shell_sort - sorts an array using shell sort algorithm
 *
 * @array: Points to the array to be sorted
 * @size: Size of the array to be sorted
 */
void shell_sort(int *array, size_t size)
{
	int temp, i;
	size_t j, k;

	if (array == NULL || size < 2)
		return;
	k = 1;
	while (k < size / 3)
	{
		k = (k * 3) + 1;
	}

	while (k >= 1)
	{
		for (j = k; j < size; j++)
		{
			for (i = j - k; i >= 0; i = i - k)
			{
				if (array[i + k] > array[i])
					break;
				else
				{
					temp = array[i];
					array[i] = array[i + k];
					array[i + k] = temp;
				}
			}
		}
		k = (k - 1) / 3;
		print_array(array, size);
	}
}
