"""
s를 t로 바꾸려면 매번 2가지 경우의수를 계산해야해서 이거 되나 싶었는데
생각을 뒤집어서 t를 s로 만든다면 해야하는 방법은 1가지 뿐.
맨뒤에 a가 있으면 a를 없애고, 맨앞이 b면 제거하고 뒤집으면되니까 ㅇㅇ
"""
import sys
input = sys.stdin.readline

S = input().rstrip()
T = input().rstrip()


def dfs(t):
    if t == S:
        print(1)
        sys.exit()

    if len(t) == 0:
        return 0

    if t[-1] == 'A':
        dfs(t[:-1])

    if t[0] == 'B':
        dfs(t[1:][::-1])


dfs(T)
print(0)
