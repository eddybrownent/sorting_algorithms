#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a listint_t doubly linked list
 * @list : this is a ponter to head of the list
 * @node_1: pointer to the first node to swap
 * @node_2: pointer to the second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node_1, listint_t *node_2)
{
	if (node_1->prev != NULL)
		node_1->prev->next = node_2;
	else
		*list = node_2;

	if (node_2->next != NULL)
		node_2->next->prev = node_1;

	node_1->next = node_2->next;
	node_2->prev = node_1->prev;
	node_2->next = node_1;
	node_1->prev = node_2;
}

/**
 * insertion_sort_list - sorts a doubly linked list
 *			using the insertion sort algorithm
 * @list: pointer to the haed of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *previous, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		previous = current->prev;

		while (previous != NULL && current->n < previous->n)
		{
			swap_nodes(list, previous, current);
			print_list((const listint_t *)*list);
			previous = current->prev;
		}
	current = current->next;
	}
}
