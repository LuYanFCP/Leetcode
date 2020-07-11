# -*- coding:utf-8 -*-
class Solution:
    def countSmaller(self, nums):
        n = len(nums)
        # 1. 离散化
        unique_nums = sorted(list(set(nums)))
        hashtable = dict(zip(unique_nums, range(1, len(unique_nums)+1)))
        # 2. 构建空的树状数组

        t = [0] * (len(unique_nums)+1) # 空出0位置方便操作
        t_n = len(unique_nums)

        # BIT的lowbit操作
        def lowbit(n):
            return n & (-n)

        # BIT的更新
        def updata(t, x):
            # x = hashtable[val] # 找到val的索引
            while x <= t_n:
                t[x] += 1
                x += lowbit(x)
        
        def ask(x):
            ans = 0
            while x:
                ans += t[x]
                x -= lowbit(x)
            return ans
        
        print(hashtable)
        # 3. 从后先前算
        res = [0] * n
        for i in range(n-1, -1, -1):
            val = nums[i]
            idx = hashtable[val]
            print(idx, t)
            res[i] = ask(idx-1)
            updata(t, idx) # 先更新
        print(res)
        return res



if __name__ == "__main__":
    s = Solution()
    # s.countSmaller([5,2,6,1])
    s.countSmaller([-1, 0])
