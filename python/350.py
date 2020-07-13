from collections import Counter
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        hashtable = Counter()
        result = []
        for num1 in nums1:
            hashtable[num1] += 1
        for num2 in nums2:
            if num2 in hashtable:
                if hashtable[num2]:
                    result.append(num2)
                    hashtable[num2] -= 1
        return result