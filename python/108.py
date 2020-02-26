# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    """
        72 ms 70.67%
        14.8 MB 100.00%
    """
    def sortedArrayToBST(self, nums):
        length = len(nums)
        if length == 0:
            return None
        if length == 1:
            return TreeNode(nums[0])  # 多一个判断会提示速度
        
        mid = (length - 1) // 2
        tempNode = TreeNode(nums[mid])
        tempNode.left = self.sortedArrayToBST(nums[:mid])  # [0:mid] 比 [:mid]切片慢?
        tempNode.right = self.sortedArrayToBST(nums[mid+1:])
        return tempNode