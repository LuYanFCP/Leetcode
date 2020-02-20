class Solution:
    def maxSubArray(self, nums):
        n = len(nums)  
        if n == 0:
            return 0
        # 这里可以直接使用nums，为了方便我更好的可读使用了dp
        # dp：已当前i为末尾的序列最大序列和
        # 转移方程：dp[i] = max(nums[i], nums[i] + dp[i-1])
        # 解释，以i为结尾有两种情况 [nums[i]], [...nums[i-1], nums[i]]
        dp = [0] * n  
        max_sum = nums[0]
        dp[0] = nums[0]
        for i in range(1, n):
            dp[i] = max(nums[i], nums[i] + dp[i-1])
            max_sum = max(dp[i], max_sum)

        return max_sum

s = Solution()
s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4])