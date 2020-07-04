class Solution:
    def longestValidParentheses(self, s: str) -> int:
        maxlen = 0
        stack = [-1]
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()  # 弹出栈
            if not len(stack):
                stack.append(i)
            else:
                maxlen = max(maxlen, i - stack[-1])

        return maxlen