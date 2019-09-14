# include<cstring>
# include<string>
# include<cassert>
using std::string;


#define MAX(a, b) (a) > (b) ? (a) : (b)
/*
 * 这道题目的我的解法的时间复杂度为O(N) 空间复杂度为O(1)
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /* 排除第一种情况 */
        if (0 == s.size())
            return 0;  
        int startIdx = 0, maxLen = 1;
        int currLen = 0;
        int charTable[256]; // 这里去初始化一下这个 
        memset(charTable, -1, sizeof(int) * 256); // 做一个hash映射，用空间换时间， char->index
        for (int i = 0; i < s.size(); i++) {
            if (charTable[s[i]] != -1) { //判断是否在 
                int charIdx = charTable[s[i]];
                if (charIdx >= startIdx) { // 说明有
                    maxLen = MAX(maxLen, currLen);
                    startIdx = charIdx + 1;
                    currLen = i - startIdx; // 如果确认有重复则当前位置，减去开始位置就是currLen
                }
            }
            charTable[s[i]] = i;
            currLen ++;
        }
        return MAX(maxLen, currLen); 
    }
};

int main() {
    Solution s;
    assert(0 == s.lengthOfLongestSubstring("")); // 极端值覆盖
    // 题目中的例子
    assert(3 == s.lengthOfLongestSubstring("abcabcbb"));
    assert(1 == s.lengthOfLongestSubstring("bbbbb"));
    assert(3 == s.lengthOfLongestSubstring("pwwkew"));
    assert(1 == s.lengthOfLongestSubstring(" "));
    assert(3 == s.lengthOfLongestSubstring("dvdf"));
}