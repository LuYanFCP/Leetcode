class Solution:
    def numTrees(self, n: int) -> int:
        """
        最简单的思路
        """
        dp = [0] * (n+1)
        dp[0] = 1
        for i in range(1, n+1):
            for j in range(i):
                dp[i] += dp[j]*dp[i-j-1]
        print(dp)
        return dp[n]