# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from typing import List
from collections import deque
from collections import OrderedDict

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        q = deque()
        
        avg = lambda x: sum(x)/len(x)
        
        q.append((root, 1))
        layer_dict = OrderedDict()
        
        while len(q):
            node, depth = q.popleft()
            layer_dict.setdefault(depth, []).append(node.val)
            # 左节点
            if node.left:
                q.append((node.left, depth+1))

            # 右节点                
            if node.right:
                q.append((node.right, depth+1))
        
        result = list(map(avg, layer_dict.values()))
        return result