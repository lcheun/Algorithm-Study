from collections import deque

N,M = map(int, input().split())
arr = [list(map(int, list(input()))) for _ in range(N)]
# 위에서 아래로, 왼쪽에서 오른쪽으로 차례대로 맥스값을 옮긴다

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

visited = [[0]*M for _ in range(N)]


def bfs(x,y,h):
    q = deque()
    q.append((x,y))
    save = [(x,y)]
    visited[x][y] = 1
    out = False

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            # 물을 부을 수 있는 경우
            if 0<=nx<N and 0<=ny<M and arr[nx][ny]!=0:
                if not visited[nx][ny]:
                    if arr[nx][ny]<h:
                        q.append((nx,ny))
                        visited[nx][ny] = 1
                        save.append((nx,ny))
            # 물이 세거나 땅에 흡수됨
            else:
                out = True

    if out:
        return 0
    #물을 부을 수 있다면 물을 붓는 곳에 물 양을 늘리고 부은 물의 총 양을 구한다(한 단계씩 붓기 때문에 +1)
    else:
        water = 0
        for i, j in save:
            arr[i][j] += 1
            water += 1
        return water


def solve(h):
    val = 0
    for i in range(N):
        for j in range(M):
            if not visited[i][j] and 0<arr[i][j]<h:
                val += bfs(i,j,h)
    return val


# 물을 한 단계씩 붓는다
answer = 0
for h in range(1, 10):
    visited = [[0]*M for _ in range(N)]
    answer += solve(h)

print(answer)