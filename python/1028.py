# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import collections

class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        q = collections.deque()
        S = S +  '-'
        count = 0
        left = 0
        for i in range(0, len(S)):
            if S[i] == '-':
                if left != i:
                    q.append((S[left:i], count))
                    count = 0
                count += 1
                left = i+1;
        # bit 
        def build_tree(depth):
            if not len(q) or q[0][1] != depth:
                return None
            root = TreeNode(q.popleft()[0])
            root.left = build_tree(depth+1)
            root.right = build_tree(depth+1)
            
            return root
        
        return build_tree(0)