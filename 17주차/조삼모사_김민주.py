import sys

input = sys.stdin.readline
n = int(input())
arr = [list(map(int, input().strip().split())) for _ in range(n)]

visited = [0 for _ in range(n)]

# 아침을 기준으로 pick
answer = sys.maxsize
def dfs(depth, start):
    global answer
    if depth==n//2:
        morning, evening = calc()
        answer = min(answer, abs(morning-evening))
        return

    for i in range(start, n):
        if not visited[i]:
            visited[i] = 1
            dfs(depth+1, i+1)
            visited[i] = 0

# 값 계산 -> 이중 포문
def calc():
    morn = []
    even = []

    for i in range(len(visited)):
        if visited[i]:
            morn.append(i)
        else:
            even.append(i)

    morning, evening = 0, 0
    for i in range(len(morn)):
        for j in range(len(morn)):
            if i!=j:
                morning += arr[morn[i]][morn[j]]
        
    for i in range(len(even)):
        for j in range(len(even)):
            if i!=j:
                evening += arr[even[i]][even[j]]


    return morning, evening


dfs(0, 0)
print(answer)
