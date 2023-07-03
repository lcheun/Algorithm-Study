import sys

input = sys.stdin.readline

N, K = map(int, input().split())

visited = [0]*26
answer = 0

words = []

# 입력받은 단어에 들어가는 알파벳 종류 저장
for _ in range(N):
    word = input().strip()
    words.append((set(list(word))))


# 알파벳 가르쳤을 때 가르칠 수 있는 최대 단어 수 구하기
def dfs(start, depth):
    global answer
    # 알파벳 K개 가르침
    if depth==K:
        count = 0 # K개 이 조합으로 가르쳤을 때 가르칠 수 있는 단어 수
        for alp in words:
            flag = True
            for al in alp:
                if not visited[ord(al)-ord('a')]:
                    flag = False
                    break
            if flag:
                count += 1

        answer = max(answer, count)
        return

    for i in range(start, 26):
        if not visited[i]:
            visited[i] = 1
            dfs(i+1, depth+1)
            visited[i] = 0


# a, n, t, i, c
if K>=5:
    visited[ord('a')-ord('a')] = 1
    visited[ord('n')-ord('a')] = 1
    visited[ord('t')-ord('a')] = 1
    visited[ord('i')-ord('a')] = 1
    visited[ord('c')-ord('a')] = 1

    dfs(0, 5)

print(answer)