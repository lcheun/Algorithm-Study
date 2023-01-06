import sys

input = sys.stdin.readline

n = int(input())
note = input()

dx = [1, 0, -1, 0] #남, 서, 북, 동
dy = [0, -1, 0, 1]
dir = 0

move = []

x, y = 0, 0
min_x, max_x = 0, 0 # 배열 행의 길이 계산 하기 위한 변수
min_y, max_y = 0, 0 # 배열 열의 길이 계산 하기 위한 변수

move.append((0,0))
for i in note:
    if i=='R': #오른쪽 회전
        dir = (dir+1)%4
    elif i=='L': #왼쪽 회전
        dir = (dir-1)%4
    elif i=='F': #이동
        x += dx[dir]
        y += dy[dir]
        max_x = max(max_x, x)
        min_x = min(min_x, x)
        max_y = max(max_y, y)
        min_y = min(min_y, y)
        move.append((x,y))

x_len = max_x-min_x+1
y_len = max_y-min_y+1
result = [['#']*y_len for _ in range(x_len)]
for x, y in move:
    result[x-min_x][y-min_y] = '.'

for i in range(x_len):
    for j in range(y_len):
        print(result[i][j],end='')
    print()