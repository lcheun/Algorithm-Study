from collections import deque

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(x, y):
    q = deque()
    q.append((x,y))
    visited[x][y] = 1

    while q:
        px, py = q.popleft()
        for i in range(4):
            nx, ny = px+dx[i], py+dy[i]

            if 0<=nx<N and 0<=ny<N and not visited[nx][ny]:
                if arr[nx][ny]>h: # 잠기지 않은 영역
                    q.append((nx,ny))
                    visited[nx][ny] = 1


max_h = max(map(max, arr))

max_area = 1 #정답

#모든 물 높이(1~최대물높이)에 대해서 안전영역 개수 bfs로 센다
#안전영역 각각의 덩어리 개수를 세어준다는 느낌으로 bfs 한번 끝나면 area += 1
# N이 최대 100밖에 안된다 걍 ㄱㄱ
for h in range(1, max_h+1):
    area = 0
    visited = [[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if not visited[i][j] and arr[i][j]>h:
                bfs(i,j)
                area += 1

    max_area = max(area, max_area)

print(max_area)
