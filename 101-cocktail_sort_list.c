#include "sort.h"
/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the pointer to the head  of the list
 * @node_1: the first node to swap
 * @node_2: the second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node_1, listint_t *node_2)
{
	if (node_1->prev)
		node_1->prev->next = node_2;
	if (node_2->next)
		node_2->next->prev = node_1;

	node_1->next = node_2->next;
	node_2->prev = node_1->prev;
	node_1->prev = node_2;
	node_2->next = node_1;

	if (node_2->prev == NULL)
		*list = node_2;
}

/**
 * cocktail_sort_list - sorts doubly linked list using cocktail shaker sort
 * @list: pointer to the pointer head of the list
 *
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;
	listint_t *left = NULL;
	listint_t *right = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		current = *list;

		while (current->next != right)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}

		right = current;

		if (swapped == 0)
			break;

		swapped = 0;
		current = right;

		while (current->prev != left)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}

		left = current;
	} while (swapped);
}
