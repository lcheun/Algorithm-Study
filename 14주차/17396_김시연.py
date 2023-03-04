"""
롤창이 만든 문젠가 보다 ^^...
값이 0인 값만 탐색하면 될듯. 도착지는 무조건 1인데 그럼 풀기 어려우니까 0으로 바꾸자
이 문제는 가중치도 있음!!!! -> BFS말고 다익스트라로 풀자
"""

import sys
import heapq
input = sys.stdin.readline
INF = sys.maxsize


def solution(n, visible, graph):
    distance = [INF for _ in range(n)]
    distance[0] = 0

    queue = []
    heapq.heappush(queue, (0, 0))

    while queue:
        dist, node = heapq.heappop(queue)

        if distance[node] < dist:
            continue

        for next_node, next_weight in graph[node]:
            next_dist = dist + next_weight
            if distance[next_node] > next_dist and visible[next_node] == 0:
                distance[next_node] = next_dist
                heapq.heappush(queue, (next_dist, next_node))

    if distance[-1] == INF:
        return -1
    else:
        return distance[-1]


if __name__ == '__main__':
    n, v = map(int, input().split())
    visible = list(map(int, input().split()))
    visible[-1] = 0

    graph = {}
    for i in range(v):
        a, b, t = map(int, input().split())
        if a not in graph:
            graph[a] = []
        graph[a].append((b, t))

        if b not in graph:
            graph[b] = []
        graph[b].append((a, t))

    if 0 not in graph:
        print(-1)
    else:
        output = solution(n, visible, graph)
        print(output)
