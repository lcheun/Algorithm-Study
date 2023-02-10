N, M = map(int, input().split())
r, c, d = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

dir = [(-1,0), (0,1), (1,0), (0,-1)] # 북, 동, 남, 서
#왼쪽 : 인덱스 -1

count = 1
visited = [[0]*M for _ in range(N)]
visited[r][c] = 1

while True:
    flag = False

    for _ in range(4):
        d = (d-1)%4
        nx = r+dir[d][0]
        ny = c+dir[d][1]

        if 0<=nx<N and 0<=ny<M and not visited[nx][ny] and arr[nx][ny] == 0:
            visited[nx][ny] = 1
            count += 1
            r, c = nx, ny
            flag = True
            break

    if not flag:
        if arr[r-dir[d][0]][c-dir[d][1]]==1:
            print(count)
            break
        else:
            r = r-dir[d][0]
            c = c-dir[d][1]

