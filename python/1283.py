class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        begin, end = 1, max(nums)+1
        while begin < end:
            mid = (end - begin)//2 + begin
            _sum = 0
            for num in nums:
                _sum += (num + mid - 1) // mid
            if _sum <= threshold:
                end = mid
            else:
                begin = mid + 1
        return end