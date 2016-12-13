
def selection_sort(a):
  for i in range(len(a)-1):
    least = a[i]
    for j in range(i+1, len(a)):
      if least > a[j]:
        least, a[j] = a[j], least
