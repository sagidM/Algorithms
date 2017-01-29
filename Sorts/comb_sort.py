
def bubble_sort(a):
  for i in range(len(a)):
    is_sorted = True
    for j in range(1, len(a)-i):
      if a[j-1] > a[j]:
        a[j-1], a[j] = a[j], a[j-1]
        is_sorted = False
    if is_sorted: break

def comb_sort(a):
  from math import e
  golden_ratio = (1 + 5**0.5)/2        # 1.2473309501039787
  factor = 1 / (1 - 1/e**golden_ratio) # 1.61803398875
  step = len(a)

  while step is not 1:
    step = int(step / factor)

    for i in range(0, len(a)-step):
      if a[i] > a[i+step]:
        a[i], a[i+step] = a[i+step], a[i]

  bubble_sort(a)
      

  
if __name__ == '__main__':
  a = [5, 1, 2, 3, 10]
  comb_sort(a)
  print(a)

