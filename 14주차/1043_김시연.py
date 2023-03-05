"""
사람이 노드, 파티가 연결고리인거같음
한동안 알고리즘 복습을 안해서 까먹고 있었는데 이거는 유니온파인드 문제였슴
하하 ^^;;
같은 파티에 참석했던 사람들을 계속해서 판별해서 알아내는것이 목적이니까 유니온 파인드
"""

import sys
input = sys.stdin.readline


def find_parent(f):
    # 본인이 parent인 경우
    if parent[f] < 0:
        return f

    # 본인이 parent가 아닌경우
    parent[f] = find_parent(parent[f])
    return parent[f]


def union(friend1, friend2):
    p1 = find_parent(friend1)
    p2 = find_parent(friend2)

    if p1 == p2:
        return

    if parent[p1] < parent[p2]:
        # 더하는 건 자식 수를 음수로 보여 주는 용도
        parent[p1] += parent[p2]
        parent[p2] = p1
    else:
        parent[p2] += parent[p1]
        parent[p1] = p2
    return


def count_party(party):
    cnt = 0

    for i in party:
        if find_parent(i) != find_parent(0):
            cnt += 1
    return cnt

# main():
n, m = map(int, input().split())
parent = [-1 for _ in range(n + 1)]
party = []

# 진실을 아는 사람들을 0번 node에 묶어서 팀으로 만듦
for truth_friend in map(int, input().split()[1:]):
    union(truth_friend, 0)

# 1명만 참가한 파티의 경우, 어차피 해당 참가자는 진실을 원래부터 알던 사람이 아니니까 union수행할 필요 없음
for _ in range(m):
    arr = list(map(int, input().split()))
    party.append(arr[1])    # 파티 정보로 각 파티의 첫번째 사람만 저장
    for i in range(2, arr[0] + 1):
        union(arr[i], arr[1])


print(count_party(party))
