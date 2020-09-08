from itertools import combinations
from typing import List
import pprint

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        return list(map(list, combinations(range(1, n+1), k)))
    

if __name__ == "__main__":
    s = Solution()
    pprint.pprint(s.combine(7, 2))