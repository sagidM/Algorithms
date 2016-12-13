#include <stdio.h>
#include <ios>
#include <cassert>
#include <ctime>


template <typename array_type, typename size_type = size_t>
void test_array(const array_type* const a, const size_type &size)
{
	for (size_type i = 1; i < size; ++i)
		if (a[i - 1] > a[i]) assert(false);
}

template <typename array_type, typename size_type = size_t>
void test_all(void (*sort)(array_type*, const size_type&))
{
	srand(unsigned(time(nullptr)));
	array_type *a0 = (array_type*)malloc(10 * sizeof(array_type));
	a0[0] = 15;
	a0[1] = 152;
	a0[2] = 1;
	a0[3] = 77;
	a0[4] = 91;
	a0[5] = 45;
	a0[6] = 100;
	a0[7] = 12;
	a0[8] = 67;
	a0[9] = 19;
	sort(a0, 10);
	test_array(a0, 10);
	printf("Custom test success\n");
	free(a0);


	const size_type n = 1000000;
	array_type* a = (array_type*)malloc(n * sizeof(array_type));


	for (size_type i = 0; i < n; ++i) a[i] = rand();
	sort(a, n);
	test_array(a, n);
	printf("Random values\n");


	for (size_type i = 0; i < n; ++i) a[i] = i;
	sort(a, n);
	test_array(a, n);
	printf("Sorted array\n");


	for (size_type i = 0; i < n; ++i) a[i] = n-i;
	sort(a, n);
	test_array(a, n);
	printf("Reversed array\n");


	free(a);
	printf("All tests were success\n");
}


template <typename type>
void sort(type* const a, const size_t &size)
{
	// implement
}

void main()
{
	test_all(&sort<int>);
	getchar();
}
