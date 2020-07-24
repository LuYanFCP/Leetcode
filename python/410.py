class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        l = max(nums)
        r = sum(nums)
        while l < r:
            mid = (r + l)//2;
            n = 1 # 分类的个数
            curr = 0
            for num in nums:
                curr += num
                if curr > mid:  # <= mid ok
                    curr = num # 退一格
                    n += 1 # 类的个数+1
            # print(n)
            if n > m: # 分的多了，要分少一些 
                l = mid + 1 # 往大值偏
            else:  # 分的少了，要分的多一些
                r = mid
            # print(l, r)

        return l