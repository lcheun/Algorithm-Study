import sys
from collections import deque

input = sys.stdin.readline
N, M = map(int, input().split())
arr = [list(map(int, input().strip().split())) for _ in range(N)]


dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]



def bfs(x, y):
    visited[x][y] = 1
    q = deque()
    q.append((x, y))

    melting = []

    while q:
        px, py = q.popleft()
        melt_cnt = 0

        for i in range(4):
            nx = px + dx[i]
            ny = py + dy[i]

            if 0 <= nx < N and 0 <= ny < M:
                if not visited[nx][ny]:
                    # 빙산인 경우
                    if arr[nx][ny]:
                        visited[nx][ny] = 1
                        q.append((nx,ny))
                    # 주변에 있는 애가 바다인 경우
                    else:
                        melt_cnt += 1

        # Melting 리스트에 넣어줌
        if melt_cnt:
            melting.append((px, py, melt_cnt))

    return melting

year = 0
while True:
    count = 0
    visited = [[0]*M for _ in range(N)]

    for i in range(N):
        for j in range(M):
            if arr[i][j] != 0 and not visited[i][j]:
                melting = bfs(i, j)
                count += 1

    for mx, my, melt_cnt in melting:
        arr[mx][my] = max(0, arr[mx][my]-melt_cnt)

    if count == 0:
        year = 0
        break
    if count > 1:
        break

    year += 1

print(year)