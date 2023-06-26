import sys
from heapq import heappop, heappush

input = sys.stdin.readline
N = int(input())

time = []
for _ in range(N):
    s, e = map(int, input().strip().split())

    time.append((s,e))

time.sort()

max_val = 0
now_use = [time[0][1]]

for i in range(1, N):
    while now_use and now_use[0]<=time[i][0]:
        heappop(now_use)

    heappush(now_use, time[i][1])
    max_val = max(max_val, len(now_use))

print(max_val)