class Solution:
    def sumNums(self, n: int) -> int:
        """
        使用and运算符短路
        """
        sum_val = 0       
        def _sum(n):
            nonlocal sum_val
            sum_val += n
            return n and _sum(n-1)
        _sum(n)
        return sum_val