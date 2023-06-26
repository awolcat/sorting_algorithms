#include "sort.h"

/**
 * quick_sort - sort an array
 * @array: the array
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{

	if (array == NULL || size <= 1)
		return;
	quick_sort_r(array, 0, size - 1, &size);
}

/**
 * quick_sort_r -  divide and sort an array
 * @array: the array
 * @lb: lower bound of the array
 * @ub: upper bound of array
 * @len: pointer to size of the original array
 *
 * Return: void
 */
void quick_sort_r(int *array, int lb, int ub, size_t *len)
{
	size_t pivot;

	if (lb < ub)
	{
		pivot = partition(array, lb, ub, len);
		quick_sort_r(array, lb, pivot - 1, len);
		quick_sort_r(array, pivot + 1, ub, len);
	}
}

/**
 * partition - partition array besed on a pivot point
 * @arr: the array. May be original or a portion of the original
 * @lb: lower bound of the array
 * @ub: upper bound of the array
 * @len: pointer to  size of the original array
 *
 * Return: index of the pivot
 */

size_t partition(int *arr, size_t lb, size_t ub, size_t *len)
{
	int pivot = arr[ub];
	size_t trailer = lb - 1;
	size_t start;

	for (start = lb; start < ub; start++)
	{
		if (arr[start] < pivot)
		{
			trailer += 1;
			swap_arr(&arr[start], &arr[trailer]);
			if ((ub == *len - 1) && (arr[trailer] < arr[start]))
				print_array(arr, ub + 1);
		}
	}
	swap_arr(&arr[ub], &arr[trailer + 1]);
	if (ub == *len - 1)
		print_array(arr, ub + 1);
	return (trailer + 1);
}
/**
 * swap_arr - swap two elements of an array
 * @arr_1: pointer to first element
 * @arr_2: pointer to second element
 *
 * Return: void
 */
void swap_arr(int *arr_1, int *arr_2)
{
	int temp = *arr_2;

	*arr_2 = *arr_1;
	*arr_1 = temp;
}
