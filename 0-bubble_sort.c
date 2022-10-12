#include "sort.h"

/**
 * bubble_sort - sorts an array using bubble sort algorithm
 *
 * @array: Points to the array to be sorted
 * @size: Size of the array to be sorted
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, flag;
	int tmp;

	for (i = 0; i < (size - 1); i++)
	{
		flag = 0;
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j +1];
				array[j + 1] = tmp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
