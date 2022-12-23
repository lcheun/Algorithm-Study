from collections import deque
import sys

L, M = map(int, sys.stdin.readline().split())
arr = map(int, sys.stdin.readline().split()
dq = deque()
for i, k in enumerate(arr):
    while dq and dq[0][0]<=i-M:
        dq.popleft()
    while dq and dq[-1][1]>=k:
        dq.pop()
    dq.append((i,k))
    print(dq[0][1], end=' ')