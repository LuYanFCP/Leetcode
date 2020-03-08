from functools import reduce
from functools import cmp_to_key
def cmp(str1, str2):
    x = str1+str2
    y = str2+str1
    if x < y:
        return 1
    elif x > y:
        return -1
    else:
        return 0
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        if nums == []:
            return
        str_nums = [str(n) for n in nums]
        str_nums.sort(reverse=True, key=cmp_to_key(cmp))
        return reduce(lambda x, y: x+y, str_nums)




"""
from functools import reduce
import sys
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        self.str_nums = [str(i) for i in nums]
        self.min = 'z'
        self.permutations(0, len(nums))
        return self.min

    def permutations(self, position, end):
        if position == end:
            _sum = reduce(lambda x, y: x+y, self.str_nums)
            if self.min > _sum:
                self.min = _sum
        else:
            for index in range(position, end):
                self.str_nums[index], self.str_nums[position] = self.str_nums[position], self.str_nums[index]
                self.permutations(position+1, end)
                self.str_nums[index], self.str_nums[position] = self.str_nums[position], self.str_nums[index]
"""