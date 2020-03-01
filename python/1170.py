import bisect
class Solution:
    def numSmallerByFrequency(self, queries, words):
        """
        80 ms, faster than 72.52% 
        13.1 MB, less than 100.00%

        1. 计算words 所有 f(w)
        2. 扫描 queries 
            + 计算 f(queries)
            + 查找
        """
        words_f = [ self.f(word) for word in words]
        words_f.sort()
        words_len = len(words_f)
        print(words_f)
        res = []
        for querie in queries:
            querie_f = self.f(querie)
            res.append(words_len - bisect.bisect_right(words_f, querie_f))
        return res

    def f(self, word):
        """最小值char的num"""
        kv = {}
        min_char = ord('z')
        min_char_nums = 0
        for c in word:
            freq = kv.setdefault(c, 0)
            freq += 1
            if ord(c) <= min_char:
                min_char_nums = freq
                min_char = ord(c)
            kv[c] = freq 
        return min_char_nums


s = Solution()
# assert s.f("abbbbc") == 1
# assert s.f("zaaaz") == 3
assert s.f("bbbbbbbbab") == 1

# print(s.numSmallerByFrequency(["bbb","cc"], ["a","aa","aaa","aaaa"]))
print(s.numSmallerByFrequency(["bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb"], ["aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"]))

