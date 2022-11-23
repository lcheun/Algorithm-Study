import sys
input = sys.stdin.readline
from collections import deque

m, n = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(n)]
queue = deque([])
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
res = 0

for i in range(n):
    for j in range(m):
        if matrix[i][j] == 1:
            queue.append([i, j])

def bfs():
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx, ny = dx[i] + x, dy[i] + y
            if 0 <= nx < n and 0 <= ny < m and matrix[nx][ny] == 0:
                matrix[nx][ny] = matrix[x][y] + 1
                queue.append([nx, ny])

bfs()
for i in matrix:
    for j in i:
        if j == 0:
            print(-1)
            exit(0)
    res = max(res, max(i))
print(res - 1)

#시도======================
# M,N=map(int, sys.stdin.readline().split())
# tomato=[]
# for m in range(N):
#     for n in range(M):
#         to=[]
#         to.append(int(sys.stdin.readline()))
#         print('ah')
#     tomato.append(to)


#input()으로 풀면 시간초과가 나서 sys.stdin.readline()으로 입력을 받아야 한다
#BFS의 큐를 이용할 땐 deque() 라이브러리를 사용
# popleft()와 pop(0)의 속도 차이 (O(1)과 O(n)
#상하좌우 돌 땐 dx, dy를 만들면 편하다 
#BFS를 끝내고 리스트를 돌며 0을 발견하면 exit()를 이용해 종료
# 돌 때 1에서부터 날짜를 추가해 올라갔기 때문에 마지막 리스트의 최댓값에서 1을 빼줘야 한다