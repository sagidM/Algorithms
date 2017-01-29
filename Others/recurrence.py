'''
Recurrence
Common folmula:
f(n) = SUM[i = 1..k] f(n-i)

For example:
if k = 3,
f(n) = f(n-1) + f(n-2) + f(n-3)
'''

class Box:
  def __init__(self, s, i): self.s, self.i = s, i
  def __str__(self):
    return "%s  [%i]=%i" % (self.s, self.i, self.s[self.i])


def recurrent_sequence1(n, k):
  '''Speed, Memory: O(k*n), O(n)'''
  a = [0] * n
  a[0] = 1
  for i in range(1, n):
    s = 0
    for j in range(max(i-k, 0), i):
      s += a[j]
    a[i] = s
  return Box(a, i)

def recurrent_sequence2(n, k):
  '''Speed, Memory: O(2*n), O(n)'''
  a = [0] * n
  a[0] = 1
  a[1] = 1
  for i in range(2, n):
    s = 0
    if i-k > 0:
      s = a[i-1] << 1
      s -= a[i-k-1]
    else:
      s = a[i-1] << 1
    a[i] = s
  return Box(a, i)

def recurrent_sequence3(n, k):
  '''Speed, Memory: O(2*n), O(k+1)'''
  a = [0] * (k+1)
  a[0] = 1
  a[1] = 1
  for i in range(2, n):
    s = 0
    if i-k > 0:
      s = a[(i-1) % (k+1)] << 1
      s -= a[i % (k+1)]
    else:
      s = a[i-1] << 1
    a[i % (k+1)] = s
  return Box(a, i%(k+1))


# f(10) = f(10-1), f(10-2) =
# f(10) = f(9) + f(8)
n, k = 10, 2
print(recurrent_sequence1(n, k))
print(recurrent_sequence2(n, k))
print(recurrent_sequence3(n, k))
