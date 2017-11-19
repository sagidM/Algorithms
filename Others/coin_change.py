# largest denomination of coin

n = 17
s = sorted([1, 5, 10, 25, 50])
cache = [dict() for i in s]

def f(s, n):
  if n in cache[len(s)-1]: return cache[len(s)-1][n]

  if len(s) == 0: return 0
  if len(s) == 1 and n % s[0] == 0: return 1
  if n == 0: return 1
  if n < 0: return 0

  n0 = n-s[-1] # s[-1] == max(s)
  f1 = f(s, n0)
  f2 = f(s[:-1], n)
  cache[len(s)-1][n0] = f1
  cache[len(s)-2][n] = f2
  return f1 + f2

res = f(s, n)
print(res)
