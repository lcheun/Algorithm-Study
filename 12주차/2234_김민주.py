from collections import deque
import copy

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(M)]
temp_arr = copy.deepcopy(arr)

binary = [8, 4, 2, 1] # 남, 동, 북, 서

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

count = 0 # 방의 개수
visited = [[0] * N for _ in range(M)]
room_info = [[[] for _ in range(N)] for _ in range(N)]

group_num = 0


def bfs(x, y):
    global group_num

    visited[x][y] = 1

    q = deque()
    q.append((x,y))

    area = 1 # 이 방 넓이

    # 이 방에 속하는 칸 담기 위한 배열
    group = []
    group.append((x,y))

    while q:
        px, py = q.popleft()
        wall = arr[px][py]
        for i in range(4):
            # 벽 있음 -> 못 감
            if wall >= binary[i]:
                wall -= binary[i]
            # 벽이 없고 / 다음 범위가 유효하면서 방문하지 않은 경우
            else:
                nx, ny = px+dx[i], py+dy[i]

                if 0<=nx<M and 0<=ny<N and not visited[nx][ny]:
                    area += 1
                    q.append((nx,ny))
                    visited[nx][ny] = 1
                    group.append((nx, ny))

    # 각 칸에 대해 방의 정보 담기(방번호, 방의 넓이)
    for i, j in group:
        room_info[i][j].append(group_num)
        room_info[i][j].append(area)

    group_num+=1
    return area

# 원래 방 상태에서 최대 방 넓이, 방 개수 구하기
max_area = 0

for i in range(M):
    for j in range(N):
        if not visited[i][j]:
            max_area = max(bfs(i, j), max_area)
            count += 1

# 벽을 하나 없앴을 때 최대 방 넓이 구하기
maybe_max = 0
for i in range(M):
    for j in range(N):
        for d in range(4):
            if arr[i][j] >= binary[d]:
                nx, ny = i+dx[d], j+dy[d]

                if 0<=nx<M and 0<=ny<N:
                    # 방 종류가 다른 경우에 방 넓이 합치기
                    if room_info[i][j][0] != room_info[nx][ny][0]:
                        #print(room_info[i][j])
                        maybe_max = max(maybe_max, room_info[i][j][1]+room_info[nx][ny][1])


print(count)
print(max_area)
print(maybe_max)
