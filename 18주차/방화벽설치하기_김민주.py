import sys, copy
from collections import deque

input = sys.stdin.readline
n,m = map(int, input().split())
arr = []
# 불 2, 방 1, 빈 0
empty = []
fire = []
wall = []

for i in range(n):
    temp = list(map(int, input().split()))
    for j in range(m):
        if temp[j]==0:
            empty.append((i,j))
        elif temp[j]==1:
            wall.append((i,j))
        else:
            fire.append((i,j))
    arr.append(temp)

# 방화벽 세개 뽑고 그 결과에 따라 bfs
# bfs로 불나지 않은 부분 개수 구한다.
visited = [0 for _ in range(len(empty))]
answer = 0
def dfs(depth, start):
    global answer
    if depth==3:
        answer = max(bfs(), answer)
        return

    for i in range(start, len(empty)):
        if not visited[i]:
            visited[i] = 1
            wall.append(empty[i])
            arr[empty[i][0]][empty[i][1]] = 1
            dfs(depth+1, i+1)
            visited[i] = 0
            wall.pop()
            arr[empty[i][0]][empty[i][1]] = 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
def bfs():
    q = deque()
    fire_visited = [[0]*m for _ in range(n)]
    temp_arr = copy.deepcopy(arr)
    count = n*m-len(wall)
    for x, y in fire:
        q.append((x,y))
        fire_visited[x][y] = 1
        count -= 1

    while q:
        px, py = q.popleft()

        for i in range(4):
            nx, ny = px+dx[i], py+dy[i]

            if 0<=nx<n and 0<=ny<m and not fire_visited[nx][ny]:
                if temp_arr[nx][ny]==0:
                    temp_arr[nx][ny] = 2
                    count -= 1
                    fire_visited[nx][ny] = 1
                    q.append((nx,ny))

    return count
    

dfs(0,0)
print(answer)
