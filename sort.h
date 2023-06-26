#ifndef SORT_H
#define SORT_H

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

#include <stddef.h>

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* bubble sort */
void bubble_sort(int *array, size_t size);
/* insertion sort */
void insertion_sort_list(listint_t **list);
void swap(listint_t **head, listint_t *src, listint_t *dest, int *len);
/*selection sort */
void selection_sort(int *array, size_t size);
/* quick sort */
void quick_sort(int *array, size_t size);
void quick_sort_r(int *array, int lb, int ub, size_t *len);
size_t partition(int *arr, size_t lb, size_t ub, size_t *len);
void swap_arr(int *arr_1, int *arr_2);
#endif
