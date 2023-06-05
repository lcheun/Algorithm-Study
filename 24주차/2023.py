import math

# 백트래킹

N = int(input())

answer = []

# 소수 판별
def check(num):
    # 제곱근까지 -> 시간복잡도 : O(n^0.5)
    for i in range(2, int(math.sqrt(num))+1):
        if num%i==0:
            return False

    return True

# 백트래킹
def dfs(depth, num):
    if depth==N:
        answer.append(num)
        return

    # 소수를 구해야 하니까 홀수에 대해서만 진행해줌
    for i in range(1, 10, 2):
        # 소수인 경우에만 다음 재귀
        if check(num*10+i):
            dfs(depth+1, num*10+i)


# 소수에 대해서만
for i in [2, 3, 5, 7]:
    dfs(1, i)

for i in answer:
    print(i)