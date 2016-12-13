from random import randint
from time import time


while True:
  module = input('Module = ')
  if len(module) != 0: break
  
while True:
  function = input('Function = ')
  if len(function) != 0: break

sorting_function = getattr(__import__(module), function)


def test_array(a):
  global sorting_function
  before = time()
  copy = a.copy()
  sorting_function(a)
  after = time()
  # check if "a" is sorted
  for i in range(1, len(a)):
    if a[i-1] > a[i]:
      print(i)
      print(copy)
      assert False
  return after - before

a = [5, 4]
test_array(a)
a = [4, 5, 4, 11, 11, 8, 9, 20, 8, 5, 7, 9, 20, 12, 17, 15, 7, 7, 14, 8]
test_array(a)
a = [4, 5, 4, 1]
test_array(a)
a = [0, 8, 10, 5, 10, 0, 4, 8, 1, 10]
test_array(a)
a = [2, 3, 5, 7, 10]
test_array(a)
a = [1, 4, 7, 8, 10, 12, 17]
test_array(a)


def test_params(arrays_count, array_len, max_value):
  start = time()
  for i in range(arrays_count):
    a = [randint(0, max_value) for j in range(array_len)]
    test_array(a)
  end = time()
  print(str(arrays_count) + ' X ' + str(array_len) + ' (0..' + str(max_value) + ') - ' + str(end - start))

print('arrays_count X each_array_len (values_range) - seconds')
print('...')

start = time()
#'''
test_params(1000, 100, 100)
test_params(1000, 100, 10)
test_params(10, 1000, 100)
test_params(10, 1000, 1000)
test_params(10, 100, 10000)
test_params(1, 4000, 10000)
test_params(1, 4000, 100)
#'''
print('sorted array (4000): ', test_array([i for i in range(4000)]))
print('unsorted array (4000): ', test_array([i for i in range(4000, 0, -1)]))
end = time()

print('-------')
print('Common time:', end - start)
print('All test are success!')
