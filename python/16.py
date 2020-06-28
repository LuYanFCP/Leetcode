import sys
class Solution:
    def threeSumClosest(self, nums, target) -> int:
        n = len(nums)
        nums.sort()
        min_dist = sys.maxsize
        min_sum = 0
        for i in range(n):
            j = i + 1
            k = n - 1
            while j < k:
                temp = nums[i] + nums[j] + nums[k]
                if abs(temp - target) == 0: 
                    return temp

                if abs(temp - target) < min_dist:
                    # print(abs(temp - target), temp, min_dist)
                    min_dist = abs(temp - target)
                    min_sum = temp
                
                if temp < target:
                    j += 1
                else:
                    k -= 1

        return min_sum