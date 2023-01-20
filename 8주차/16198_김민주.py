

N = int(input())
arr = list(map(int, input().split()))

visited = [0 for _ in range(N)]

answer = 0

# 처음에 visited 배열 써서 하려다가 곱할 원소 판단이 복잡해져서
# 배열(arr)자체의 원소를 뺏다가 넣었다가 했음(N이 매우 작기 때문에 가능)
# 근데 pop, insert는 아무래도 시간 상 안 좋을 거 같아서 list 배열을 파라미터로 주고 잘라서 쓰는 방법도 써봄 -> 근데 왜인지 백준에서 이 방법이 시간이 더 오래 걸린다..?
def dfs(list, sum):
    global answer

    if len(list)==2:
        answer = max(sum, answer)
        return

    for i in range(1, len(list)-1):
        dfs(list[:i]+list[i+1:], sum+(list[i-1]*list[i+1]))

dfs(arr, 0)
print(answer)