from typing import List

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        temp = []
        candidates = list(range(1, 10))
        target = n
        n = len(candidates)
        
        def dfs(_target: int, idx:int, depth:int):
            if depth == k:
                if _target == 0:
                    res.append(temp[:])
                return
        
            for idx in range(idx, n):
                val = candidates[idx]
                if val <= _target:
                    temp.append(val)
                    dfs(_target - val, idx+1, depth+1)
                    temp.pop()
                    
                     
        dfs(target, 0, 0)
        return res