from collections import deque

M, N = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]
visited = [[0 for _ in range(M)] for _ in range(N)]

dx = [-1,1,0,0]
dy = [0,0,-1,1]


def bfs():
    q = deque()
    #익은 토마토 있는 칸 모두 넣어준다
    #외부에서 반복문 돌려서 따로따로 넣으면 토마토 익는 날짜 최소값 확인을 따로해줘야 하지 않을까?
    for i in range(N):
        for j in range(M):
            if arr[i][j] == 1:
                q.append((i,j))
                visited[i][j] = 1

    # visited 배열을 익은 날 배열로 사용한다.
    while q:
        x,y = q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<M and not visited[nx][ny]:
                if arr[nx][ny] == 0:
                    q.append((nx,ny))
                    visited[nx][ny] = visited[x][y]+1 # 하루지나서 익으니까 x,y보다 하루 더 up
                    arr[nx][ny] = 1 # 토마토 익혀준다

    # 다 익지 못한 게 있나 확인해준다
    for i in range(N):
        if 0 in arr[i]:
            return -1

    # 최대값 구하는데 1빼주는 이유 : 시작일은 0일인데 visited True, False 구분을 위해 1일부터 시작했기 때문
    return max(map(max, visited))-1

print(bfs())