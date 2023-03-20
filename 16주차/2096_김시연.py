"""
최대값, 최소값을 찾아야하는데 탐색도 해야하니까 dp인거같긴함
근데 그냥은 메모리초과가 나버려서 결국 검색함 -> 슬라이딩 윈도우 사용해야함
즉, 모든 라인 다 받아놓고 하지 말고 한줄한줄 받아오면서 처리하고, dp 배열 갱신해줘야한다는 소리임
"""

import sys
input = sys.stdin.readline


n = int(input())
line = list(map(int, input().split()))
max_dp = line
min_dp = line

for _ in range(n-1):
    line = list(map(int, input().split()))

    max1 = line[0] + max(max_dp[0], max_dp[1])
    max2 = line[1] + max(max_dp)
    max3 = line[2] + max(max_dp[1], max_dp[2])

    min1 = line[0] + min(min_dp[0], min_dp[1])
    min2 = line[1] + min(min_dp)
    min3 = line[2] + min(min_dp[1], min_dp[2])

    max_dp = [max1, max2, max3]
    min_dp = [min1, min2, min3]

print(max(max_dp), min(min_dp))
