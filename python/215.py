class Solution:
    """
    1040 ms	14.71%
    13.1 MB 100%
    """
    def findKthLargest(self, nums, k):
        i = 0
        length = len(nums)
        j = length - 1
        pivot = -1
        while i < j:
            print(nums, i, j, pivot)
            diff = length - pivot 
            if diff > k:
                i = pivot + 1
            elif diff < k:
                j = pivot - 1
            else:
                return nums[pivot]
            pivot = self.partition(nums, i, j)
        return nums[i]

    def partition(self, nums, i, j):
        if i == j:
            return i
        pivot = nums[i]
        l = i + 1
        r = j
        while 1:
            while l <= r and nums[l] < pivot: 
                l += 1
            while l <= r and nums[r] >= pivot:
                r -= 1
            if l <= r:
                nums[l], nums[r] = nums[r], nums[l]
            else:
                break

        nums[r], nums[i] = nums[i], nums[r]
        return r

s = Solution()
print(s.findKthLargest([3,2,1,5,6,4], 2))

 