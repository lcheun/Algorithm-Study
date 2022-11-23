#dfs

import sys
sys.setrecursionlimit(10000)

def dfs(v):
    visited[v] = True
    for e in adj[v]:
        if not visited[e]:
            dfs(e)
            
N, M = map(int, input().split())
adj = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)
count = 0

for _ in range(M):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)
    
for j in range(1, N + 1):
    if not visited[j]:
        dfs(j)
        count += 1

print(count)
#=====================================
#bfs
import sys
from collections import deque

input = sys.stdin.readline


def bfs(start):
    queue = deque([start])
    visited[start] = True
    while queue:
        node = queue.popleft()
        for i in graph[node]:
            if not visited[i]:
                visited[i] = True
                queue.append(i)


N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

# 방문처리
visited = [False] * (1 + N)
count = 0  # 컴포넌트 그래프 개수 저장

# 1~N번 노드를 각각돌면서
for i in range(1, N + 1):
    if not visited[i]:  # 만약 방문하지 않았다면
        if not graph[i]:  # 만약 그래프가 비어있다면
            count += 1  # 개수 1개 추가
            visited[i] = True  # 방문 처리
        else:  # 만약 그래프가 비어있지 않다면(어느 점과 연결된 점이 있다면)
            bfs(i)  # 해당 i를 시작노드로 bfs를 돈다.
            count += 1  # 연결요소 를 +1개 해준다.

print(count)


#======================================================================
# #시도

# import heapq
# import sys

# point,line=map(int, sys.stdin.readline().split())
# linelist=[]

# for i in range(line):
#     s,e=map(int, sys.stdin.readline().split())
#     linelist.append([min(s,e), max(s,e)])
#     # print(linelist)
# #_______________________________
# #linelist.sort()
# ele=[]
# ele.append([])
# ele[0].append(linelist[0][0])
# ele[0].append(linelist[0][1]) #ele=[[1,2]]
# pointlist=[]
# pointlist.append(linelist[0][0])
# pointlist.append(linelist[0][1]) #pointlist=[1,2]
# print(ele)
# print(pointlist)

# while len(pointlist)!=point:
#     for i in range(line):
#         for j in range(len(ele)):
#             if linelist[i][0] in ele[j] and linelist[i][1] in ele[j]:
#                 break
#             elif linelist[i][0] in ele[j]:
#                 ele[j].append(linelist[i][1])
#                 pointlist.append(linelist[i][1])
#                 print(pointlist)
#             elif linelist[i][1] in ele[j]:
#                 ele[j].append(linelist[i][0])
#                 pointlist.append(linelist[i][0])
#                 print(pointlist)
#             else:
#                 ele.append([])
#                 j+=1
#                 ele[j].append(linelist[i][0])
#                 ele[j].append(linelist[i][1])
#                 pointlist.append(linelist[i][0])
#                 pointlist.append(linelist[i][1])
#                 print(pointlist)

# # print(pointlist)
# # print(len(ele))
# # print(ele)







# # linelist.sort()
# # ele=[]
# # ele.append[[]]
# # ele[0].append(linelist[0][0])
# # ele[0].append(linelist[0][1])

# # #heapq.heappush(lect,stlist[0][1])
# # cnt=0
# # for i in range(1,line):
# #     if linelist[i][0] in ele[cnt]:
# #         heapq.heappush(ele,linelist[i][1])
# #     elif linelist[i][1] in ele[cnt]:
# #         heapq.heappush(ele,linelist[i][0])
# #     else:
# #         heapq.heappop(lect)
# #         heapq.heappush(lect,stlist[i][1])
# #         cnt+=1
# #         ele.append[[]]
# #         ele[cnt].append(linelist[i][0])
# #         ele[cnt].append(linelist[i][1])
# # print(len(lect))