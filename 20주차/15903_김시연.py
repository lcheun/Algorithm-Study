from sys import stdin
import heapq


n, m = map(int, stdin.readline().split())
cards = [int(x) for x in stdin.readline().split()]
heapq.heapify(cards)

# 걍 작은순으로 정렬한 다음에, 제일 작은거 2개 뽑아서 합체하는게 제일 작은값이 나오는 결과임
for _ in range(m):
    card1 = heapq.heappop(cards)
    card2 = heapq.heappop(cards)

    heapq.heappush(cards, card1 + card2)
    heapq.heappush(cards, card1 + card2)

print(sum(cards))
