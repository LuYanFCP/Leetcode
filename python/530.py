class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        min_diff = 10000000000
        pre_val = -10000000000
        
        def inorder(root: TreeNode):
            nonlocal min_diff
            nonlocal pre_val
            if root == None:
                return
            inorder(root.left)
            min_diff, pre_val = min(root.val - pre_val, min_diff), root.val
            inorder(root.right)
            
        inorder(root)
        return min_diff