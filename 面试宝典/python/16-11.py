class Solution:
    def divingBoard(self, shorter: int, longer: int, k: int) -> List[int]:
        if k == 0:return []
        if shorter == longer: return [k*shorter]
        return list(range(shorter*k,longer*k+1,(longer-shorter)))