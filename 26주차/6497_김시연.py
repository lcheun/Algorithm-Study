"""
그래프문제이고, 도로들 중 모든 집을 연결할 수 있으면서 가장 절약가능한 사이클 없는 그래프를 찾는거니까
mst문제임
prim하고 kruskal이 있는데, union-find 쓰는 크루스칼 형태로 풀어보자
크루스칼: 간선을 오름차순 정렬하고, n-1개 선택될때까지 사이클 형성 안하는 한해서 작은순으로 연결
"""
import sys
input = sys.stdin.readline


def find(a):
    if a == parent[a]:
        return a
    parent[a] = find(parent[a])
    return parent[a]


def union(a, b):
    a = find(a)
    b = find(b)
    if a > b:
        parent[a] = b
    else:
        parent[b] = a


while True:
    # 0 0 이면 종료
    m, n = map(int, input().split())
    if m == 0 and n == 0:
        break

    # 테스트케이스마다 여러개의 길정보가 존재함
    edge = []
    parent = [i for i in range(m+1)]
    ans = 0

    for i in range(n):
        x, y, z = map(int, input().split())
        edge.append((x, y, z))

    # 가중치 작은순으로 정렬
    edge.sort(key=lambda x:x[2])

    # 입력받은 길들을 기반으로 트리 찾기
    for i in edge:
        x, y, z = i
        if find(x) != find(y):
            union(x, y)
        else:
            ans += z

    # 출력
    print(ans)