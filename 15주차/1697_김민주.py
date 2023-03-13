import sys
from collections import deque

input = sys.stdin.readline

N, K = map(int, input().split())

# 100001로 안하고 N, K 중 max 사이즈로 하면 틀린다.
visited = [0 for _ in range(100001)]
def bfs():
    q = deque()
    q.append(N)
    visited[N] = 1

    while q:
        now = q.popleft()
        if now==K:
            return visited[now]

        # now-1
        if 0<=now-1<100001 and not visited[now-1]:
            q.append(now-1)
            visited[now-1] = visited[now]+1
        # now+1
        if 0<=now+1<100001 and not visited[now+1]:
            q.append(now+1)
            visited[now+1] = visited[now]+1
        # 2*now
        if 0<=2*now<100001 and not visited[2*now]:
            q.append(2*now)
            visited[2*now] = visited[now]+1

print(bfs()-1)

