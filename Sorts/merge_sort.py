
def merge(a, ai, a_last, b, bi, b_last, res, resi):
  '''Merge two array into one.
:params a - array, ai - start index of array a, a_last - end index of that, and the same for array b;
res - array-result, resi - start index of array res

Example:
res = [0]*10
merge([2, 4, 10, 100], 0, 4, [1, 6, 17, 50, 150, 200], 0, 6, res, 0)
print('array res is', res)
'''
  
  while True:
    if ai >= a_last:
      while bi < b_last:
        res[resi] = b[bi]
        bi += 1
        resi += 1
      break
    if bi >= b_last:
      while ai < a_last:
        res[resi] = a[ai]
        ai += 1
        resi += 1
      break

    if a[ai] < b[bi]:
      res[resi] = a[ai]
      ai += 1
    else:
      res[resi] = b[bi]
      bi += 1
    resi += 1

  return res


def merge_sort(a):
  '''Pay attention: this method sorts array in-place, not returns a new!'''
  n = len(a)
  tmp = [0] * n
  step, half = 2, 1
  half_of_len = n//2
  while half <= n:
    for i in range(0, n, step):
      if i + half >= n: break
      m = i + step if i + step < n else n
      merge(a, i, i + half, a, i + half, m, tmp, i)
      a[i:m] = tmp[i:m]
    step <<= 1 # *=2
    half <<= 1

  return a
