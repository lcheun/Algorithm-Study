# 실버2 bfs

from collections import deque

T = int(input())

dx = [-1,1,0,0]
dy = [0,0,-1,1]


def bfs(x, y):
    visited[x][y] = 1
    q = deque()
    q.append((x,y))

    while q:
        px, py = q.popleft()
        for i in range(4):
            nx, ny = px+dx[i], py+dy[i]

            if 0<=nx<N and 0<=ny<M and not visited[nx][ny]:
                if arr[nx][ny] == 1:
                    visited[nx][ny] = 1
                    q.append((nx,ny))


for _ in range(T):
    M, N, K = map(int, input().split())

    arr = [[0] * M for _ in range(N)]
    visited = [[0]*M for _ in range(N)]

    for _ in range(K):
        X, Y = map(int, input().split())
        arr[Y][X] = 1

    area = 0
    for i in range(N):
        for j in range(M):
            if not visited[i][j] and arr[i][j]:
                bfs(i,j)
                area+=1

    print(area)