# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        stack = []
        res = []
        p = root
        
        while p or stack:
            while p:
                stack.append(p)
                p = p.left
            if stack:
                p = stack.pop()
                res.append(p.val)
                p = p.right
                
        return res