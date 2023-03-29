import sys
from collections import deque

# https://www.codetree.ai/training-field/frequent-problems/codetree-mon-bread
# bfs 로 베이스캠프랑 다음 이동할 위치(최단거리로) 구하기

input = sys.stdin.readline
n,m = map(int, input().split()) #격자크기, 사람수
arr = [[0 for _ in range(n+1)]] #격자 정보
base = []

for i in range(1, n+1):
    temp = [0]+list(map(int, input().strip().split()))
    for j in range(1, n+1):
        if temp[j]==1:
            base.append((i,j))
    arr.append(temp)

store = [list(map(int, input().strip().split())) for _ in range(m)]

cant_go = [[0 for _ in range(n+1)] for _ in range(n+1)]


dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0] # 위, 왼, 오, 아

# 각 편의점과 각 베이스와 거리 구하기
def store_base(x, y, bx, by):
    q = deque()
    visited = [[0 for _ in range(n+1)] for _ in range(n+1)]

    q.append((x, y))
    visited[x][y] = 1

    while q:
        px, py = q.popleft()
        if px == bx and py == by:
            return visited[px][py]-1
        for i in range(4):
            nx, ny = px+dx[i], py+dy[i]
            if 1<=nx<n+1 and 1<=ny<n+1 and not visited[nx][ny] and not cant_go[nx][ny]:
                visited[nx][ny] = visited[px][py]+1
                q.append((nx,ny))


    return -1

# 편의점과 가장 가까운 베이스 구하기
def find_base(sx, sy):
    temp = []

    # 모든 베이스에 대해 store_base 함수 호출해서 거리를 구한다음에 규칙에 맞게 정렬해준다
    for bx, by in base:
        if not cant_go[bx][by]:
            dis = store_base(sx, sy, bx, by)
            
            if dis!=-1:
                temp.append((dis, bx, by))
    
    if temp:
        temp.sort(key=lambda x:(x[0], x[1], x[2]))
        return temp[0][1], temp[0][2]
    else:
        return -1, -1

# 사람위치에서부터 편의점 위치까지 최단거리로 이동할 수 있는 "다음 홉"을 구하는 함수
def go_store(x, y, sx, sy, d):
    q = deque()
    visited = [[0 for _ in range(n+1)] for _ in range(n+1)]
    visited[x][y] = 1

    # 다음 홉부터 탐색 진행
    nx, ny = x+dx[d], y+dy[d]
    first_nx, first_ny = nx, ny
    if 1<=nx<n+1 and 1<=ny<n+1 and not cant_go[nx][ny]:
        visited[nx][ny] = 2
        q.append((nx, ny))
    # 다음 홉이 갈 수 없는 곳이면 sys.maxsize를 dis로 반환
    else:
        return sys.maxsize, 0, 0

    while q:
        px, py = q.popleft()
        # 편의점까지 도착했으면 거리, 다음홉x, y를 반환
        if px==sx and py==sy:
            return visited[px][py]-1, first_nx, first_ny
        for i in range(4):
            nx, ny = px+dx[i], py+dy[i]

            if 1<=nx<n+1 and 1<=ny<n+1 and not cant_go[nx][ny] and not visited[nx][ny]:
                visited[nx][ny] = visited[px][py]+1
                q.append((nx, ny))

    # 해당 방향을 다음홉으로 삼았을 때 편의점까지 갈 수 없는 경우
    return sys.maxsize, 0, 0

pos_list = [[] for _ in range(m)] # 사람의 현위치
t = 1 # 시간

# 가장 처음은 3단계부터 시작한다 (그전에는 맵에 아무도 없으니까)
sx, sy = store[0] 
bx, by = find_base(sx, sy)
pos_list[0] = [bx, by]
cant_go[bx][by] = 1

stop = [0 for _ in range(m)] # 편의점에 도착한 사람은 stop해줌
count = 0 #편의점 도달한 사람 수
while count < m:
    t += 1
    temp_go = [(0,0) for _ in range(m)] # 사람별로 갈 다음 홉
    for i in range(m):
        # 현재 맵에 i번째 사람이 있고 편의점까지 도착하지 않은 경우
        if pos_list[i] and not stop[i]:
            sx, sy = store[i]
            x, y = pos_list[i]
            min_dis = sys.maxsize
            min_fx, min_fy = 0, 0
            # 각 방향 별로 거리를 구해서 최단거리로 이동할 수 있는 방향(다음 홉 위치)을 구한다
            for d in range(4):
                dis, fx, fy = go_store(x, y, sx, sy, d)
                if min_dis > dis:
                    min_dis = dis
                    min_fx, min_fy = fx, fy

            temp_go[i] = (min_fx, min_fy)
    
    for i, (fx, fy) in enumerate(temp_go):
        # 만약 한칸 이동했는데 도착한 경우 => 이동할 수 없는 칸으로 바꾸고 그 사람 stop시키고 도착완료한 사람 수 up
        if store[i][0]==fx and store[i][1]==fy:
            pos_list[i] = [fx, fy]
            cant_go[fx][fy] = 1
            stop[i] = 1
            count += 1
        # 도착한 거 아니면 그냥 이동만
        else:
            pos_list[i] = [fx, fy]

    # 3단계
    if t<=m:
        bx, by = find_base(store[t-1][0], store[t-1][1])
        pos_list[t-1] = [bx, by]
        cant_go[bx][by] = 1

print(t) 
