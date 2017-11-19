# eratosthenes vs sundaram

def eratosthenes(n):
  a = [True]*(n+1)
  res = []
  for i in range(2, n+1):
    if not a[i]: continue
    for j in range(i*i, n+1, i):
      a[j] = False
    res.append(i)
  return res

def sundaram(n):
  n = n-1 >> 1
  a = [True]*(n+1)
  i, j = 1, 1
  done = False
  t = i + j + 2*i*j
  while t <= n:
    while t <= n:
      a[t] = False
      j += 1
      t = i + j + 2*i*j
    i += 1
    j = i
    t = i + j + 2*i*j

  res = [2]
  for i in range(1, n+1):
    if a[i]: res.append((i<<1) + 1)
  return res


from time import time
N = 1000000

a1 = time()
eratosthenes(N)
print('eratosthenes:', time()-a1)

b1 = time()
sundaram(N)
print('sundaram:', time()-b1)
