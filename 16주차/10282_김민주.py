import sys
from heapq import heappop, heappush

# 의존 하면 감염
# 시작점(c)에서부터 갈 수 있는 곳을 최단거리로 가는 거기 때문에 다익스트라라고 생각

input = sys.stdin.readline
T = int(input())

INF = sys.maxsize


def dijkstra(start):
    dis_list = [INF for _ in range(n + 1)]
    pq = []
    heappush(pq, (0, start))
    dis_list[start] = 0
    end = 0
    count = 1

    while pq:
        cost, node = heappop(pq)

        if cost > dis_list[node]:
            continue

        end = node # 마지막 노드는 현재 방문한 노드로 담아야 한다.
        for next_cost, next_node in connect[node]:
            if cost + next_cost < dis_list[next_node]:
                dis_list[next_node] = cost + next_cost
                heappush(pq, (dis_list[next_node], next_node))
                #end = next_node pq에 들어가기 전이기 때문에 마지막이 아닐수도 있는 거 같다??

    count = len(dis_list)-dis_list.count(INF) # 방문한 개수를 세어준다(INF인경우에는 미방문)
    return count, dis_list[end]


for _ in range(T):
    n, d, c = map(int, input().split())
    connect = [[] for _ in range(n+1)]
    for _ in range(d):
        # 단방향연결
        a, b, s = map(int, input().split())
        connect[b].append((s, a))

    cnt, time = dijkstra(c)
    print(cnt, time)


