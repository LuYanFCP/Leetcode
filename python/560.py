class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        presum = [0] * (n+1)
        hashmap = {0: 1}
        res = 0
        for i in range(1, n+1):
            next_sum = presum[i-1] + nums[i-1]
            presum[i] =  next_sum
            if (next_sum - k) in hashmap: res += hashmap[next_sum - k]
            if next_sum not in hashmap: hashmap[next_sum] = 0
            hashmap[next_sum] += 1
        
        return res