import sys

# 플로이드워셜
input = sys.stdin.readline
n, m = map(int, input().rstrip().split())

INF = sys.maxsize
graph = [[INF]*(n+1) for _ in range(n+1)]
path = [[0]*(n+1) for _ in range(n+1)]

for i in range(m):
    a, b, c = map(int, input().rstrip().split())
    graph[a][b] = c
    graph[b][a] = c
    path[a][b] = b
    path[b][a] = a

for i in range(1,n+1):
    graph[i][i] = 0

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            new_cost = graph[i][k]+graph[k][j]
            if new_cost < graph[i][j]:
                graph[i][j] = new_cost
                path[i][j] = path[i][k] # 출발점에서 가장 앞의 집하장을 저장해주기 위해 앞부분의 집하장 저장


for i in path[1:]:
    for j in i[1:]:
        if j==0:
            print('-', end=' ')
        else:
            print(j, end=' ')
    print()