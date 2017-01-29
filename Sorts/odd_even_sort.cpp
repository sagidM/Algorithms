#include <iostream>

template <typename type>
void odd_even_sort(type* const a, size_t size)
{
	bool is_sorted;
	do
	{
		is_sorted = true;
		for (int i = 0; i < size-1; i+=2)
		{
			if (a[i] > a[i+1])
			{
				std::swap(a[i], a[i+1]);
				is_sorted = false;
			}
		}
		for (int i = 1; i < size-1; i+=2)
		{
			if (a[i] > a[i+1])
			{
				std::swap(a[i], a[i+1]);
				is_sorted = false;
			}
		}
	} while (!is_sorted);
}

int main()
{
	int a[] = {4, 1, 30, 0, 100};
	odd_even_sort(a, 5);
	for (int i = 0; i < 5; i++)
		std::cout << a[i] << "\n";
}