import sys

input = sys.stdin.readline

N,K = map(int, input().split())
words_alpha = []

for _ in range(N):
    word = input().rstrip()
    words_alpha.append(set(list(word)))


visited = [0]*26
answer = 0


def dfs(start, cnt):
    global answer

    if cnt == K:
        count = 0
        for word_set in words_alpha:
            flag = True
            for j in word_set:
                if not visited[ord(j)-ord('a')]:
                    flag = False
                    break
            if flag:
                count += 1

        answer = max(count, answer)
        return

    # 야구공문제와 다르게 순서가 상관 없어서(종류만) start가 있어야 하는듯(=치킨배달)
    for i in range(start, 26):
        if visited[i]:
            continue
        visited[i] = 1
        dfs(i+1, cnt+1)
        visited[i] = 0


ord_a = ord('a')

# 조건 나누지 않고 dfs하면 시간 초과
# 문제에 있는 조건들을 잘 활용하자
if K>=5:
    visited[0] = 1
    visited[ord('n')-ord_a] = 1
    visited[ord('t')-ord_a] = 1
    visited[ord('i')-ord_a] = 1
    visited[ord('c')-ord_a] = 1

    dfs(0, 5)
    print(answer)
else:
    print(answer)

