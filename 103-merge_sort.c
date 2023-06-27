#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort - merge sort on an array
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *leftArr, *rightArr;
	size_t i, l = 0, r = 0;
	size_t middle = size / 2;

	if (size < 2)
		return;
	leftArr = malloc(sizeof(array[0]) * middle);
	rightArr = malloc(sizeof(array[0]) * (size - middle));
	for (i = 0; i < size; i++)
	{
		if (i < middle)
		{
			leftArr[l] = array[i];
			l++;
		}
		else
		{
			rightArr[r] = array[i];
			r++;
		}
	}
	merge_sort(leftArr, middle);
	merge_sort(rightArr, size - middle);
	merge(leftArr, rightArr, array);
	printf("Merging...\n[left]: ");
	print_array(leftArr, middle);
	printf("[right]: ");
	print_array(rightArr, size - middle);
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge - morge sorted arrays
 * @left: the left part of the array
 * @right: right part of the array
 * @array: the original array
 *
 * Return: void
 */
void merge(int *left, int *right, int *array)
{
	size_t l, r, i;
	size_t lenl, lenr;

	for (lenl = 0; left[lenl]; lenl++)
		;
	for (lenr = 0; right[lenr]; lenr++)
		;
	l = 0;
	r = 0;
	i = 0;
	while (l < lenl && r < lenr)
	{
		if (left[l] < right[r])
		{
			array[i] = left[l];
			l++;
			i++;
		}
		else
		{
			array[i] = right[r];
			r++;
			i++;
		}
	}
	while (l < lenl)
	{
		array[i] = left[l];
		l++;
		i++;
	}
	while (r < lenr)
	{
		array[i] = right[r];
		r++;
		i++;
	}
}
