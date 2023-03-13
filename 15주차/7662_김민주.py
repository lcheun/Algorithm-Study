import heapq, sys

input = sys.stdin.readline
T = int(input())

# 힙을 두개를 만들어 푼다
# 최소힙과 최대힙

# 두 힙에 원소가 모두 있는 경우에 삭제가 가능한데 (그렇지 않은 경우에는 이미 삭제된 원소)
# 처음에는 이를 while ... not in ... 으로 판단해줬는데 시간 초과!!!
# visited 배열을 만들어 삭제되지 않은 원소를 바로 알아낼 수 있게 바꾸니 정답
# 들어간 순서대로 id를 부여하고 처음에 push할 때 visited[id]를 1로 만들어서 두 큐 모두에 원소가 있음을 나타낸다.
# visited[id]가 0인 경우 이미 삭제된 원소로, while문을 돌면서 그런 원소가 없을 때까지 계속 pop해준다.

for _ in range(T):
    k = int(input())
    max_h = []
    min_h = []

    visited = [0 for _ in range(1000001)]

    for i in range(k):
        comm, num = input().strip().split()
        num = int(num)
        if comm=='I':
            heapq.heappush(max_h, (-num, i))
            heapq.heappush(min_h, (num, i))
            visited[i] = 1 #1이면 어떤 힙에서도 삭제가 안된 상태
        else:
            if num==-1:
                # 최댓값 제거에서 이미 제거된 경우
                while min_h and not visited[min_h[0][1]]:
                    heapq.heappop(min_h)
                if min_h:
                    visited[min_h[0][1]] = 0
                    heapq.heappop(min_h)
            else:
                while max_h and not visited[max_h[0][1]]:
                    heapq.heappop(max_h)
                if max_h:
                    visited[max_h[0][1]] = 0
                    heapq.heappop(max_h)

    while max_h and not visited[max_h[0][1]]:
        heapq.heappop(max_h)
    while min_h and not visited[min_h[0][1]]:
        heapq.heappop(min_h)

    if min_h and max_h:
        print(-max_h[0][0], min_h[0][0])
    else:
        print("EMPTY")