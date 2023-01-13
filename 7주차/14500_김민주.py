from collections import deque

N,M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

answer = 0
visited = [[0]*M for _ in range(N)]


def dfs(depth, sum, x, y):
    global answer

    if depth == 4:
        answer = max(sum, answer)
        return

    for i in range(4):
        nx, ny = x+dx[i], y+dy[i]
        if 0<=nx<N and 0<=ny<M and not visited[nx][ny]:
            visited[nx][ny] = 1
            dfs(depth+1, sum+arr[nx][ny], nx, ny)
            visited[nx][ny] = 0


sx = [(0,0,0,1), (0,0,0,-1), (0,-1,1,0), (0,-1,1,0)]
sy = [(0,-1,1,0), (0,-1,1,0), (0,0,0,-1), (0,0,0,1)]


def special(x, y):
    global answer

    for i in range(4):
        tmp = 0
        for j in range(4):
            nx = x+sx[i][j]
            ny = y+sy[i][j]

            if 0<=nx<N and 0<=ny<M:
                tmp += arr[nx][ny]
            else:
                tmp = 0
                break

        answer = max(tmp, answer)


for i in range(N):
    for j in range(M):
        visited[i][j] = 1
        dfs(1, arr[i][j], i, j)
        visited[i][j] = 0

        special(i,j)

print(answer)