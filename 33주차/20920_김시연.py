"""
빈도수 > 길이 > 사전순
최대 10만개 단어
"""
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
words = {}

for i in range(n):
    word = input().rstrip()
    if len(word) < m:
        continue
    else:
        if word in words:
            words[word] += 1
        else:
            words[word] = 1


# x[1]=빈도수, x[0]=단어
# -붙인게 내림차순
words = sorted(words.items(), key = lambda x : (-x[1], -len(x[0]), x[0]))

for i in words:
    print(i[0])

