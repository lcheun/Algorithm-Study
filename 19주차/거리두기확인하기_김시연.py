def checkRoom(place):
    people = []
    for i in range(5):
        for j in range(5):
            if place[i][j] == "P":
                people.append((i, j))

    for x, y in people:
        for x2, y2 in people:
            dist = abs(x - x2) + abs(y - y2)
            if dist == 0 or dist > 2:
                continue

            if dist == 1:
                return 0
            elif x == x2 and place[x][(y + y2) // 2] != "X":
                return 0
            elif y == y2 and place[(x + x2) // 2][y] != "X":
                return 0
            elif x != x2 and y != y2:
                if place[x2][y] != "X" or place[x][y2] != "X":
                    return 0
    return 1


def solution(places):
    answer = []

    for i in range(5):
        num = checkRoom(places[i])
        answer.append(num)

    return answer