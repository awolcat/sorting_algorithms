#include "sort.h"

/**
 * insertion_sort_list - does insertion sort on doubly linked list
 * @list: the list to sort
 *
 * Return:  void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	listint_t *prev;
	listint_t *temp2;
	listint_t *current;
	listint_t *count;
	int len = 0;

	if (!list || !*list)
		return;
	count = *list;
	while (count)
	{
		len += 1;
		count = count->next;
	}

	if (*list && len >= 2)
	{
		temp = (*list)->next;

		while (temp)
		{
			temp2 = temp->prev;
			while (temp2)
			{
				if (temp->n < temp2->n)
				{
					current = temp;
					prev = temp2;
					swap(list, current, prev, &len);
					print_list(*list);
				}
				temp2 = temp2->prev;
			}
			temp = temp->next;
		}
	}
}
/**
 * swap - insert src immediately before dest
 * @head: head of the linked list
 * @src: node to insert
 * @dest: src will be inserted just before dest node
 * @len: length of the list
 *
 * Return: void
 */
void swap(listint_t **head, listint_t *src, listint_t *dest, int *len)
{
	if (*len == 2)
	{
		src->next = dest;
		src->prev = NULL;
		dest->next = NULL;
		dest->prev = src;
		(*head) = src;
	}
	else if (dest->prev == NULL)
	{
		(src->prev)->next = src->next;
		(src->next)->prev = src->prev;
		src->next = dest;
		src->prev = NULL;
		dest->prev = src;
		(*head) = src;
	}
	else if (src->next == NULL)
	{
		(src->prev)->next = NULL;
		src->next = dest;
		src->prev = dest->prev;
		(dest->prev)->next = src;
		dest->prev = src;
	}
	else
	{
		(src->prev)->next = src->next;
		(src->next)->prev = src->prev;
		src->next = dest;
		src->prev = dest->prev;
		(dest->prev)->next = src;
		dest->prev = src;
	}
}
