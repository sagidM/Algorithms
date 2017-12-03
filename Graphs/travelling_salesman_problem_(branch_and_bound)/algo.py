# https://habrahabr.ru/post/246437/
from copy import deepcopy
import sys
# sys.stdin = open('in2.txt', 'r')
INF = 10**6
CUT = '-'

if sys.version.split('.')[0] == '2':
    input = raw_input

# reading
#n, k = map(int, input().split(' '))
k = int(input())
g = [None for i in range(k)]
for i in range(k):
    g[i] = list(map(lambda x: int(x) if x != '-' else INF, input().split(' ')))


def min_in_raw(g, raw):
    m = INF+1
    for i in range(len(g[raw])):
        if g[raw][i] == CUT: continue
        m = min(m, g[raw][i])
    if m == INF+1: m = None # is cut string
    return m
def min_in_column(g, column):
    m = INF+1
    for i in range(len(g)):
        if g[i][column] == CUT: continue
        m = min(m, g[i][column])
    if m == INF+1: m = None # is cut string
    return m
def print_matrix(matrix, title = ''):
    print(title)
    for it in matrix: print(it)
    print('\n')
    
############
### algo ###
############

print_matrix(g, '<Source graph>')

def reduction(g):
    min_sum = 0
    for i in range(len(g)):
        m = min_in_raw(g, i)
        if m == None: continue
        for j in range(len(g)):
            if g[i][j] == CUT: continue
            g[i][j] -= m
        min_sum += m

    for i in range(len(g)):
        m = min_in_column(g, i)
        if m == None: continue
        for j in range(len(g)):
            if g[j][i] == CUT: continue
            g[j][i] -= m
        min_sum += m
    return min_sum

def reduction_by(g, xy, hm, vm):
    for i in range(len(g)):
        if g[xy[0]][i] == CUT: continue
        g[xy[0]][i] -= hm
    g[xy[0]][xy[1]] = INF
    for i in range(len(g)):
        if g[i][xy[1]] == CUT: continue
        g[i][xy[1]] -= vm
    g[xy[0]][xy[1]] = INF

min_sum = reduction(g)

print('<Start (R = {%i})>\n' % min_sum)

def get_min_r():
    t_min = INF
    current_sheet_index = None
    for i in range(len(R)):
        if R[i][2]: continue
        if t_min > R[i][0]:
            t_min = R[i][0]
            current_sheet_index = i
    return current_sheet_index

def remove_cross_from_matrix(matrix, xy):
    for i in range(len(matrix)):
        matrix[xy[0]][i] = CUT
        matrix[i][xy[1]] = CUT

# [fine, g, is_sheet, is_present, edge, parent_index]
R = [[min_sum, g, False, True]]

## Cycle ##
while True:
    current_sheet_index = get_min_r()
    assert current_sheet_index is not None # or break
    r = R[current_sheet_index]
    g = deepcopy(r[1])
    print_matrix(g, '<Matrix (fine = %i)>' % r[0])
    
    # search zeros
    zeros = []
    for i in range(len(g)):
        for j in range(len(g)):
            if g[i][j] == 0:
                zeros.append((i, j))

    if len(zeros) == 1:
        break
    # search maximum among minimums in zeros
    mx = -1
    vm0 = hm0 = None
    for zero in zeros:
        t = g[zero[0]][zero[1]]
        g[zero[0]][zero[1]] = INF
        hm = min_in_raw(g, zero[0])
        vm = min_in_column(g, zero[1])
        if mx < hm + vm:
            mx = hm + vm
            vm0, hm0 = vm, hm
            skip = zero
        g[zero[0]][zero[1]] = t
    assert skip[0] != skip[1] and mx >= 0
    g[skip[0]][skip[1]] = INF
    expensive_g = deepcopy(g)
    reduction_by(expensive_g, skip, hm0, vm0)
    print_matrix(expensive_g, '<Reduction cross %s, %s>' % (str(skip), mx))
    remove_cross_from_matrix(g, skip)
    print_matrix(g, '<Cross-line removing ' + str(skip) + '>')
    
    # fine
    if g[skip[1]][skip[0]] != CUT:
        g[skip[1]][skip[0]] = INF
    min_sum = reduction(g)
    print_matrix(g, '<Reduction (sum = %i)>' % min_sum)

    r[2] = True
    R.append([r[0] + mx, expensive_g, False, False, skip, current_sheet_index])
    R.append([r[0] + min_sum, deepcopy(g), False, True, skip, current_sheet_index])
    print('<R += {%i+%i, %i+%i}; %s>' % (r[0], mx, r[0], min_sum, skip))
    print('-'*20 + '\n')

#print('R: ' + str(list(map(lambda x: (x[0], x[2]), R))))

edges = [None]*k
edges[zeros[0][0]] = zeros[0][1]
i = 0
while i < k-1:
    assert r[4][0] is not None
    if r[3]:
        edges[r[4][0]] = r[4][1]
        i += 1
    r = R[r[5]]

j = 0
path = [0+1]
for i in range(k):
    j = edges[j]
    path.append(j+1)
print(path)
