#include <stdio.h>
#include <ios>


template <typename type>
void print(char* sep, const type* const array, const size_t &size)
{
	if (size >= 1)
		printf("%i", array[0]);
	for (size_t i = 1; i < size; i++)
		printf("%s%i", sep, array[i]);
	printf("\n");
}

template <typename type>
void quick_sort(type* const a, const int &size)
{
	if (size <= 1) return;
	const int &last = size - 1;
	int left = 0, right = last;
	type pivot = a[(right - left) / 2 + left];
	while (left <= right)
	{
		while (a[left] < pivot) ++left;
		while (a[right] > pivot) --right;

		if (left <= right)
		{
			if (left != right) std::swap(a[left], a[right]);
			++left;
			--right;
		}
	}

	quick_sort(a, right+1);
	if (last > left) quick_sort(a + left, last - left + 1);
}


void main()
{
	int *a = (int*)malloc(10 * sizeof(int));
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

	quick_sort(a, 10);
	print(", ", a, 10);
	free(a);


	getchar();
}
