N = int(input())
A = list(map(int, input().split()))

dp_inc = [0]*N # 증가하는 수열
dp_dec = [0]*N # 감소하는 수열


# n위치에 대해 증가 수열 최대길이 구하기
def increase(n):
    if dp_inc[n] == 0:
        dp_inc[n] = 1
        # n 이전 위치들보다 n 위치 값이 더 큰 경우에 증가 조건에 부합하므로
        # 재귀적으로 최대값을 구한다.(top-down)
        for i in range(n):
            if A[i] < A[n]:
                dp_inc[n] = max(dp_inc[n], increase(i)+1)

    return dp_inc[n]


def decrease(n):
    if dp_dec[n] == 0:
        dp_dec[n] = 1
        # n 이후 위치들보다 n 위치 값이 더 큰 경우에 감소 조건에 부합하므로
        # 재귀적으로 최댓값을 구한다.
        for i in range(n+1, N):
            if A[n] > A[i]:
                dp_dec[n] = max(dp_dec[n], decrease(i)+1)

    return dp_dec[n]


for i in range(N):
    increase(i)
    decrease(i)

answer = -1
for i in range(N):
    answer = max(answer, dp_inc[i]+dp_dec[i])

print(answer-1) # 자기 자신이 두번 카운트되므로 1 빼준다.
