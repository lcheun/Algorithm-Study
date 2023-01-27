# 백트래킹 골4
N = int(input())

count = 0
visited = [0]*N #행별로 퀸이 어디 놓여 있나

def dfs(depth):
    global count

    if depth == N:
        count += 1
        return

    for i in range(N):
        visited[depth] = i
        if check(depth):
            dfs(depth+1)
        #visited[depth] = 0


def check(depth):
    for i in range(depth):
        #지금까지 채워진 애들 중에 같은 열에 들어있는 값이 있나?
        if visited[i]==visited[depth]:
            return False
        #대각선
        elif abs(i-depth) == abs(visited[i]-visited[depth]):
            return False
    return True


dfs(0)
print(count)