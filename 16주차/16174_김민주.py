import sys
from collections import deque


input = sys.stdin.readline

N = int(input())
arr = [list(map(int, input().strip().split())) for _ in range(N)]

dx = [1, 0]
dy = [0, 1]
visited = [[0]*N for _ in range(N)]

def bfs():
    q = deque()
    q.append((0, 0))
    visited[0][0] = 1

    while q:
        x, y = q.popleft()

        # 도달
        if x==N-1 and y==N-1:
            print("HaruHaru")
            return

        for i in range(2):
            nx, ny = x+(dx[i]*arr[x][y]), y+(dy[i]*arr[x][y]) # 값만큼 이동하기 위해 arr값을 곱해줌
            if 0<=nx<N and 0<=ny<N and not visited[nx][ny]:
                visited[nx][ny] = 1
                q.append((nx,ny))

    print("Hing")
    return

bfs()


