class Solution:
    def translateNum(self, num: int) -> int:
        str_num = str(num)
        n = len(num)
        dp = [0] * n + 1 # 前n个数有多少种可能
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n+1):
            temp = int(str_num[i-2:i])
            if temp > 9 and temp < 26:
                dp[i] += dp[i-2]
            dp[i] += dp[i-1]

        return dp[n]

    def translateNum2(self, num: int) -> int:
        n = len(num)
        str_num = str(num)
        a, b = 1, 1 # 由于只用到后面两个数，所有可以直接迭代, 节约了空间
        for i in range(2, n+1):
            temp = int(str_num[i-2:i])
            if temp > 9 and temp < 26:
                a, b = a+b, a
            else:
                a, b = a, a
        return a