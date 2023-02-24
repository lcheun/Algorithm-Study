import sys
sys.setrecursionlimit(111111) #충분한 재귀 깊이를 주어 오류를 예방

input = sys.stdin.readline
T = int(input())

def dfs(x):
    global result
    visited[x] = 1
    cycle.append(x)

    next = arr[x]

    if visited[next]:
        if next in cycle:
            result+=cycle[cycle.index(next):]
        return
    else:
        dfs(next)


for _ in range(T):
    N = int(input())
    arr = [0] + list(map(int, input().split()))
    visited = [1]+[0]*N
    result = []

    for i in range(1, N+1):
        if not visited[i]:
            cycle = []
            dfs(i)

    print(N - len(result))