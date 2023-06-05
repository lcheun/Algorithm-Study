from heapq import heappop, heappush


def prim():
    visited = [0 for _ in range(m)]
    ans, cnt = 0, 0

    pq = []
    pq.append((0, 0))

    while pq:
        if cnt == m:
            break

        cost, node = heappop(pq)

        if not visited[node]:
            visited[node] = 1
            ans += cost
            cnt += 1

            for nc, nn in connect[node]:
                heappush(pq, (nc, nn))

    return ans


while True:
    m, n = map(int, input().split())
    if m==0 and n==0:
        break

    total = 0
    connect = [[] for _ in range(m)]

    for _ in range(n):
        x, y, z = map(int, input().split())
        connect[x].append((z, y))
        connect[y].append((z, x))

        total += z

    print(total-prim())




