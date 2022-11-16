from heapq import heappush, heappop
import sys
input = sys.stdin.readline
n, e = map(int, input().split())
s = [[] for i in range(n + 1)]
inf = sys.maxsize

for i in range(e):
    a, b, c = map(int, input().split())
    s[a].append([b, c])
    s[b].append([a, c])
v1, v2 = map(int, input().split())

def dijkstra(start):
    dp = [inf for i in range(n + 1)]
    dp[start] = 0
    heap = []
    heappush(heap, [0, start])
    while heap:
        w, c = heappop(heap)
        for n_n, n_w in s[c]:
            wei = n_w + w
            if dp[n_n] > wei:
                dp[n_n] = wei
                heappush(heap, [wei, n_n])
    return dp
one = dijkstra(1)
v1_ = dijkstra(v1)
v2_ = dijkstra(v2)
cnt = min(one[v1] + v1_[v2] + v2_[n], one[v2] + v2_[v1] + v1_[n])
print(cnt if cnt < inf else -1)