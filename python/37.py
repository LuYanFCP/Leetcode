from typing import List
from itertools import repeat
import numpy as np

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        n, m = len(board), len(board[0])
        
        rows = np.array([[False for _ in range(9)]for _ in range(9)])
        cols = np.array([[False for _ in range(9)]for _ in range(9)])
        cells = np.array([[[False for _ in range(9)]for _ in range(9)] for _ in range(3)])

        # rows =  [  dict(zip(range(1, 10), repeat(False, 9))) for i in range(n)]  # 记录行
        # cols =  [  dict(zip(range(1, 10), repeat(False, 9))) for i in range(m)]  # 记录列
        # cells = [[ dict(zip(range(1, 10), repeat(False, 9))) for i in range(n//3)] for j in range(m//3)]  # 记录cells
        
        cnt = 0
        
        for i in range(n):
            for j in range(m):
                if board[i][j] == '.':
                    cnt += 1
                    continue
                idx = ord(board[i][j]) - ord('1')
                
                rows[i][idx] = True
                cols[j][idx] = True
        
        def getPossibleStatus(i, j):
            """
            返回可能位置的一个bool向量
            """
            return ~(rows[i] | rows[j] | cells[i//3][j//3])
        
        def getNext():  # 动态获得下一个
            """
            找到范围最小的点
            """
            minCnt = 10
            res = (0, 0)
            for i in range(9):
                for j in range(9):
                    if board[i][j] != '.': continue
                    cur = getPossibleStatus(i, j)
                    
                    if np.sum(cur) < minCnt:
                       res = (i, j)
                       minCnt = np.sum(cur)
            return res
        
        def fillNum(x:int, y:int, n:int, flag:bool) -> None:
            rows[x][n] = flag
            cols[y][n] = flag
            cells[x//3][y//3][n] = flag
        
        def dfs(cnt: int) -> bool:
            if cnt == 0: return True
            
            next_pos = getNext()
            bit_vec = getPossibleStatus(next_pos[0], next_pos[1])
            for idx in range(9):
                if not bit_vec[idx]: continue
                fillNum(next_pos[0], next_pos[1], idx, True)
                board[next_pos[0]][next_pos[1]] = chr(idx + ord('1'))
                if dfs(cnt-1): return True
                board[next_pos[0]][next_pos[1]] = '.'
                fillNum(next_pos[0], next_pos[1], idx, False)
                               
            return False
    
        dfs(cnt)
        print(board)
        
            
s = Solution()
board = eval("""[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]""")
s.solveSudoku(board=board)