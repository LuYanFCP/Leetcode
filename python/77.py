class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]]
        for val in nums:
            for i in range(len(result)):
                result.append(result[i]+[val]) 
        return result