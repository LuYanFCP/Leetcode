import queue

class Solution:
    
    def permutation(self, s: str) -> List[str]:
        self.flag = [False] * len(s)
        self.result = []
        self.temp = []
        self.orderset = set()
        self.dfs(s, 0)
        return self.result


    def dfs(self, s: str, pos: int):
        if pos == len(s):
            res = ''.join(self.temp)
            if not res in self.orderset:
                self.result.append(res)
                self.orderset.add(res)

        for i in range(len(s)):
            if not self.flag[i]:
                self.flag[i] = True
                self.temp.append(s[i])
                self.dfs(s, pos+1)
                self.flag[i] = False
                self.temp.pop()
