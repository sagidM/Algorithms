
def bubble_sort(a):
  for i in range(0, len(a)):
    swapped = False
    for j in range(1, len(a)-i):
      if a[j-1] > a[j]:
        a[j-1], a[j] = a[j], a[j-1]
        swapped = True
    if swapped is False:
      break

  return a
