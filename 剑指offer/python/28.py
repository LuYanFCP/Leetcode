# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def is_cur(L, R):
            if L == None and R == None: 
                return True
            if L == None or R == None or L.val != R.val: 
                return False
            return is_cur(L.left, R.right) and is_cur(L.right, R.left)

        return is_cur(root.left, root.right) if root else True