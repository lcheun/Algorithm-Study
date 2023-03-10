import sys
from collections import deque
input = sys.stdin.readline


def solution(n, k):
    answer = 100000
    visited = [-1 for _ in range(100001)]
    visited[n] = 0
    deq = deque()
    deq.append(n)

    while deq:
        now = deq.popleft()
        if now == k:
            answer = visited[now]

        n1 = now-1
        n2 = now+1
        n3 = now*2

        if visited[now] < answer:
            if n1 >= 0 and visited[n1] == -1:
                deq.append(n1)
                visited[n1] = visited[now] + 1

            if n2 <= 100000 and visited[n2] == -1:
                deq.append(n2)
                visited[n2] = visited[now] + 1

            if n3 <= 100000 and visited[n3] == -1:
                deq.append(n3)
                visited[n3] = visited[now] + 1

    return answer


if __name__ == '__main__':
    n, k = map(int, input().split())
    output = solution(n, k)
    print(output)
