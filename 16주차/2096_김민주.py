import sys
import copy

input = sys.stdin.readline
N = int(input())
arr = list(map(int, input().strip().split())) # 전체 배열을 다 받으면 메모리 초과 난다.

max_dp = [arr[0], arr[1], arr[2]]
min_dp = [arr[0], arr[1], arr[2]]

for i in range(1, N):
    a,b,c = map(int, input().split()) # 숫자 입력 한 줄 씩 받는다

    max1 = max(max_dp[0], max_dp[1])+a
    min1 = min(min_dp[0], min_dp[1])+a

    max2 = max(max_dp[0], max_dp[1], max_dp[2])+b
    min2 = min(min_dp[0], min_dp[1], min_dp[2])+b

    max3 = max(max_dp[1], max_dp[2])+c
    min3 = min(min_dp[1], min_dp[2])+c

    max_dp = [max1, max2, max3]
    min_dp = [min1, min2, min3]

print(max(max_dp), min(min_dp))