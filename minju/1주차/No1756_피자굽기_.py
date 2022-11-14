#O(n^2) : 시간 초과
import sys

D, N = map(int, input().split())
oven = list(map(int, input().split()))
pizza = list(map(int, input().split()))

# 오븐 크기를 조정해준다
# 위에 더 좁은 오븐이 있으면 어차피 더 큰 거는 무의미하기 때문에 위에 있는 오븐 중 최소 너비로 조정
for i in range(1, len(oven)):
    oven[i] = min(oven[i], oven[i-1])

idx = 0
depth = D-1
#오븐 밑에서부터 피자를 쌓아준다.
for i in range(D-1, -1, -1):
    if idx>=N:
        print(depth+1)
        sys.exit(0)
    if oven[i]>=pizza[idx]:
        idx+=1
        depth = i

print(0)