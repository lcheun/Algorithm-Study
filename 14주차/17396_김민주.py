import sys
import heapq

# 다익스트라

input = sys.stdin.readline
N,M = map(int, input().split())

arr = list(map(int, input().strip().split()))
arr[-1] = 0 # 편의상 마지막 분기점을 0으로 바꿔준다.

INF = sys.maxsize

# 양방향 그래프 연결
connect = [[] for _ in range(N)]
for i in range(M):
    a, b, t = map(int, input().split())
    # 필요없음
    # if arr[b]:
    #     connect[a].append((INF, b))
    #     connect[b].append((INF, a))
    # else:
    connect[a].append((t, b))
    connect[b].append((t, a))


# 다익스트라(출발지와 도착지가 하나씩으로 정해져있고 최단 거리를 찾는 문제라 다익스트라 라고 생각했음)
def dijkstra(start, end):
    dis_list = [INF for _ in range(N)]
    dis_list[start] = 0

    pq = []
    heapq.heappush(pq, (0, start))

    while pq:
        dis, node = heapq.heappop(pq)
        #갱신된 게 이미 더 작을 경우에는 넘어감
        if dis > dis_list[node]:
            continue

        # 다음 노드의 거리가 새롭게 생긴 다음 노드의 거리보다 크고 /// 다음 노드가 방문할 수 있는 노드인 경우에 거리 업데이트하고 pq에 넣어줌
        for next_cost, next_node in connect[node]:
            if dis_list[next_node] > dis_list[node]+next_cost and not arr[next_node]:
                dis_list[next_node] = dis_list[node]+next_cost
                heapq.heappush(pq, (dis_list[next_node], next_node))

    #print(dis_list)
    return dis_list[end]

num = dijkstra(0, N-1)
if num==INF:
    print(-1)
else:
    print(num)