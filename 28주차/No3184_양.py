from collections import deque

R, C = map(int, input().split())
sheep, wolf = 0, 0

arr = []
for i in range(R):
    temp = list(input())
    for j in range(C):
        if temp[j]=='v':
            wolf += 1
        if temp[j]=='o':
            sheep += 1

    arr.append(temp)

visited = [[0]*C for _ in range(R)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    global sheep, wolf

    q = deque()
    visited[x][y] = 1

    s, w = 0, 0
    if arr[x][y] == 'o':
        s += 1
    if arr[x][y] == 'v':
        w += 1

    q.append((x, y))

    while q:
        px, py = q.popleft()
        for i in range(4):
            nx = px+dx[i]
            ny = py+dy[i]

            if 0<=nx<R and 0<=ny<C and not visited[nx][ny]:
                if arr[nx][ny]!='#':
                    if arr[nx][ny]=='v':
                        w += 1
                    if arr[nx][ny]=='o':
                        s += 1
                    visited[nx][ny] = 1
                    q.append((nx,ny))


    if s>w:
        wolf -= w
    else:
        sheep -= s


for i in range(R):
    for j in range(C):
        if arr[i][j] != '#' and not visited[i][j]:
            bfs(i, j)

print(sheep, wolf)

