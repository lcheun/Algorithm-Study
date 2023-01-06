import sys

input = sys.stdin.readline

N,K = map(int, input().split())
words_alpha = []

for _ in range(N):
    word = input().rstrip()
    words_alpha.append(set(list(word))) #알파벳 종류만 알면되니까 set으로 변환하여 저장


visited = [0]*26
answer = 0


def dfs(start, cnt):
    global answer
    
    #요구하는 개수만큼 알파벳배움
    if cnt == K:
        count = 0
        for word_set in words_alpha: #word_set이 한 단어
            flag = True
            for j in word_set:
                if not visited[ord(j)-ord('a')]: #word_set(한단어의 알파벳들의 집합)에 있는 알파벳을 배우지 않은 경우
                    flag = False
                    break
            if flag: #True면 단어를 아는 상태
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

