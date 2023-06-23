#include "sort.h"

/**
 * selection_sort - sort an array with selection sort algo
 * @array: the array to sort
 * @size: length of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int index, current, least;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		least = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < least)
			{
				least = array[j];
				index = j;
			}
		}
		if (least < array[i])
		{
			current = array[i];
			array[i] = array[index];
			array[index] = current;
			print_array(array, size);
		}

	}
}
