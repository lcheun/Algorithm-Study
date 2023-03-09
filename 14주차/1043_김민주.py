import sys

input = sys.stdin.readline

#union find 유니온 파인드
N, M = map(int, input().split())

input_truth = list(map(int, input().strip().split()))
truth = set(input_truth[1:])
#truth = input_truth[1:]

party = []
for i in range(M):
    temp = list(map(int, input().strip().split()))
    party.append(temp)


def find(x, parent):
    if x!=parent[x]:
        parent[x] = find(parent[x], parent)

    return parent[x]


def union(a, b, parent):
    a = find(a, parent)
    b = find(b, parent)

    if a<b:
        parent[b] = a
    else:
        parent[a] = b


parent = [i for i in range(N+1)]
count = M

# 가장 작은 값을 기준으로 그룹핑 (굳이 가장 작은 값은 아니어도 됐었을 거 같기도..)
for i in range(M):
    arr = sorted(party[i][1:])
    #print(arr)
    p = arr[0]
    for j in range(1, len(arr)):
        #print(arr[j], arr[j+1])
        # 둘이 같은 그룹이 아니었다면 그룹으로 만들어줌
        if find(p, parent) != find(arr[j], parent):
            union(p, arr[j], parent)
        # 둘 중 하나가 진실을 알고 있는 사람이라면 둘다 truth에 넣어줬었는데 필요 없음(밑에서 전체에 대해서 하니까)
        # if arr[j] in truth or p in truth:
        #     truth.add(arr[j])
        #     truth.add(p)

# truth에 있는 원소와 같은 그룹이라면 truth에 넣어준다
visited = [0] * (N+1)
for i in range(1, N+1):
    if i in truth and not visited[i]:
        p = find(i, parent)
        for j in range(1, N+1):
            if find(j, parent)==p:
                visited[j] = 1
                truth.add(j)


# print(parent)
# print(truth)

for i in range(M):
    for j in range(1, party[i][0]+1):
        if party[i][j] in truth:
            count -= 1
            break

print(count)
