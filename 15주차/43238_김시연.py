"""
꼭 딱 떨어지는 시간이 나오지 않을 수 있다는걸 몰랐음
n=10, times = [6, 8, 10]의 경우
30->9명, 31->11명을 처리 가능함. 딱 10명 처리가능한 시간대가 없음
이런경우도 생각해야함
"""

def solution(n, times):
    answer = 0

    left = 1
    right = max(times) * n
    mid = (left + right) // 2

    while left <= right:
        count = 0
        for time in times:
            count += mid // time

        if count >= n:
            right = mid - 1
            answer = mid
        else:
            left = mid + 1
        mid = (left + right) // 2

    return answer

if __name__ == '__main__':
    times = [6, 8, 10]
    n = 10
    output = solution(n, times)
    print(output)
