import sys

input = sys.stdin.readline

N, M, B = map(int, input().rstrip().split())
arr = [list(map(int, input().rstrip().split())) for _ in range(N)]

min_h = min(map(min, arr)) #높이 범위 최소
max_h = max(map(max, arr)) #높이 범위 최대

ans_time = sys.maxsize
ans_h = 0

for h in range(min_h, max_h+1):
    minus = 0
    plus = 0
    for i in range(N):
        for j in range(M):
            if arr[i][j] > h:
                plus += arr[i][j] - h
            else:
                minus += h - arr[i][j]

    if minus > plus + B:
        continue

    time = plus * 2 + minus

    if ans_time >= time:
        ans_h = h
        ans_time = time

print(ans_time, ans_h)
