class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        empty = 0
        exist = -10000000000
        for i in range(n):
            temp = empty
            empty = max(exist + prices[i]-fee, empty)
            exist = max(exist, temp - prices[i])
        return empty