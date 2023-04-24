"""
레이저는 인접한 괄호쌍! 딱 () 이렇게 생긴거
그 외의 괄호는 쇠막대기를 상징함
레이저가 나올때마다, 해당 레이저로 몇개의 조각이 생겼는지 확인해서 더해주기
백준 돌리는데 오조오억년 걸려서 순간 오류난줄 알았음
"""
import sys

input = sys.stdin.readline

answer = 0
data = list(input().rstrip())
metal = []


def solution():
    global answer, data, metal
    while data:
        now = data.pop()

        if now == ")":
            if data[-1] == "(":
                data.pop()
                if metal:
                    answer += len(metal)
            else:
                metal.append(now)

        else:
            metal.pop()
            answer += 1


solution()
print(answer)
