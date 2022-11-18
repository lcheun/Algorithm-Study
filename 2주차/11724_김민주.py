from collections import deque

N, M = map(int, input().split())

arr = [[] for _ in range(N+1)]
for _ in range(M):
    u, v = map(int, input().split())
    arr[u].append(v)
    arr[v].append(u)

visited = [0 for _ in range(N+1)]

def bfs(start):
    q = deque()
    q.append(start)

    visited[start] = 1

    while q:
        now = q.popleft()

        for next in arr[now]:
            if not visited[next]:
                visited[next] = 1
                q.append(next)


count = 0
for i in range(1, N+1):
    if not visited[i]:
        bfs(i)
        count += 1

print(count)