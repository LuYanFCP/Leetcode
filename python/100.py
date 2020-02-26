# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSameTree(self, p, q) -> bool:
        """
        28 ms, faster than 70.22%
        12.7 MB, less than 100.00%
        """
        if not p and not q:  # 两个都是最终节点
            return True
        if not p or not q or p.val != q.val: # 出现一个是一个不是或者两个值的一致
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)