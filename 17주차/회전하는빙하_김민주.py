import sys, copy
from collections import deque

input = sys.stdin.readline

n, q = map(int, input().split())
arr = [list(map(int, input().strip().split())) for _ in range(2**n)]
level = list(map(int, input().strip().split()))

dx = [0, 1, -1, 0]
dy = [1, 0, 0, -1]

new_arr = [[0 for _ in range(2**n)] for _ in range(2**n)]

# 회전 시키는 거 어렵..
def rotate(l):
    global new_arr, arr
    new_arr = [[0 for _ in range(2**n)] for _ in range(2**n)]

    box_size = 2**l
    half_size = 2**(l-1)
    #print(half_size)
    x, y = 0, 0
    
    for i in range(0, 2**n, 2**l):
        for j in range(0, 2**n, 2**l):
            move(i, j, half_size, 0)
            move(i, j+half_size, half_size, 1)
            move(i+half_size, j, half_size, 2)
            move(i+half_size, j+half_size, half_size, 3)

    arr = copy.deepcopy(new_arr)
        

def move(start_row, start_col, half_size, move_dir):
    global new_arr
    for row in range(start_row, start_row+half_size):
        for col in range(start_col, start_col+half_size):
            nr = row+dx[move_dir]*half_size
            nc = col+dy[move_dir]*half_size

            new_arr[nr][nc] = arr[row][col]
    

def melt():
    melt_list = []
    for i in range(2**n):
        for j in range(2**n):
            if arr[i][j] != 0:
                count = 0
                for d in range(4):
                    nx, ny = i+dx[d], j+dy[d]
                    if 0<=nx<2**n and 0<=ny<2**n:
                        if arr[nx][ny] != 0:
                            count += 1
                if count < 3:
                    melt_list.append((i,j))

    for i, j in melt_list:
        arr[i][j] -= 1

visited = [[0]*2**n for _ in range(2**n)]
total = 0
def bfs(x, y):
    global total 

    q = deque()
    q.append((x,y))
    visited[x][y] = 1
    count = 1
    total += arr[x][y]

    while q:
        px, py = q.popleft()
        for i in range(4):
            nx, ny  = px+dx[i], py+dy[i]

            if 0<=nx<2**n and 0<=ny<2**n and not visited[nx][ny]:
                if arr[nx][ny] != 0:
                    visited[nx][ny] = 1
                    q.append((nx,ny))
                    count += 1
                    total += arr[nx][ny]

    return count

def calc():
    max_size = 0
    for i in range(2**n):
        for j in range(2**n):
            if not visited[i][j] and arr[i][j]!=0:
                max_size = max(bfs(i,j), max_size)

    return max_size

for l in level:
    if l!=0:
        rotate(l)
    # for a in arr:
    #     print(*a)
    melt()
    # print()
    # for a in arr:
    #     print(*a)


max_size = calc()

print(total)
print(max_size)
                


# rotate(2)
# print(arr)
