"""
문자열을 stack에 집어넣고 하나씩 꺼냄
1)stack 맨뒤에 같은게 있는지 확인(바로붙어있는 쌍)
2)아니라면 맨앞을 확인하고 빼기(감싸는 형태의 쌍)
-> 이렇게 하니까 안됐음. 가장 중심부에 있는 쌍부터 없애는 식으로 변경했더니 됨. 이유는 모르겠음...
"""
import sys
input = sys.stdin.readline
from collections import deque

n = int(input())
words = [list(input().rstrip()) for _ in range(n)]
answer = 0

for word in words:
    stack = []
    while word:
        now = word.pop()

        # 스택이 비어있으면 넣어주기
        if not stack:
            stack.append(now)
        #이미 스택이 무언가 있다면 가장 최근값이랑 비교하기
        else:
            if stack[-1] == now:
                stack.pop()
            else:
                stack.append(now)

    if not stack:
        answer += 1

print(answer)
