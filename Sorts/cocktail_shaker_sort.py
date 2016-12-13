
def cocktail_shaker_sort(a):
  left, right = 0, len(a)
  while left < right:
    swapped = False
    for i in range(left+1, right):
      if a[i-1] > a[i]:
        a[i-1], a[i] = a[i], a[i-1]
        swapped = True
    if swapped is False:
      break
    right -= 1

    for i in range(right-1, left, -1):
      if a[i-1] > a[i]:
        a[i-1], a[i] = a[i], a[i-1]
        swapped = True
    if swapped is False:
      break
    left += 1
    

  return a
