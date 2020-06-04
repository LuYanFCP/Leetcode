class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [1] * n
        l, r = 1, 1
        for i in range(0, n):
            j = n - i - 1
            res[i] *= l
            res[j] *= r
            l *= nums[i]
            r *= nums[j]
        return res