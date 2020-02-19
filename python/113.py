class Solution:        
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        self.res = []
        self.target = sum
        self.order(root, [], 0)
        return self.res
    
    def order(self, root, ls, sum):
        """
        52 ms	
        17.9 MB	
        """
        if root is not None:
            ls += [root.val]
            sum += root.val
            if root.left != None or root.right != None:  # 叶子节点判断
                self.inorder(root.left, ls[:], sum)  # ls[:]很浪费空间和时间, 因此order2的时候改成复用ls,加一个pop操作即可
                self.inorder(root.right, ls[:], sum)
            else:
                if sum == self.target:
                    # 这里会重复append
                    self.res.append(ls)

    def order(self, root, ls, sum):
        """
        44 ms	 72.95% 
        13.8 MB  100%
        """
        if root is not None:
            ls += [root.val]
            sum += root.val
            if root.left != None or root.right != None: 
                self.inorder(root.left, ls, sum)  # 此处做了修改
                self.inorder(root.right, ls, sum)
            else:
                if sum == self.target:
                    # 这里会重复append
                    self.res.append(ls[:])  # 这里还是copy操作,因为ls是引用
            ls.pop() # 弹出栈
            

    