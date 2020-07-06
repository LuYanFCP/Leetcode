# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        res = 0
        
        def dfs(root: TreeNode):
            if not root: return 0
            nonlocal res
            left_depth = dfs(root.left)
            right_depth = dfs(root.right)
            res = max(res, left_depth+right_depth)
            return max(left_depth, right_depth) + 1
        
        dfs(root)
        return res