#include "sort.h"

/**
 * insertion_sort_list - sorts a double linked list using insertion sort
 *
 * @list: Pointer to head pointer of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *current_node, *temp, *prev;

	if (list == NULL || *list == NULL)
		return;
	head = (*list)->next;
	while (head != NULL)
	{
		temp = head;
		current_node = head->prev;
		while ((current_node != NULL) && (current_node->n > temp->n))
		{
			prev = current_node->prev;
			if (current_node->next->next == NULL)
			{
				current_node->next = NULL;
			}
			else
			{
				current_node->next->next->prev = current_node;
				current_node->next = current_node->next->next;
			}


			if (current_node->prev != NULL)
				current_node->prev->next = temp;
			current_node->prev = temp;
			temp->prev = prev;
			if (temp->prev == NULL)
				*list = temp;
			temp->next = current_node;

			current_node = prev;
			print_list(*list);
		}
		head = head->next;
	}
}
