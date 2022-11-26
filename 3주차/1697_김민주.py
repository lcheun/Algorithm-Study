from collections import deque

N,K = map(int, input().split())

visited = [0]*100001

#bfs 사용하여 풀이
# X-1 / X+1 / 2X에 대해 탐색해준다.
def bfs():
    q = deque()
    q.append(N)
    visited[N] = 1

    while q:
        now = q.popleft()
        if now == K:
            return visited[now] - 1

        # X-1
        if 0<=now-1<100001 and not visited[now-1]:
            visited[now-1] = visited[now] + 1
            q.append(now-1)

        #X+1
        if 0<=now+1<100001 and not visited[now+1]:
            visited[now+1] = visited[now] + 1
            q.append(now+1)

        # 2X
        if 0<=2*now<100001 and not visited[now*2]:
            visited[now*2] = visited[now] + 1
            q.append(now*2)


print(bfs())