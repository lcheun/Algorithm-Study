import sys
input = sys.stdin.readline
from collections import deque

n,k = map(int,input().split())
ans = 0
belt = deque(map(int,input().split()))
robot = deque(list([0]*n))

while belt.count(0) < k:

    belt.rotate(1)
    robot.rotate(1)
    robot[-1] = 0
    if sum(robot) > 0 :
        for i in range(n-2,-1,-1):
            if robot[i] == 1 and robot[i+1] == 0 and belt[i+1]>=1:
                    robot[i+1] = 1 
                    robot[i] = 0 
                    belt[i+1] -= 1
        robot[-1] = 0
    if robot[0] == 0 and belt[0]>=1: 
        robot[0] = 1 
        belt[0] -= 1 
    ans += 1 
print(ans)