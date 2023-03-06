import sys

# 슬라이딩 윈도우
input = sys.stdin.readline

for _ in range(int(input())):
    v = list(input().strip())
    k = int(input())

    min_val = len(v)
    max_val = -1

    alpha = [[] for _ in range(26)] #알파벳 등장한 인덱스 담는 배열

    for idx, val in enumerate(v):
        val = ord(val)-97
        alpha[val].append(idx)

    for al in alpha:
        for i in range(len(al)-k+1):
            min_val = min(min_val, al[i+k-1]-al[i]+1)
            max_val = max(max_val, al[i+k-1]-al[i]+1)

    if max_val==-1:
        print(-1)
    else:
        print(min_val, max_val)