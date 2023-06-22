#include "sort.h"
#include <stdlib.h>

/**
 * bubble_sort - bubble sort an integer array in ascending order
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swap = 0;
	int temp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swap += 1;
			}
		}
		if (swap == 0)
			break;
	}
}
