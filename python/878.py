class Solution:
    def nthMagicalNumber(self, N: int, A: int, B: int) -> int:
        def gcd(x, y):
            if not x:
                return y
            else:
                return gcd(y % x, x);

        A_B = A*B//gcd(A, B)
        MOD = 10**9 + 7

        i = 1
        j = 10 ** 15
        while i < j:
            mid = (i + j) // 2
            n = mid // A + mid // B - mid // A_B
            if n < N:
                i = mid + 1
            else:
                j = mid

        return i % MOD


