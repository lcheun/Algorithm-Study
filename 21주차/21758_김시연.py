"""
무조건 벌통1개에 벌2마리고, 가장 최대가 나오는 장소를 찾기
벌-벌-벌통 / 벌-벌통-벌 / 벌통-벌-벌 3가지 방식이 존재
1번은 맨왼쪽에 벌1,맨오른쪽에 벌통 두고 중간 벌을 옮겨보기
2번은 벌2마리는 양쪽에 고정
3번은 벌통과 오른쪽벌이 양쪽에 고정됨
+ 누적합 써야할거같이 생김
"""
import sys

input = sys.stdin.readline

n = int(input())
honey = list(map(int, input().split()))
answer = 0

# 누적합 구해놓고 시작
sum = []
sum.append(honey[0])
for i in range(1, n):
    sum.append(sum[i - 1] + honey[i])

# 벌통 왼쪽
for i in range(1, n - 1):
    # 맨오른쪽벌이 모은 꿀 = sum[n-2]-honey[i]
    # 중간벌이 모은 꿀 = sum[i-1]
    answer = max(answer, sum[n - 2] - honey[i] + sum[i - 1])

# 벌통 오른쪽
for i in range(1, n - 1):
    answer = max(answer, sum[n - 1] - honey[0] - honey[i] + sum[n - 1] - sum[i])

# 벌통 중간
for i in range(1, n - 1):
    # n-2까지의 sum을 기반으로 해서 맨 오른쪽 벌 위치의 꿀 제외
    # 왼쪽 벌 위치의 꿀도 -honey[0]으로 제외
    # 벌통은 2번 방문되니까 한번 더 추가
    answer = max(answer, sum[n - 2] - honey[0] + honey[i])

print(answer)
