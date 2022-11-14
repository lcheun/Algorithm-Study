import heapq
import sys

input = sys.stdin.readline
N, E = map(int, input().split())
arr = [[] for _ in range(N+1)]

for _ in range(E):
    a, b, c = map(int, input().split())

    arr[a].append((c,b))
    arr[b].append((c,a))

spot1, spot2 = map(int, input().split())

INF = sys.maxsize
def dijkstra(start, end):
    dis_list = [INF for _ in range(N+1)] # 시작 노드 정보 우선순위 큐에 삽입
    dis_list[start] = 0 # 시작노드 -> 시작노드 거리 기록
    pq = []
    heapq.heappush(pq, [0, start])

    while pq:
        dis, node = heapq.heappop(pq)

        #큐에서 뽑아낸 거리가 이미 갱신된 거리보다 클 경우 무시(=방문한 셈)
        if dis_list[node]<dis:
            continue

        #큐에서 뽑아낸 노드와 연결된 인접노드들 탐색
        for next_cost, next_node in arr[node]:
            if dis_list[next_node] > dis_list[node] + next_cost: # 시작 -> node거리 + node->next_node(인접노드)의 거리
                dis_list[next_node] = dis_list[node] + next_cost
                heapq.heappush(pq, [dis_list[next_node], next_node])

    return dis_list[end]

path1 = dijkstra(1, spot1) + dijkstra(spot1, spot2) + dijkstra(spot2, N)
path2 = dijkstra(1, spot2) + dijkstra(spot2, spot1) + dijkstra(spot1, N)

if path1>=INF and path2>=INF:
    print(-1)
else:
    print(min(path1, path2))