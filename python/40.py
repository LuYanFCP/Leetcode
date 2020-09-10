from typing import List

class Solution:
   def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        temp = []
        
        n = len(candidates)
        candidates.sort()   ## 1. 进行排序
        
        def dfs(_target: int, idx:int):
            if _target < 0:
                return  # 剪枝
            elif _target == 0:
                res.append(temp[:])
                return

            """
            剪枝的思路：
            由于数组是排序好的，因此只要前一个不等于当前就不重复
            [1, 2, 2, 2]
             |  |
            1, 2 不等，因此当前和之前一个不重复
            [1, 2, 2, 2]
                |  |
            2, 2 相等，因此当前和之前一个不重复
            """
            pre = -1  # 2. 进行减枝
            for idx in range(idx, n):
                val = candidates[idx]
                if val <= _target and pre != val: # 2. 进行剪枝
                    temp.append(val)
                    dfs(_target - val, idx+1)  # 3. 不再重复搜索自身
                    temp.pop()
                pre = val # 2. 进行减枝
                    
        dfs(target, 0)
        return res