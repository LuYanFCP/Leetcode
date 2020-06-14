class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        def _sum(arr, m):
            __sum = 0
            for val in arr:
                __sum += val if val <= m else m
            return __sum

        l, r = 0, max(arr)
        while l < r:
            mid = (l + r)//2
            temp = _sum(arr, mid)
            print(l, r, mid, temp)
            if temp > target:
                r = mid
            elif temp < target:
                l = mid + 1
            else:
                return mid

        return l-1 if abs(_sum(arr, l) - target) >= abs(_sum(arr, l-1) - target) else l