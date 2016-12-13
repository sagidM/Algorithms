
class Node(object):
  """docstring for Node"""
  def __init__(self, value, left=None, right=None):
    self.value = value
    self.left = left
    self.right = right

  def __str__(self):
    return "value = %s, None = (%s, %s)" % (self.value, self.left==None, self.right==None)

class LinkedList(object):
  def __init__(self, first_value=None):
    self.first = self.last = None if first_value is None else Node(first_value)

  def add(self, value):
    l = self.last
    self.last = Node(value, self.last)
    if l is None:   # if is empty
      self.first = self.last
    else:
      l.right = self.last

  def remove_node(self, node):
    left, right = node.left, node.right
    if left is not None:
      left.right = right
    elif node is self.first:
      self.first = right

    if right is not None:
      right.left = left
    elif node is self.last:
      self.last = left

  def __iter__(self):
    self.current = self.first
    return self
  def next(self):
    if self.current is None:
      raise StopIteration()
    c = self.current
    self.current = self.current.right
    return c.value

s = LinkedList()
s.add(7)
print(list(s))