class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        def dfs(b, e, lst):
            # print(lst)
            if len(lst) == k:
                res.append(lst[:])
                return
            if b > e:
                return
            for j in range(b, e):
                lst.append(j+1)
                dfs(j+1, e, lst)
                lst.pop()
        
        dfs(0, n, [])
        return res