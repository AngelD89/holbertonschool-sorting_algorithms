#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	if (a != b)
	{
		int tmp = *a;

		*a = *b;
		*b = tmp;
	}
}

/**
 * lomuto_partition - Lomuto Partiting scheme
 * @array: The array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of full array (for printing)
 * Return: final pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(&array[i], &array[j]);
			if (i != j)
			    print_array(array, size);
			i++;
		}
	}

	if (i != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort - Recursive quick sort
 * @array: The array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Total size of the array(for printing)
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int p = lomuto_partition(array, low, high, size);

		quicksort(array, low, p - 1, size);
		quicksort(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Entry point for Quick Sort
 * @array: The array to sort
 * @size: Number of elements in array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
