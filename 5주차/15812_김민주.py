import sys
from collections import deque

N,M = map(int,input().split())

arr = []
vill = []
empty = []

for i in range(N):
    tmp = list(input())
    for j, val in enumerate(tmp):
        if val=='1':
            vill.append((i,j))
        else:
            empty.append((i,j))
    arr.append(tmp)

dx = [-1,1,0,0]
dy = [0,0,-1,1]

INF = sys.maxsize
def bfs(x1, y1, x2, y2):
    visited = [[0]*M for _ in range(N)]
    q = deque()
    q.append((x1, y1))
    visited[x1][y1] = 1
    q.append((x2, y2))
    visited[x2][y2] = 1
    fin = len(vill)
    count = 0
    time = 0

    while q:
        time += 1
        size = len(q)
        while size:
            size -= 1
            x, y = q.popleft()
            for i in range(4):
                nx, ny = x+dx[i], y+dy[i]
                if 0<=nx<N and 0<=ny<M:
                    if not visited[nx][ny]:
                        if arr[nx][ny]=='1':
                            count += 1
                        visited[nx][ny] = 1
                        q.append((nx,ny))

        if fin==count:
            break

    return time

answer = sys.maxsize
#동시에 2개 설치
for i in range(len(empty)-1):
    (x1, y1) = empty[i]
    for j in range(i+1, len(empty)):
        (x2, y2) = empty[j]

        answer = min(answer, bfs(x1, y1, x2, y2))

print(answer)