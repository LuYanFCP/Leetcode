def conflict(state, nextX):
    nextY = len(state)
    for i in range(nextY):
        if abs(state[i] - nextX) in (0, nextY-i):
            return True
    return False

def queens(num, state):
    for pos in range(num):
        if not conflict(state, pos):
            if len(state) == num-1:
                yield (pos, )
            else:
                for result in queens(num, state+(pos,)):
                    yield (pos, ) + result

def prettyprint(solution):
    def line(pos, lenght=len(solution)):
        return '.'*(pos) + 'Q' + '.' * (lenght-pos-1)
    res = []
    for pos in solution:
        res.append(line(pos))


class Solution:
    def solveNQueens1(self, n: int) -> List[List[str]]:

        res = []
        for s in queens(num=n, state=()):
            print(s)
            res.append(prettyprint(s))
        print(len(res))
        return res

    def solveNQueens2(self, n: int) -> List[List[str]]:
        arr = list(range(n))

        def _check(arr):
            for i in range(0, n):
                for j in range(i+1, n):
                    if abs(i-j) == abs(arr[i] - arr[j]):
                        return False
            return True

        _res = []
        def _dfs(pos):

            if pos == n-1:
                if _check(arr):
                    _res.append(arr[:])
            else:
                for i in range(pos, n):
                    
                    arr[pos], arr[i] = arr[i], arr[pos]
                    _dfs(pos+1)
                    arr[pos], arr[i] = arr[i], arr[pos]

        _dfs(0)
        res = []

        def _replace(pos):
            str_res = ['.']*n
            str_res[pos] = 'Q'
            return ''.join(str_res)

        for res_one in _res:
            res.append([_replace(i) for i in res_one])
        return res
    
    def solveNQueens3(self, n: int) -> List[List[str]]:
        
        hashtable = [False] * (n+1)
        P = list(range(n+1))
        res = []

        def _replace(pos):
            str_res = ['.']*n
            str_res[pos-1] = 'Q'
            return ''.join(str_res)

        def dfs(index):
            if index == n+1:
                temp = []
                for i in range(1, n+1):
                    temp.append(_replace(P[i]))
                res.append(temp)
            
            for x in range(1, n+1):
                if not hashtable[x]:
                    flag = True
                    for pre in range(1, index):
                        if abs(index - pre) == abs(x - P[pre]):
                            flag = False
                            break
        
                    if flag:
                        P[index] = x
                        hashtable[x] = True
                        dfs(index+1)
                        hashtable[x] = False
        dfs(1)
        return res
            