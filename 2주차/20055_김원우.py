import sys

input = sys.stdin.readline
from collections import deque

n, k = map(int, input().split())
belt = deque(list(map(int, input().split())))
robot = deque([0] * n)
res = 0

while 1:
    belt.rotate(1)
    robot.rotate(1)
    robot[-1] = 0  # 로봇이 내려가는 부분이니 0

    # 로봇 전진
    if sum(robot):  # 로봇이 존재하면
        for i in range(n - 2, -1, -1):  # 로봇 내려가는 부분 인덱스 i-1 이므로 그 전인 i-2부터
            if robot[i] == 1 and robot[i + 1] == 0 and belt[i + 1] >= 1:
                # 1보 전진
                robot[i + 1] = 1
                robot[i] = 0
                # 내구도 하락
                belt[i + 1] -= 1
        robot[-1] = 0  # 이 부분도 로봇 out -> 0임

    # 로봇 올리기
    if robot[0] == 0 and belt[0] >= 1:
        robot[0] = 1
        belt[0] -= 1

    # 단계 증가시키기
    res += 1

    # 내구도 칸수 확인, k개 이상이라면 break
    if belt.count(0) >= k:
        break

print(res)