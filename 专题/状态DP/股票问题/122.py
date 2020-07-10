class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [ [0] * (n+1) for i in range(2)]
        dp[1][0] = - 100000 # prices[i] <= e4
        for i in range(n):
            dp[0][i+1] = max(dp[1][i] + prices[i], dp[0][i])
            dp[1][i+1] = max(dp[1][i], dp[0][i] - prices[i])
        return dp[0][n]

    def maxProfit2(self, prices: List[int]) -> int:
        n = len(prices)
        empty = 0
        exist = -10000000000
        for i in range(n):
            temp = empty
            empty = max(exist + prices[i], empty)
            exist = max(exist, temp - prices[i])
        return empty