# 0 카드가 없다는 점을 생각해주지 못해서 처음에 틀렸어서 고쳤음
# 숫자 범위가 유효하다면 앞자리와 이어서 + 독립 하게 만들수 있으므로 dp[i-1]+dp[i-2]
# 숫자 카드가 이어진 경우 34를 초과하거나, 앞자리가 0인 경우에는 독립 카드로만 dp[i-1]
# 현재 숫자 카드가 0인 경우에는 무조건 앞과 이어주어야 한다. dp[i-2]

nums = input()
dp = [0]*(len(nums))

dp[0] = 1
if len(nums)>=2:
    if nums[1]!='0' and nums[0]+nums[1] <= '34':
        dp[1] = 2
    else:
        dp[1] = dp[0]

if len(nums)>=3:
    for i in range(2, len(nums)):
        # 두가지 다 가능한 경우
        if nums[i-1]!='0' and nums[i]!='0' and nums[i-1]+nums[i] <= '34':
            dp[i] = dp[i-1]+dp[i-2]
        # 이전이 0이거나 34 초과하는데 현재 숫자가 0이 아닌 경우 -> 독립으로 사용
        elif nums[i] != '0':
            dp[i] = dp[i-1]
        # 현재 숫자가 0인 경우 -> 이어서 사용
        else:
            dp[i] = dp[i-2]

print(dp[len(nums)-1])