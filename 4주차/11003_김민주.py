import sys
import heapq

# pypy3로 풂
# 우큐에서 값뿐아니라 인덱스 가지고 판단해야할 때 풀이법

N, L = map(int, sys.stdin.readline().split())

arr = list(map(int,sys.stdin.readline().split()))

answer = []
pq = []

for i in range(len(arr)):
    #힙의 최솟값 중에 이미 지나간 인덱스 있다면 pop
    while pq and pq[0][1]<i-L+1:
        heapq.heappop(pq)

    heapq.heappush(pq, (arr[i], i))
    print(pq[0][0], end=' ')
