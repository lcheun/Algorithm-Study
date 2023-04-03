import sys

input = sys.stdin.readline
n = int(input())

nums = list(map(int, input().strip().split()))
counts = list(map(int, input().strip().split())) #덧, 뺄, 곱
ops = []
for i in range(len(counts)):
    for j in range(counts[i]):
        if i==0:
            ops.append(0)
        elif i==1:
            ops.append(1)
        else:
            ops.append(2)

#print(ops)

min_val = sys.maxsize
max_val = -sys.maxsize

visited = [0 for _ in range(n-1)]

def dfs(depth, num):
    global min_val, max_val
    
    if depth == n-1:
        min_val = min(min_val, num)
        max_val = max(max_val, num)
        return

    for i in range(len(ops)):
        if not visited[i]:
            visited[i] = 1
            if ops[i]==0:
                dfs(depth+1, num+nums[depth+1])
            if ops[i]==1:
                dfs(depth+1, num-nums[depth+1])
            if ops[i]==2:
                dfs(depth+1, num*nums[depth+1])
            visited[i] = 0

dfs(0, nums[0])
print(min_val, max_val)
