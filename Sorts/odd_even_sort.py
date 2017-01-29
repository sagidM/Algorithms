
def odd_even_sort(a):
  while True:
    is_sorted = True
    for i in range(0, len(a)-1, 2):
      if a[i] > a[i+1]:
        a[i], a[i+1] = a[i+1], a[i]
        is_sorted = False
    for i in range(1, len(a)-1, 2):
      if a[i] > a[i+1]:
        a[i], a[i+1] = a[i+1], a[i]
        is_sorted = False
    if is_sorted: break

if __name__ == '__main__':
  a = [5, 1, 2, 3, 10]
  odd_even_sort(a)
  print(a)
