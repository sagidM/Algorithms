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

// l - left array's size
// r - right array's size
template <typename type>
void merge(type* const a, const size_t &l, const size_t &r, type* const res)
{
	size_t il = 0, ir = l, k = 0;
	while (il < l || ir < r)
	{
		if (il == l)
		{
			for (size_t i = ir; i < r; i++)
				res[k++] = a[i];
			break;
		}
		if (ir == r)
		{
			for (size_t i = il; i < l; i++)
				res[k++] = a[i];
			break;
		}
		res[k++] = a[il] < a[ir] ? a[il++] : a[ir++];
	}
}

template <typename type>
void _merge_sort(type* const a, const size_t &size, type* const res)
{
	if (size <= 1) return;

	size_t m = size / 2;
	_merge_sort(a, m, res);
	_merge_sort(a + m, size-m, res);

	merge(a, m, size, res);
	for (size_t i = 0; i < size; i++)
		a[i] = res[i];
}

template <typename type>
void merge_sort(type* const a, const size_t &size)
{
	type* tmp = new type[size];
	_merge_sort(a, size, tmp);
	delete[] tmp;
}

void main()
{
	int* a = new int[7] {4, 1, 5, 3, 7, 11, 10};
	merge_sort<int>(a, 7);
	print(" ", a, 7);
	delete[] a;
	getchar();
}
