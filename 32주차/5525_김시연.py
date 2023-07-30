"""
그냥 냅다 I가 나올때마다 번갈아서 나오는지 count하면 너무 비효율적임
IOIOI등을 전체를 찾으려 하지 말고 IOI가 시작되는 index부분을 찾아서 정리해놓는식..?
=> IOI가 몇번 연속되는지 count하면 원하는 길이의 IOI가 연속되는 구간에 몇개 있는지도 금방 찾을 수 있음
=> 5번 연속되는 구간에서 IOIOIOI는 3번 나옴(5-(3-1))
"""
import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
s = input()
answer, i, count = 0, 0, 0

while i < (m-1):
    # IOI 단위로 끊기
    if s[i:i+3] == 'IOI':
        i += 2
        count += 1
        if count == n:
            answer += 1
            count -= 1

    else:
        # IOI가 끊긴거니까 count초기화
        i += 1
        count = 0


print(answer)