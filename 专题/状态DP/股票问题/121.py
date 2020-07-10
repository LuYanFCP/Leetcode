class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if not n: return 0
        dp = [ [0] * (n+1) for i in range(2)]
        dp[1][0] = -10000000000  # 这里代表最大
        for i in range(n):
            dp[0][i+1] = max(dp[0][i], dp[1][i] + prices[i])
            dp[1][i+1] = max(dp[1][i], -prices[i])
        return dp[0][n] 
    
    def maxProfit2(self, prices: List[int]) -> int:
        n = len(prices)
        if not n: return 0
        empty = 0
        exist = -100000000000
        for i in range(n):
            empty = max(empty, exist + prices[i])
            exist = max(exist, -prices[i])
        return empty