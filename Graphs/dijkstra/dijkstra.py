
k = 5 # count of vertexes
inp = (
  (1, 2, 1),
  (1, 4, 2),
  (2, 3, 1),
  (3, 5, 3),
  (4, 5, 1),
)
n = len(inp)

INF = 10**9+1

edges = tuple([] for i in range(n+1))
weights = tuple([] for i in range(n+1))

for i in range(1, n+1):
  u, v, w = inp[i-1]
  edges[u].append(v)
  weights[u].append(w)
  # if undirected graph
  #edges[v].append(u)
  #weights[v].append(w)

marks = [INF]*(k+1)
is_marks = [False]*(k+1)

#--------------------

pos = 1
marks[pos] = 0

while pos != -1:
  for i in range(len(edges[pos])):
    assert marks[pos] != INF
    u, v, w = pos, edges[pos][i], weights[pos][i]
    if marks[v] > marks[pos] + w:
       marks[v] = marks[pos] + w

  assert not is_marks[pos]
  is_marks[pos] = True # remove vertex

  # find minimum
  m = INF
  pos = -1
  for i in range(1, k+1):
    if is_marks[i]: continue
    if m > marks[i]:
      m = marks[i]
      pos = i


for i in range(1, len(marks)):
  print("from %i minimum path is %i" % (i, marks[i]))
