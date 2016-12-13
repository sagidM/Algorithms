
def __quick_sort(a, lt, gt):
  pivot = a[(gt-lt) // 2 + lt]  # average
  left, right = lt, gt

  while left <= right:
    while a[left] < pivot:
      left += 1
      
    while a[right] > pivot:
      right -= 1

    if left <= right:
      if left < right:
        a[left], a[right] = a[right], a[left]
      left += 1
      right -= 1
  
  if right > lt:
    __quick_sort(a, lt, right)
  if gt > left:
    __quick_sort(a, left, gt)


def quick_sort(a):
  __quick_sort(a, 0, len(a)-1)


