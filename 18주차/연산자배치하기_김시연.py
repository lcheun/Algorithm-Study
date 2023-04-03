"""
연산자 순서 생각할 필요 없음
각 순서마다 덧셈 뺄셈 곱셈을 할지를 백트래킹으로 진행
"""
import sys
input = sys.stdin.readline
INF = sys.maxsize

n = int(input())
nums = list(map(int, input().split()))
operators = list(map(int, input().split()))
big, small = -INF, INF


def solution(idx, total):
    global big
    global small

    if idx == n - 1:
        small = min(total, small)
        big = max(total, big)
        return

    if operators[0]:
        operators[0] -= 1
        solution(idx + 1, total + nums[idx + 1])
        operators[0] += 1
    if operators[1]:
        operators[1] -= 1
        solution(idx + 1, total - nums[idx + 1])
        operators[1] += 1
    if operators[2]:
        operators[2] -= 1
        solution(idx + 1, total * nums[idx + 1])
        operators[2] += 1
    return


if __name__ == "__main__":
    solution(0, nums[0])
    print(big, small)
