#include "sort.h"

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void print_elements(int *list);

/**
 * print_array - Print an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}

/*void print_elements(int *list)
{
	size_t i, size;

	i = 0;
	size = sizeof(list) / sizeof(int *);
	while (list && i < size)
	{
		if (i == size - 1)
		{
			printf("%d\n", list[i]);
			break;
		}
		printf("%d, ", list[i]);
		++i;
	}
}
*/
