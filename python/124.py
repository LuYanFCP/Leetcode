# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import sys

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.result = -sys.maxsize-1
        def _dfs(r):
            if r == None:
                return 0
            left_length = _dfs(r.left)
            right_length = _dfs(r.right)
            val1  = r.val
            val2 = r.val + left_length
            val3 = r.val + right_length
            val4 = r.val + left_length + right_length
            max_val = max([val1, val2, val3, val4])  # 作为根
            self.result = max(self.result, max_val)  
            return max([val1, val2, val3])  # 作为路径

            # 两种情况

        _dfs(root)
        return self.result