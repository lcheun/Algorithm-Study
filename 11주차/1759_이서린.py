import sys
input = sys.stdin.readline
def dfs(len, idx):
    if len == l:
        vo = 0
        co = 0
        for i in range(l):
            if arr[i] in 'aeiou': vo += 1
            else: co += 1
        if vo >= 1 and co >= 2:
            print(''.join(arr))
        return
    for i in range(idx, c):
        if check[i] == 0:
            arr.append(s[i])
            check[i] = 1
            dfs(len + 1, i + 1)
            check[i] = 0
            del arr[-1]
l, c = map(int, input().split())
check = [0 for i in range(c)]
arr = []
s = input().split()
s.sort()
dfs(0, 0)