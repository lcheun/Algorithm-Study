"""
일단 한 색깔을 한쪽으로 모으기로 결정했다면 뒤쪽에 있는 애들을 먼저 옮겨서 색깔을 최대한 모아준 후에
앞쪽애를 한번에 넘겨주는게 무조건 이득인거는 알겠으나, 어떤 색깔을 어디로 옮길지도 그리디가 되는지 고민했는데
이거는 그냥 4가지 경우 모두 브루트포스적으로 해결하면 되는거였음
"""
import sys
input = sys.stdin.readline

n = int(input())
s = input().rstrip()
answers = []

# 빨강을 왼쪽으로
flag = False
cnt = 0
for i in range(n):
    if s[i] != 'R':
        flag = True
    else:
        if flag is True:
            cnt += 1
answers.append(cnt)

# 파랑을 왼쪽으로
flag = False
cnt = 0
for i in range(n):
    if s[i] != 'B':
        flag = True
    else:
        if flag is True:
            cnt += 1
answers.append(cnt)

# 빨강을 오른쪽으로
flag = False
cnt = 0
for i in reversed(range(n)):
    if s[i] != 'R':
        flag = True
    else:
        if flag is True:
            cnt += 1
answers.append(cnt)

# 파랑을 오른쪽으로
flag = False
cnt = 0
for i in reversed(range(n)):
    if s[i] != 'B':
        flag = True
    else:
        if flag is True:
            cnt += 1
answers.append(cnt)

print(min(answers))
