#DFS로 풀이

import sys

def dfs(node):
    for n in graph[node]:
        if check[n]==0:
            check[n]=check[node]+1
            dfs(n)
            
n=sys.stdin.readline()
graph=[[] for _ in range(n+1)]
s, e = map(int, sys.stdin.readline().split())
for _ in range(int(input())):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)
check=[0]*(n+1)
dfs(s)
print(check[e] if check[e]>0 else -1)