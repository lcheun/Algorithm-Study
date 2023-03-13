import sys, math, heapq

# 전체 요소 연결했을 때 최단거리를 찾는 것 : 최소 스패닝 트리
# 프림 알고리즘 사용
# 정점 기준 알고리즘 -> 간선이 많을 때 사용하기 좋다
# 현재 그래프에서 가장 짧은 간선을 선택하고 그 정점에 방문하지 않은 경우 정점 방문

# 임의의 정점을 선택
# 해당 정점에서 갈 수 있는 간선을 minheap에 넣는다.
# 최소값을 뽑아 해당 정점을 방문 안했다면 선택한다.
input = sys.stdin.readline
n = int(input())
INF = sys.maxsize

graph = [[] for _ in range(n)]

arr = []
for _ in range(n):
    x, y = map(float, input().strip().split())
    arr.append((x,y))

for i in range(n):
    for j in range(i+1, n):
        dis = math.sqrt((arr[i][0]-arr[j][0])**2+(arr[i][1]-arr[j][1])**2)
        graph[i].append((dis, j))
        graph[j].append((dis, i))

pq = [[0, 0]] #시작 정점 0
visited = [0 for _ in range(n)]
answer = 0
count = 0

while pq:
    if count==n:
        break

    dis, v = heapq.heappop(pq)
    if not visited[v]:
        visited[v] = 1
        answer += dis
        count += 1
        for i in graph[v]:
            heapq.heappush(pq, i)


print(int(answer*100)/100)