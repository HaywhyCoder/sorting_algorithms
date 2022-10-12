#include "sort.h"

int partition(int *array, size_t size, int low, int high)
{
	int i, pi, temp, pivot;

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
		}
	}
	temp = array[high];
	array[high] = array[pi];
	array[pi] = temp;
	print_array(array, size);

	return (pi);
}

void quicksort(int *array, size_t size, int low, int high)
{
	int pi;
	
	if (low >= high || low < 0)
		return;

	pi = partition(array, size, low, high);

	quicksort(array, size, low, pi - 1);
	quicksort(array, size, pi + 1, high);
}

void quick_sort(int *array, size_t size)
{
	quicksort(array, size, 0, size - 1);
}

int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	quick_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
