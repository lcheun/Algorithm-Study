def solution(cap, n, deliveries, pickups):
    d_val, p_val = 0, 0
    answer = 0
    for i in range(n):
        # 가장 먼곳부터 들르는게 최단거리
        # 만약 val에 더했는데도 음수인 경우에는, 저번 왕복에서 처리가능했었다는 뜻
        # 그러므로 두 값이 양수로 변하는 경우에만 밑에 작업을 수행
        d_val += deliveries[n - i - 1]
        p_val += pickups[n - i - 1]

        # 양수인 경우, 다시한번 왕복을 해야한다는 의미이므로 -cap
        while p_val > 0 or d_val > 0:
            d_val -= cap
            p_val -= cap
            # 왕복이라 *2
            answer += 2 * (n - i)
    return answer