# 유니온 파인드
# 크루스칼
# 최소 신장 트리(최소 스패닝 트리)

# find 함수 : parent를 찾아준다.
def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])

    return parent[x]

# union 함수 : 합집합을 만들어준다. (스패닝 트리에 포함, 연결 시키는 것)
def union(parent, a, b):
    a = find(parent, a)
    b = find(parent, b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b


N, M = map(int, input().split())
connects = []
parent = [i for i in range(N+1)]

for i in range(M):
    a, b, c = map(int, input().split())
    connects.append((a,b,c))

# 가중치를 기준으로 정렬한다.
connects.sort(key=lambda x:x[2])

answer = 0
biggest = 0 # 최소 스패닝 트리에서 가장 큰 간선을 빼서 마을을 2개로 분리함

for a, b, c in connects:
    # 사이클이 발생하지 않는다면 트리에 포함시키고 비용 업데이트
    if find(parent, a) != find(parent, b):
        union(parent, a, b)
        answer += c
        biggest = c

print(answer-biggest)