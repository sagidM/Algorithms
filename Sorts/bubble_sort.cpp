#include <iostream>

template <typename type>
void bubble_sort(type* const a, const size_t &size)
{
  for (int i = 1; i < size; ++i)
  {
    for (int j = 0; j < size-i; ++j)
    {
      if (a[j] > a[j+1])
        std::swap(a[j], a[j+1]);
    }
  }
}

int main()
{
  int* a = new int[5];
  a[0] = 4;
  a[1] = 7;
  a[2] = 2;
  a[3] = 6;
  a[4] = 1;
  bubble_sort(a, 5);

  for (int i = 0; i < 5; ++i)
    std::cout << a[i] << " ";
  std::cout << std::endl;
  delete a;
}