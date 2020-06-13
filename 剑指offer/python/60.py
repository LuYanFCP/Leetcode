class Solution:
    def twoSum(self, n):
        dp = [[0 for j in range(n*6+1)] for i in range(n)]
        dp[0][1:6] = ([1] * 6)
        for i in range(1, n):
            for j in range(i, i*6+7):
                for k in range(1, 7):
                    if j >= k+i-1 and j-k <= 6*n: # 优化 因为 n 不需要再计算n-1
                        dp[i][j] += dp[i-1][j-k]

        res = []
        for i in range(n, n*6+1):
            res.append(dp[n-1][i]*1.0/6**n)
        return res

    def twoSum_2(self, n):
        dp = [0 for j in range(n*6+1)]
        dp[1:6] = ([1] * 6)
        for i in range(2, n+1):
            for j in range(i*6, i-1, -1):
                dp[j] = 0
                for k in range(1, 7):
                    if j >= k+i-1 : # 优化
                        dp[j] += dp[j-k]  # 压缩存储
        res = []
        for i in range(n, n*6+1):
            res.append(dp[i]*1.0/6**n)
        
        return res



if __name__ == "__main__":
    s = Solution()
    s.twoSum_2(2)