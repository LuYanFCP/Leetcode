class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]]
        for val in nums:
            for i in range(len(result)):
                result.append(result[i]+[val]) 
        return result

    def subsets_dfs(self, nums: List[int]) -> List[List[int]]:
        result = [[]]
        n = len(nums)
        def dfs(temp, pos):
            for i in range(pos, n):
                temp.append(nums[i])
                result.append(temp[:])
                dfs(temp, i+1)
                temp.pop()

        dfs([], 0)
        return result