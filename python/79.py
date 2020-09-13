from typing import List
from collections import deque



class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n = len(board)
        m = len(board[0])
        
        def get_index(x, y):
            return x * m + y
        

        def gen_next_node(node: tuple, pre_node: set):
            #  pre_node: set
            poss = [(1, 0), (0, 1), (-1, 0), (0, -1)]
            for pos in poss:
                next_x = pos[0] + node[0]
                next_y = pos[1] + node[1]
                # 防止越界和重复
                if next_x >= 0 and next_x < n and next_y >= 0 and next_y < m and get_index(next_x, next_y) not in pre_node:
                # if next_x >= 0 and next_x < n and next_y >= 0 and next_y < m:
                    yield (next_x, next_y)
        
        def get_x_y(index):
            return index%m, index/m
        
        def dfs(node: tuple, idx: int, pre_node: set): # node是当前节点， idx是对应str的位置
            # if idx == len(word):
            #     return True
            
            if board[node[0]][node[1]] == word[idx]:
                pre_node.add(get_index(*node))
                idx += 1
                
                if idx == len(word):
                    return True
                
                for next_node in gen_next_node(node, pre_node):                
                    if dfs(next_node, idx, pre_node):
                        return True
                
                pre_node.remove(get_index(*node))
            return False
    
        
        for i in range(n):
            for j in range(m):
                if dfs((i,j), 0, set()):
                    return True
        return False