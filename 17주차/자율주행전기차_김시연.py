"""
이 문제가 레전드인듯...너무 복잡해서 하기 싫어지는 마음
하다 꼬여서 정답 참고함
"""
import sys
from collections import deque
input = sys.stdin.readline


# input
n, m, battery = map(int, input().split())
road = [[] for _ in range(n+1)]

# passenger 위치를 입력으로 받는데, 1부터 시작하기 때문에 그리드 초기화도 n+1만큼
for i in range(1, n+1):
    road[i].append(0)
    road[i].extend(list(map(int, input().split())))

car_pos = tuple(map(int, input().split()))
passengers = [tuple(map(int, input().split())) for _ in range(m)]
moved_passenger = [False for _ in range(n*n)]

# bfs로 탐색 후 좌표별 자동차와의 거리 탐색용으로 배열 생성
step = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
visited = [[False for _ in range(n + 1)] for _ in range(n + 1)]

def bfs(start_pos):
    deq = deque()
    for i in range(1, n + 1):
        for j in range(n + 1):
            visited[i][j] = False

    start_x, start_y = start_pos

    visited[start_x][start_y] = True
    step[start_x][start_y] = 0
    deq.append((start_x, start_y))

    dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

    # BFS 시작
    while deq:
        curr_x, curr_y = deq.popleft()

        for x, y in zip(dx, dy):
            nx, ny = curr_x + x, curr_y + y

            if 1 <= nx <= n and 1 <= ny <= n:
                if not visited[nx][ny] and not road[nx][ny]:
                    deq.append((nx, ny))
                    step[nx][ny] = step[curr_x][curr_y] + 1
                    visited[nx][ny] = True


def need_update(short_pos, new_pos):
    if short_pos == (-1, -1):
        return True

    sx, sy = short_pos
    nx, ny = new_pos

    # 거리, 행, 열 순으로 더 작은 경우에만 골라져야 합니다.
    return (step[sx][sy], sx, sy) > (step[nx][ny], nx, ny)


def move_passenger():
    global car_pos, battery

    # step1) 승객 최단거리 찾기
    bfs(car_pos)

    # step2) 가장 우선순위 높은 승객 출발위치 구하기
    short_pos, short_idx = (-1, -1), -1
    for i, (start_x, start_y, dest_x, dest_y) in enumerate(passengers):
        if moved_passenger[i] or not visited[start_x][start_y] \
                or step[start_x][start_y] > battery:
            continue

        if need_update(short_pos, (start_x, start_y)):
            short_pos, short_idx = (start_x, start_y), i

    # 현 연료로 태울 수 있는 승객 없음
    if short_pos == (-1, -1):
        return False

    # 태울 수 있는 승객이 있는 경우 -> 이동하기
    start_x, start_y, end_x, end_y = passengers[short_idx]
    car_pos = (start_x, start_y)
    battery -= step[start_x][start_y]

    # step3) 목적지 까지의 최단거리 구하기
    bfs((start_x, start_y))

    # 만일 도달 불가능한경우
    if not visited[end_x][end_y] or \
            step[end_x][end_y] > battery:
        return False

    # 가능한 경우
    car_pos = (end_x, end_y)
    battery -= step[end_x][end_y]
    moved_passenger[short_idx] = True
    battery += step[end_x][end_y] * 2
    return True


# output
for _ in range(m):
    is_moved = move_passenger()

    if not is_moved:
        print(-1)
        exit(0)

print(battery)
