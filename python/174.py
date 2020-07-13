class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])
        dp = [[100000] * (n + 1) for _ in range(m + 1)]
        dp[n][m - 1] = dp[n - 1][m] = 1

        for i in range(m - 1, -1, -1):  
            for j in range(n - 1, -1, -1):
                minn = min(dp[i + 1][j], dp[i][j + 1])
                dp[i][j] = max(minn - dungeon[i][j], 1) 

        return dp[0][0]