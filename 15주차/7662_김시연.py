"""
동기화용 list를 하나 만들어놓는것
그냥 계속 최소힙값에 -1붙여서 최대힙구성하고,
거기서 하나 뺀 다음에 다시 최소힙 구성하는거는 시간이 너무너무 오래걸림
최대힙이든 최소힙이든 같이 공유하는거는 operation의 idx임
그거로 pop여부를 알아내서 pop을 먼저 해주고 operation을 해줌으로서 동기화 가능
"""

import sys
from heapq import heappop, heappush, heapify

input = sys.stdin.readline

popped = []
que = []
que_max = []


def solution(c, n, i):
    if c == 'D' and que:
        if n == -1:
            # 우선순위큐의 최소값의 i -> popped[i]
            while que and popped[que[0][1]]:
                heappop(que)
            if que:
                idx = heappop(que)[1]
                popped[idx] = True

        elif n == 1:
            while que_max and popped[que_max[0][1]]:
                heappop(que_max)
            if que_max:
                idx = heappop(que_max)[1]
                popped[idx] = True

    elif c == "I":
        heappush(que, (n, i))
        heappush(que_max, (-n, i))


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        k = int(input())
        popped = [False for _ in range(k)]
        for i in range(k):
            c, n = map(str, input().split())
            solution(c, int(n), i)

        while que and popped[que[0][1]]:
            heappop(que)
        while que_max and popped[que_max[0][1]]:
            heappop(que_max)

        if not que:
            print("EMPTY")
        else:
            small = heappop(que)[0]
            big = -heappop(que_max)[0]
            print(big, small)

        que = []
        que_max = []
