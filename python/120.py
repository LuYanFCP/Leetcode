class Solution:
    def minimumTotal(self, triangle):
        length = len(triangle)
        lst = triangle[length - 1][:]  # 滚动数组
        for i in range(length - 2, -1, -1):
            for j in range(0, i+1):
                lst[j] = min(lst[j], lst[j+1]) + triangle[i][j]

        return lst[0]
        