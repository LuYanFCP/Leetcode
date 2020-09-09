from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        """

        Parameters
        ----------
        candidates : List[int]
            输入的无重复的数组
            
        target : int
            求和的目标值

        Returns
        -------
        List[List[int]]
            结果的组合
        """
        res = []
        
        temp = []
        
        n = len(candidates)
        
        def dfs(_target: int, idx:int):
            if _target < 0:
                return  # 剪枝
            elif _target == 0:
                res.append(temp[:])
                return
        
            for idx in range(idx, n):
                val = candidates[idx]
                if val <= _target:
                    temp.append(val)
                    dfs(_target - val, idx)
                    temp.pop()
                    
        dfs(target, 0)
        return res