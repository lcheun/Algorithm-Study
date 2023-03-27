import sys
from collections import deque

input = sys.stdin.readline

# input 받기
n, q = map(int, input().split())
grid_size = 2 ** n
ice = [list(map(int, input().split())) for _ in range(grid_size)]
new_ice = [[0 for _ in range(grid_size)] for _ in range(grid_size)]
levels = list(map(int, input().split()))
# 오른쪽, 아래, 위, 왼쪽 이동 순(시계방향)
dx, dy = [0, 1, -1, 0], [1, 0, 0, -1]


def move(start_r, start_c, half_size, move_dir):
    for r in range(start_r, start_r + half_size):
        for c in range(start_c, start_c + half_size):
            next_r = r + dx[move_dir] * half_size
            next_c = c + dy[move_dir] * half_size
            new_ice[next_r][next_c] = ice[r][c]


def spin(level):
    for i in range(grid_size):
        for j in range(grid_size):
            new_ice[i][j] = 0

    box_size, half_size = 2 ** level, 2 ** (level - 1)

    for i in range(0, grid_size, box_size):
        for j in range(0, grid_size, box_size):
            # i, j가 회전하는 단위의 왼쪽 위 모서리임
            move(i, j, half_size, 0)
            move(i, j + half_size, half_size, 1)
            move(i + half_size, j, half_size, 2)
            move(i + half_size, j + half_size, half_size, 3)

    for i in range(grid_size):
        for j in range(grid_size):
            ice[i][j] = new_ice[i][j]


def get_near_ice(cx, cy):
    cnt = 0
    for x, y in zip(dx, dy):
        nx, ny = cx + x, cy + y
        if 0 <= nx < grid_size and 0 <= ny < grid_size and ice[nx][ny]:
            cnt += 1
    return cnt


def melt():
    for i in range(grid_size):
        for j in range(grid_size):
            new_ice[i][j] = 0

    for i in range(grid_size):
        for j in range(grid_size):
            cnt = get_near_ice(i, j)
            if ice[i][j] and cnt < 3:
                new_ice[i][j] = ice[i][j] - 1
            else:
                new_ice[i][j] = ice[i][j]

    for i in range(grid_size):
        for j in range(grid_size):
            ice[i][j] = new_ice[i][j]


def count_ice():
    # 새로 알게된 sum 방법...
    return sum([
        ice[i][j]
        for i in range(grid_size)
        for j in range(grid_size)
    ])


def get_biggest():
    max_size = 0
    deq = deque()
    visited = [[0 for _ in range(grid_size)] for _ in range(grid_size)]

    for i in range(grid_size):
        for j in range(grid_size):
            if ice[i][j] and not visited[i][j]:
                visited[i][j] = True
                deq.append((i, j))

                group_size = 0
                while deq:
                    cx, cy = deq.popleft()
                    group_size += 1

                    for x, y in zip(dx, dy):
                        nx, ny = cx + x, cy + y

                        if 0 <= nx < grid_size and 0 <= ny < grid_size:
                            if not visited[nx][ny] and ice[nx][ny]:
                                deq.append((nx, ny))
                                visited[nx][ny] = True

                max_size = max(max_size, group_size)
    return max_size


for level in levels:
    if level:
        spin(level)
        # for i in range(2 ** n):
        #    print(ice[i])
    melt()

print(count_ice())
print(get_biggest())
