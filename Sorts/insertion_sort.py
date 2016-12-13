
def insertion_sort(a):
  for i in range(1, len(a)):
    if a[i-1] > a[i]:
      for j in range(i, 0, -1):
        if a[j-1] > a[j]:
          a[j-1], a[j] = a[j], a[j-1]
