class Solution:
    def myPow(self, x: float, n: int) -> float:
        # 快速幂算法
        if n < 0:
            x = 1/x
            n = -n
        base = x
        res = 1.0
        while n:
            if n % 2:
                res *= base
            n = n >> 1
            base *= base
        return res