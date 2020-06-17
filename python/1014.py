class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        pre = A[0] + 0
        ans = 0
        for i in range(1, len(A)):
            ans = max(pre + A[i] - i, ans)
            pre = max(A[i] + i, pre)
        return ans