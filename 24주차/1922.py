from heapq import heappush, heappop

N = int(input())
M = int(input())

# 모든 컴퓨터 연결 = MST
connect = [[] for _ in range(N+1)]
for _ in range(M):
    a, b, c = map(int, input().split())
    connect[a].append((c, b))
    connect[b].append((c, a))

def prim():
    cnt, ans = 0, 0
    pq = []
    pq.append((0, 1))
    visited = [0 for _ in range(N+1)]

    while pq:
        if cnt == N:
            break

        c, v = heappop(pq)
        if not visited[v]:
            cnt += 1
            ans += c
            visited[v] = 1

            for i in connect[v]:
                heappush(pq, i)

    return ans

print(prim())