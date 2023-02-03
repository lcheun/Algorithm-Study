
N = int(input())
nums = []

#전체를 다 구하고 정렬 후 그 중에서 인덱스로 찾자!


def dfs(num, start):
    #역순으로 탐색해서 자동으로 감소하는 수가 되도록
    #다음 탐색에서 하나 아래 값부터 시작할 수 있도록(?) start로 범위 지정
    for i in range(start, -1, -1):
        num.append(i)
        dfs(num, i-1)
        nums.append(int(''.join(str(x) for x in num))) #오호..
        num.pop()


dfs([], 9)
nums.sort()

if N>=len(nums):
    print(-1)
else:
    print(nums[N])