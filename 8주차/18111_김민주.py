import sys

input = sys.stdin.readline

N, M, B = map(int, input().rstrip().split())
arr = [list(map(int, input().rstrip().split())) for _ in range(N)]

min_h = min(map(min, arr)) #높이 범위 최소
max_h = max(map(max, arr)) #높이 범위 최대

ans_time = sys.maxsize
ans_h = 0

# 첨에는 방문 순서에 따라 인벤토리에 있는 블록 개수가 달라지니까 방문 순서부터 dfs 로 구해줘야 된다고 생각했는데(시간 초과)
# 그냥 마지막에 총 개수로만 되는지 안 되는지 따져주면 된다.
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