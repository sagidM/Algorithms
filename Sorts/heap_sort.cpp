#include <stdio.h>
#include <iostream>

// array[sheet_index] is the last sheet, which must be moving
// sheet_index < size
template <typename type>
void sift_up(type* const array, size_t sheet_index)
{
	// is not root
	while (sheet_index != 0)
	{
		// sheet_index % 2 == 0 than sheet_index = right; otherwise sheet_index = left
		size_t parent_index = (sheet_index - (sheet_index % 2 == 0 ? 2 : 1)) / 2;

		if (array[sheet_index] > array[parent_index])
		{
			std::swap(array[sheet_index], array[parent_index]);
			sheet_index = parent_index;
		}
		else
		{
			break;
		}
	}
}

template <typename type>
void sift_down(type* const array, const size_t &size, size_t sieving_index = 0)
{
	// left, right and max_of_sheets are indexes (not values)

	while (sieving_index <= size)
	{
		size_t left = sieving_index * 2 + 1;

//		printf("left: %i, size: %i\n", left, size);
		// it has no sheets, it's a sheet
		if (left >= size) return;

		size_t right = left + 1;

		// it has only a left sheet (right is out of range)
		if (right >= size)
		{
			std::swap(array[sieving_index], array[left]);
			return;
		}

		size_t &max_of_sheets = array[left] > array[right] ? left : right;
//		printf("[%i]\n", max_of_sheets);
		if (array[sieving_index] < array[max_of_sheets])
		{
			std::swap(array[max_of_sheets], array[sieving_index]);
			sieving_index = max_of_sheets;
		}
		else
			return;
	}
}

template <typename type>
void heap_sort(type* const array, const size_t& size)
{
	for (size_t i = 1; i < size; i++)
		sift_up(array, i);

	for (size_t i = 1; i < size; i++)
	{
		std::swap(array[0], array[size-i]);
		sift_down(array, size - i, 0);
	}
}

void print(char* sep, const int* const array, const size_t &size)
{
	if (size >= 1)
		printf("%i", array[0]);
	for (size_t i = 1; i < size; i++)
	{
		printf("%s%i", sep, array[i]);
	}
	printf("\n");
}

void main()
{
	// sheets: 2*i + 1, 2*i + 2
	const size_t n = 10;
	int *a = new int[n];

	a[0] = 15;
	a[1] = 152;
	a[2] = 1;
	a[3] = 77;
	a[4] = 91;
	a[5] = 45;
	a[6] = 100;
	a[7] = 12;
	a[8] = 67;
	a[9] = 19;

	print(", ", a, n);
	heap_sort(a, n);
	print(", ", a, n);
	delete a;

	getchar();
}
