from collections import deque
import copy

N, M = map(int, input().split())

empty = []
virus = []
wall = []

arr = []

for i in range(N):
    temp = list(map(int, input().split()))
    arr.append(temp)
    for j in range(M):
        if temp[j] == 0:
            empty.append((i,j))
        elif temp[j] == 1:
            wall.append((i,j))
        else:
            virus.append((i,j))

answer = 0
visited = [0]*(len(empty))


def dfs(start, depth):
    global answer
    if depth == 3:
        answer = max(bfs(), answer)
        return

    for i in range(start, len(empty)):
        if not visited[i]:
            visited[i] = 1
            arr[empty[i][0]][empty[i][1]] = 1
            dfs(i+1, depth+1)
            visited[i] = 0
            arr[empty[i][0]][empty[i][1]] = 0


dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs():
    q = deque()
    b_visited = [[0]*M for _ in range(N)]
    temp_arr = copy.deepcopy(arr)

    for i, j in virus:
        b_visited[i][j] = 1
        q.append((i,j))

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]

            if 0<=nx<N and 0<=ny<M and not b_visited[nx][ny]:
                if temp_arr[nx][ny] == 0:
                    b_visited[nx][ny] = 1
                    temp_arr[nx][ny] = 2
                    q.append((nx,ny))

    safe = 0
    for i in range(N):
        for j in range(M):
            if temp_arr[i][j] == 0:
                safe += 1

    return safe


dfs(0, 0)
print(answer)