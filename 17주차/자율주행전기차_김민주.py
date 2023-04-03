import sys
from collections import deque

input = sys.stdin.readline
n, m, c = map(int, input().split()) #격자크기, 승객수, 초기배터리충전량

arr = [list(map(int, input().strip().split())) for _ in range(n)] #도로 정보
x, y = map(int, input().split()) # 처음 위치
x-=1
y-=1
customers = [list(map(int, input().strip().split())) for _ in range(m)] #승객 출발 x, y / 도착 x, y
start = [[0]*(n) for _ in range(n)]
end = [[0]*(n) for _ in range(n)]
flag = 0
for i in range(len(customers)):
    x_s, y_s, x_e, y_e = customers[i]
    # 그냥 배열을 하나 더 크게 만들걸...
    x_s-=1
    y_s-=1
    x_e-=1
    y_e-=1

    # 해당 출발&도착 위치를 가진 승객이 누군지 표시
    start[x_s][y_s] = i+1
    end[x_e][y_e] = i+1

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
visited_people = [0 for _ in range(m)]
# 현 위치와 가장 가까운 승객을 뽑는다.
def pick(cx, cy):
    global count
    q = deque()
    visited = [[0]*(n) for _ in range(n)]
    visited[cx][cy] = 1
    q.append((cx, cy))
    min_list = []
    min_dis = sys.maxsize
    min_cus = 0
    
    while q:
        px, py = q.popleft()
        for i in range(4):
            nx, ny = px+dx[i], py+dy[i]

            if 0<=nx<n and 0<=ny<n and arr[nx][ny]==0:
                if not visited[nx][ny]:
                    visited[nx][ny] = visited[px][py] + 1
                    q.append((nx,ny))
                # 현재 차의 위치 == 승객 위치 일 수 있기 때문에
                # 승객 간 최소 거리 측정하는 건 visited 여부와 상관 없이 해주었다.
                if start[nx][ny] != 0:
                    who = start[nx][ny]
                    if not visited_people[who-1]:
                        min_list.append((visited[nx][ny], nx, ny))

    # 조건에 따라 정렬
    min_list.sort(key = lambda x:(x[0], x[1], x[2]))
    if min_list:
        min_dis = min_list[0][0]
        min_cus = start[min_list[0][1]][min_list[0][2]]
    return min_dis, min_cus

# 승객 태우고 가는 거 
def go(min_dis, min_cus):
    global c, x, y

    # 이동 거리가 0인데 아래 수식하면 +1이 되기 때매 0 아닐 때만
    if min_dis!=0:
        c -= (min_dis-1)
    # 지금 연료로 가지 못한다면 -1을 리턴한다.
    if c < 0:
        return -1

    xs, ys, xe, ye = customers[min_cus-1]
    # 배열을 크게 잡을 걸...
    xs-=1
    ys-=1
    xe-=1
    ye-=1

    q = deque()
    q.append((xs, ys))
    visited = [[0]*(n) for _ in range(n)]
    visited[xs][ys] = 1

    while q:
        px, py = q.popleft()
        # 도착했는데 연료보다 많이 가야되면 -1리턴
        # 갈 수 있으면 거리 리턴
        if px==xe and py==ye:
            x = xe
            y = ye
            if visited[px][py]-1 > c:
                return -1
            return visited[px][py]-1
        for i in range(4):
            nx, ny = px+dx[i], py+dy[i]

            if 0<=nx<n and 0<=ny<n and not visited[nx][ny] and arr[nx][ny]==0:
                
                next_cost = visited[px][py]+1
                visited[nx][ny] = next_cost
                q.append((nx,ny))

    return -1

count = 0
def play():
    global x, y, c, count
    while True:
        # 모든 승객 태워다 줬으면 연료 리턴
        if count == m:
            return c
        min_dis, min_cus = pick(x, y)
        visited_people[min_cus-1] = 1 # 태워다 준 승객 표시
        #print(visited_people)
        x, y = customers[min_cus-1][:2]
        x-=1
        y-=1
        dis = go(min_dis, min_cus)
        if dis==-1:
            return -1
        else:
            #print(min_cus)
            #print(c)
            c += dis
            #print(c)
            count += 1

val = play()                    
print(val)

