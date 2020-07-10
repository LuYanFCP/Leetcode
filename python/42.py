class Solution:
    def trap(self, height: List[int]) -> int:
        stack = []
        res = 0
        for idx, val in enumerate(height):
            while len(stack) and val > height[stack[-1]]:
                top = stack.pop()
                if len(stack) == 0:
                    break
                h = min(height[stack[-1]], height[idx]) - height[top]
                dist = idx - stack[-1] - 1
                res += (dist * h)
            stack.append(idx)

        return res