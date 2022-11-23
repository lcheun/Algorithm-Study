import sys
# deque 모듈 사용하여 pop -> popleft, 시간 복잡도 O(N) -> O(1)
from collections import deque

input = sys.stdin.readline

M, N = map(int, input().split())
matrix = []
# 좌표 넣어줄 것
queue = deque([])
# 방향 리스트
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
res = 0

# 익은 토마토 queue에 넣기
for i in range(N):
    matrix.append(list(map(int, input().split())))
    for j in range(M):
        if matrix[i][j] == 1:
            queue.append([i, j])


# bfs 함수, 재귀 X
def bfs():
    while queue:
        # 익은 토마토 꺼내서
        x, y = queue.popleft()
        # 4방향 익힐 토마토 확인
        for i in range(4):
            nx, ny = dx[i] + x, dy[i] + y
            # 좌표범위 내의 익지 않은 토마토인지 확인
            if 0 <= nx < N and 0 <= ny < M and matrix[nx][ny] == 0:
                matrix[nx][ny] = matrix[x][y] + 1 # n일째에 익혀졌음 같은 의미
                queue.append([nx, ny])


bfs()
# print(matrix) 토마토밭 현황 확인 ..
for i in matrix:
    for j in i:
        # 토마토 익히지 못하는 경우
        if j == 0:
            print(-1)
            exit(0)
    res = max(res, max(i))

print(res-1)