
def sift_up(a, k):
  while k != 0:
    if k % 2 == 0:
      parent = (k-2) // 2
    else:
      parent = (k-1) // 2

    if a[k] > a[parent]:
      a[k], a[parent] = a[parent], a[k]
      k = parent
    else:
      return


def sift_down(a, size, k = 0):
  while True:
    left = k*2 + 1
    if left >= size:     # there're no sheets
      return

    right = left + 1
    if right == size:    # there's only left sheet
      if a[k] < a[left]:
        a[k], a[left] = a[left], a[k]
      return

    great = left if a[left] > a[right] else right
    if a[k] >= a[great]: break
    a[k], a[great] = a[great], a[k]
    k = great

def heap_sort(a):
  size = len(a)
  for i in range(1, size):
    sift_up(a, i)  # build
  for i in range(1, size):
    a[0], a[size-i] = a[size-i], a[0]
    sift_down(a, size-i, 0)

'''
def is_heap_struct(a, size):
  for i in range(size):
    left = 2*i + 1
    right = left + 1
    if left >= size: break
    if a[i] < a[left]: return False
    if right == size: break
    if a[i] < a[right]: return False
  return True
'''
