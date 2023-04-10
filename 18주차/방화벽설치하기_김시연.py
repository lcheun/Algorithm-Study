"""
-> 그냥 백트래킹을 통해 무지성으로 벽을 놓고, bfs로 탐색하기
그리드 크기인 n,m이 최대 8이니까 64칸밖에 되지 않으므로 무지성으로 벽을 놓아도 될것같음
"""
import sys
from collections import deque

input = sys.stdin.readline

# n이 행, m이 열 -> list[n][m]
n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]

empty_places = []
selected = []
deq = deque()
answer = 0


def init():
    for i in range(n):
        for j in range(m):
            visited[i][j] = False

    for i in range(n):
        for j in range(m):
            if grid[i][j] == 2:
                deq.append((i, j))
                visited[i][j] = True


def burn():
    global answer
    # 0: 우, 1: 하, 2: 좌, 3: 상
    dxs, dys = [0, 1, 0, -1], [1, 0, -1, 0]
    init()

    while deq:
        cx, cy = deq.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = cx + dx, cy + dy
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and grid[nx][ny] != 1:
                deq.append((nx, ny))
                visited[nx][ny] = True

    cnt = 0
    for i in range(n):
        for j in range(m):
            if not visited[i][j] and grid[i][j] == 0:
                cnt += 1

    answer = max(cnt, answer)


def solution(idx):
    global grid
    if idx == 3:
        burn()
        return

    for i in range(n):
        for j in range(m):
            if grid[i][j] == 0:
                grid[i][j] = 1
                solution(idx + 1)
                grid[i][j] = 0

    return


solution(0)
print(answer)



