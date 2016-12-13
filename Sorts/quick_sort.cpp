#include <stdio.h>
#include <iostream>

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

template <typename type>
void quick_sort(type* const a, const size_t &b0, const size_t &e0)
{
	size_t b = b0, e = e0;
	type pivot = a[(e0 - b0) / 2 + b0];

	while (b <= e)
	{
		while (a[b] < pivot) ++b;
		while (a[e] > pivot) --e;

		if (b <= e)
		{
			if (b != e) std::swap(a[b], a[e]);
			++b;
			--e;
		}
	}

	if (e > b0)
		quick_sort(a, b0, e);
	if (e0 > b)
		quick_sort(a, b, e0);
}

template <typename type>
void quick_sort(type* const a, const size_t &size)
{
	quick_sort(a, 0, size - 1);
}

void main()
{
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

	quick_sort(a, n);
	print(", ", a, n);

	delete[] a;

	getchar();
}
