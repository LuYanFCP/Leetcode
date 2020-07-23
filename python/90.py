class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = [[]]
        n = len(nums)
        nums.sort()
        def dfs(temp, pos):
            pre = -100000000000
            for i in range(pos, n):
                if pre == nums[i]:  # 剪枝
                    continue
                pre = nums[i]
                temp.append(nums[i])
                result.append(temp[:])
                dfs(temp, i+1)
                temp.pop()

        dfs([], 0)
        return result