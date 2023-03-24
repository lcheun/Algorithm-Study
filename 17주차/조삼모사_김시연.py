"""
그냥 최소를 구하는게 아니라, 아침과 저녁간의 강도 차이를 최소값으로 구하는거임
어떤 업무를 아침에 골라서 할지를 재귀식으로 구현해야하나보다 -> 딱히 가지치기 용도 아님
시간복잡도도 딱히 생각할 필요 없는듯
"""
import sys

input = sys.stdin.readline
INF = sys.maxsize

n = int(input())
work = [[] for _ in range(n + 1)]
for i in range(1, n+1):
    work[i].append(0)
    work[i].extend(list(map(int, input().split())))

morning = []
answer = INF


def calculate(list):
    weight = 0
    for x in range(0, len(list)-1):
        for y in range(x+1, len(list)):
            i, j = list[x], list[y]
            weight += work[i][j] + work[j][i]
    return weight


def makeNight(morning):
    night = []
    for num in range(1, n + 1):
        if num not in morning:
            night.append(num)
    return night


def solution(morning, now):
    global answer
    if len(morning) == n // 2:
        night = makeNight(morning)
        weight_m = calculate(morning)
        weight_n = calculate(night)
        if answer > abs(weight_m - weight_n):
            answer = abs(weight_m - weight_n)
        return

    for num in range(now + 1, n + 1):
        morning.append(num)
        solution(morning, num)
        morning.remove(num)
    return


solution(morning, 0)
print(answer)
