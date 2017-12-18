def build(a, l, r, tree, i):
  if l == r:
    assert tree[i] == 0
    tree[i] = a[l]
    return tree

  m = (r-l)//2 + l
  build(a, l, m, tree, 2*i+1)
  build(a, m+1, r, tree, 2*i+2)
  assert tree[i] == 0
  tree[i] = tree[2*i+1] + tree[2*i+2]
  return tree


a = [1, 20, 300, 4000]
tree = [0]*(len(a)*4)
build(a, 0, len(a)-1, tree, 0)
print(tree)
