#include "sort.h"

void swap(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *next;

	next = (b)->next;
	if ((b)->next != NULL)
		(b)->next->prev = (a);
	(b)->next = (a);
	(b)->prev = (a)->prev;
	if ((b)->prev == NULL)
		*list = (b);

	if ((a)->prev != NULL)
		(a)->prev->next = (b);
	(a)->next = next;
	(a)->prev = (b);
}

void cocktail_sort_list(listint_t **list)
{
	int sorted;
	listint_t *head, *next_node, *prev;

	head = *list;
	sorted = 1;
	while (sorted == 1)
	{
		do
		{
			sorted = 0;
			next_node = head->next;
			if (head->n > next_node->n)
			{
				swap(list, head, next_node);
				sorted = 1;
				print_list(*list);
			}
			head = head->next;
		} while (head->next != NULL);

		if (sorted == 0)
			break;

		sorted = 0;
		head = head->prev;
		do
		{
			prev = head->prev;
			if(head->n < prev->n)
			{
				swap(list, prev, head);
				sorted = 1;
				print_list(*list);
			}
			head = head->prev;
		} while (head);
		
	}
}

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	cocktail_sort_list(&list);
	printf("\n");
	print_list(list);
	return (0);
}
