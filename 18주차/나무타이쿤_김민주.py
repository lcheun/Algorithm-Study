import sys

dx = [0, 0, -1, -1, -1, 0, 1, 1, 1]
dy = [0, 1, 1, 0, -1, -1, -1, 0, 1]

ddx = [-1, 1, -1, 1]
ddy = [-1, 1, 1, -1]

input = sys.stdin.readline
n,m = map(int, input().split())
arr = [list(map(int, input().strip().split())) for _ in range(n)]
move = [list(map(int, input().strip().split())) for _ in range(m)]
pos = [(n-2, 0), (n-2, 1), (n-1, 0), (n-1, 1)] #비료 좌표값
pos_arr = [[0]*n for _ in range(n)] #밭에서 비료 상태
for x, y in pos:
    pos_arr[x][y] = 1


for year in range(m):
    d, p = move[year]
    new_pos = []
    for i in range(len(pos)):
        x, y = pos[i]
        pos_arr[x][y] -= 1 #새 비료랑 전에 있던 비료가 겹치는 걸 고려해서 -1 +1 해줌

        nx = (x+dx[d]*p)%n #이동 격자 연결되게
        ny = (y+dy[d]*p)%n

        new_pos.append((nx,ny))
        pos_arr[nx][ny] += 1

        arr[nx][ny] += 1

    pos = new_pos

    # 비료 뿌린 데에 +1 만큼 작물 성장
    for x, y in pos:
        for dd in range(4):
            nnx, nny = x+ddx[dd], y+ddy[dd]
            if 0<=nnx<n and 0<=nny<n and arr[nnx][nny]!=0:
                arr[x][y] += 1

    # 비료 뿌린 데 제외하고 -2 만큼 베기 & 비료 옮기기
    new_pos = []
    for i in range(n):
        for j in range(n):
            if pos_arr[i][j] == 0 and arr[i][j] >= 2:
                pos_arr[i][j] = 1
                new_pos.append((i,j))
                arr[i][j] -= 2
    
    for i, j in pos:
        pos_arr[i][j] = 0
    
    pos = new_pos


total = 0
for i in range(n):
    total += sum(arr[i])

print(total)

