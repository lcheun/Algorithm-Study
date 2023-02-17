from collections import deque

n, w, L = map(int, input().split())
cars = list(map(int, input().split()))


# 큐를 이용해서 구현
# 처음에 다리의 길이만큼 0을 넣어준다 -> 차가 다리에 들어와서 나가는 거 시간 카운트할 수 있도록 빈 공간을 넣어준다.
q = deque()
for _ in range(w):
    q.append(0)

time = 0


idx = 0
while idx < n:
    time += 1
    q.popleft()

    # 지금 차 들어가도 다리 하중이 넘지 않는 경우
    if sum(q)+cars[idx] <= L:
        q.append(cars[idx])
        idx += 1
    # 넘으면 이전 차만 앞으로 가는 거고 빈공간이 생기는 거니까 0 넣어줌
    else:
        q.append(0)

# 다리에 차가 다 나가야 하므로 큐가 빌때까지
while q:
    time += 1
    q.popleft()

print(time)