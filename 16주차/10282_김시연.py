"""
그래프 탐색 문제인듯
대신 의존성이 있으므로 일방향 그래프가 될듯함
그리고 감염되는데 걸리는 시간 s가 있으므로 가중치가 있는 그래프임
다익스트라로 풀어보자
"""
import sys
from heapq import heappush, heappop

input = sys.stdin.readline
inf = sys.maxsize


def dijkstra(start, dp, graph):
    heappush(heap, [0, start])
    dp[start] = 0
    while heap:
        w, n = heappop(heap)
        for n_n, wei in graph[n]:
            n_w = wei + w
            if n_w < dp[n_n]:
                dp[n_n] = n_w
                heappush(heap, [n_w, n_n])


t = int(input())
for _ in range(t):
    n, d, c = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    dp = [inf] * (n + 1)
    heap = []
    for _ in range(d):
        a, b, s = map(int, input().split())
        graph[b].append([a, s])

    dijkstra(c, dp, graph)

    cnt = 0
    ans = 0
    for i in dp:
        if i != inf:
            cnt += 1
            ans = max(ans, i)

    print(cnt, ans)
