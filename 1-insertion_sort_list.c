#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @left: The left node
 * @right: The right node (right = left->next)
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;

	right->next = left;
	left->prev = right;

	print_list(*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending
 * order with insertion sort.
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		prev = current->prev;

		while (prev && current->n < prev->n)
		{
			swap_nodes(list, prev, current);
			prev = current->prev;
		}
		current = current->next;
	}
}
