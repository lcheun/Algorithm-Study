import sys

R, C = map(int, sys.stdin.readline().split())
arr = [list(sys.stdin.readline().rstrip()) for _ in range(R)]
visited = [0]*26

# chr(숫자) : ascii -> alpha
# ord(문자) : alpha -> ascii
# 'A' : 65

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

answer = 0


def calc_ascii(letter):
    asc = ord(letter)-65
    return asc

#파라미터 : 지금 탐색할 위치(x,y) , 지금까지 안 끊어지고 온 횟수
def dfs(x, y, count):
    global answer
    answer = max(answer, count)

    for i in range(4):
        nx, ny = x+dx[i], y+dy[i]
        if 0<=nx<R and 0<=ny<C:
            asc = calc_ascii(arr[nx][ny])
            if not visited[asc]:
                visited[asc] = 1
                dfs(nx, ny, count+1)
                visited[asc] = 0 #백트래킹


visited[calc_ascii(arr[0][0])] = 1
dfs(0,0,1)
print(answer)
