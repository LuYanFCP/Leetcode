from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return -1
        l = 0
        r = len(nums) - 1

        while l < r:
            mid = (r - l) // 2 + l
            num_mid = nums[mid]
            if num_mid >= nums[l]:  # 在左边  
                if target <= num_mid and target >= nums[l]:  # 由于 r=mid因此可以等于
                    r = mid
                else:
                    l = mid + 1
            else:
                if target > num_mid and target <= nums[r]:  # nums[mid] < target < nums[r]
                    l = mid + 1
                else:
                    r = mid
        
        if nums[l] == target:
            return l

        return -1

if __name__ == "__main__":
    s = Solution()
    assert(s.search([1,3], 1) == 0)
    assert(s.search([1,3], 3) == 1)
    assert(s.search([3,1], 3) == 0)
    assert(s.search([3,1], 1) == 1)
