class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashmap = {}
        for v in nums:
            if v in hashmap:
                hashmap[v] += 1
            else:
                hashmap[v] = 1
        
        sorted_map = sorted(hashmap.items(), key=lambda x: x[1], reverse=True)

        res = []
        for i in range(k):
            res.append(sorted_map[i][0])
        return res