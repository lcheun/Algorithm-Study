# 현재 위치에서 갈 수 있는 노드 찾기
def getNextNodes(i, prev, adj_list):
    nextNode = [edge for edge in prev if edge != i]
    for j in range(len(adj_list)):
        if adj_list[i][j] == True:
            nextNode.append(j)
    return nextNode


# 현재 위치(i) 기준으로 갈 수 있는 노드 방문 🠒 DFS
def DFS(i, sheep, wolf, prev, adj_list, info):
    global answer
    nextNode = getNextNodes(i, prev, adj_list)
    if sheep == wolf or not nextNode:
        if answer < sheep:
            answer = sheep
        return

    for node in nextNode:
        if info[node] == 0:
            # 가려는 노드에 양이 있는 경우
            DFS(node, sheep + 1, wolf, nextNode, adj_list, info)
        else:
            # 가려는 노드에 늑대가 있는 경우
            DFS(node, sheep, wolf + 1, nextNode, adj_list, info)


def solution(info, edges):
    global answer
    answer = 1
    adj_list = [[False] * len(info) for _ in range(len(info))]
    for x, y in edges:
        adj_list[x][y] = True

    DFS(0, 1, 0, [0], adj_list, info)
    return answer