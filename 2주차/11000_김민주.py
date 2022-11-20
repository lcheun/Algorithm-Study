import heapq

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]

arr.sort(key = lambda x:x[0]) # 시작순서 빠른대로 정렬
# print(arr)

pq = []
heapq.heappush(pq, arr[0][1])

count = 0
for i in range(1, N):
    if pq:
        #이어서 수업할 수 있는 경우
        if pq[0]<=arr[i][0]:
            heapq.heappop(pq)
            heapq.heappush(pq, arr[i][1])
        else:
            heapq.heappush(pq, arr[i][1])
    else:
        heapq.heappush(pq, arr[i][1])

    count = max(count, len(pq))


print(count)