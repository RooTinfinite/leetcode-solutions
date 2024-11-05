def solve():
    f = open('user.out', 'w')
    for nums in map(loads, stdin):
        maxSum, curSum = nums[0], nums[0]
        for num in nums[1:]:
            if curSum < 0:
                curSum = num
            else:
                curSum += num
            if curSum > maxSum:
                maxSum = curSum
        print(maxSum, file=f)

solve()
exit()