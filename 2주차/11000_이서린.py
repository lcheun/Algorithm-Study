#우선 순위 큐 = 힙큐가 핵심. 힙큐 잘 몰라서 복습할 예정
#반복적인 input은 시간 초과가 나므로 sys.stdin.readline() 이용
#sys를 쓰더라도 heapq를 쓰지 않으면 시간 초과.
#heapq는 시간 복잡도 O(logN), sort는 시간 복잡도 O(NlogN) 

#모범답안========================
import heapq
import sys

N=int(input()) #여기 한 줄은 input okay.
stlist=[]
for n in range(N):
    s,t=map(int, sys.stdin.readline().split())
    stlist.append([int(s),int(t)])

stlist.sort()
lect=[]
heapq.heappush(lect,stlist[0][1])

for i in range(1,N):
    if stlist[i][0]<lect[0]:
        heapq.heappush(lect,stlist[i][1])
    else:
        heapq.heappop(lect)
        heapq.heappush(lect,stlist[i][1])

print(len(lect))
#print(lect)

#==========================================================================#
# #sys를 쓰더라도 heapq를 쓰지 않으면 시간 초과.
# #heapq는 시간 복잡도 O(logN), sort는 시간 복잡도 O(NlogN) 
# import heapq
# import sys

# N=int(input())
# stlist=[]
# for n in range(N):
#     s,t=sys.stdin.readline().split()
#     #s,t=map(int, sys.stdin.readline().split())
#     stlist.append([int(s),int(t)])

# stlist.sort()
# lect=[]
# lect.append(stlist[0][1])

# for i in range(1,N):
#     if stlist[i][0]<lect[0]:
#         lect.append(stlist[i][1])
#         lect.sort()
 
#     else:
#         lect.pop(0)
#         lect.append(stlist[i][1])
#         lect.sort()

# print(len(lect))
# #print(lect)

