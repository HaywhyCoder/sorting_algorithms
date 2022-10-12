#include "sort.h"

void counting_sort(int *array, size_t size)
{
	size_t i;
	int max, *count, *output, j;

	if (array == NULL || size < 2)
		return;
	max = 0;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	
	for (j = 0; j <= max; j++)
	{
		count[j] = 0;
	}	
	for (i = 0; i < size; i++)
	{
		count[array[i]] += 1;
	}
	for (j = 1; j <= max; j++)
	{
		count[j] = count[j] + count[j - 1];
	}
	print_array(count, max + 1);
	for (j = size - 1; j >= 0; j--)
	{
		output[--count[array[j]]] = array[j];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(output);
	free(count);
}
