import sys
import heapq

input = sys.stdin.readline
N = int(input())
right_q = [] # 중간값보다 작은 값들 -> 최대힙
left_q = [] # 중간값보다 큰 값들 -> 최소힙
answer = []

for i in range(N):
    num = int(input())
    # 길이 같으면 left_q에 넣음
    # ..'.' / .. 가 되도록 (위치 상 left_q의 루트를 중간값으로 만든다)
    if len(left_q) == len(right_q):
        heapq.heappush(left_q, (-num, num))
    # 길이 다르면 right_q에 넣음
    # ..'.' / ... 가 되도록
    else:
        heapq.heappush(right_q, (num, num))

    # left_q에서 가장 큰값이 right_q에서 가장 작은값보다 더 크다면?
    # 중간값보다 큰 값이 left_q에 들어가 있는 것
    if right_q and left_q[0][1] > right_q[0][1]:
        min = heapq.heappop(right_q)[1]
        max = heapq.heappop(left_q)[1]

        heapq.heappush(left_q, (-min, min))
        heapq.heappush(right_q, (max, max))

    answer.append(left_q[0][1])

for i in answer:
    print(i)