import sys
sys.setrecursionlimit(10**5)
from collections import deque
n, m = map(int, raw_input().split(" "))
cor = [[0]*m for _ in range(n)]
grid = []
g = [[[] for _ in range(m)] for _ in range(n)]

for i in range(n):
	grid.append(raw_input())

for i in range(n):
	for j in range(m):
		if i and grid[i][j] == grid[i-1][j]:
			g[i][j].append((i-1, j))
		if j and grid[i][j] == grid[i][j-1]:
			g[i][j].append((i, j-1))
		if i < n-1 and grid[i][j] == grid[i+1][j]:
			g[i][j].append((i+1, j))
		if j < m-1 and grid[i][j] == grid[i][j+1]:
			g[i][j].append((i, j+1))

def achaCiclo(i, j, pre):
	cor[i][j] = 1
	for v in g[i][j]:
		if v == pre: continue
		if cor[v[0]][v[1]] == 0:
			achaCiclo(v[0], v[1], (i, j))

		if cor[v[0]][v[1]] in [1, 3]:
			cor[i][j] = 3
	if cor[i][j] == 1:
		cor[i][j] = 2


ciclo = False
for i in range(n):
	for j in range(m):
		if cor[i][j] == 0:
			achaCiclo(i, j, (-1, -1))
			if cor[i][j] == 3:
				ciclo = True

if ciclo:
	print("Yes")
else:
	print("No")
