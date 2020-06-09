class Solution:
    def translateNum(self, num: int) -> int:
        # dfs
        # 12258
        num_str = str(num)
        cache = {}  # 缓存， 空间换时间 40ms->36ms
        # count = 0
        def _dfs(num_str):
            # nonlocal count
            if not len(num_str):
                # count+=1
                return 1

            num_str1 = num_str[1:]
            num_str2 = num_str[2:]
            
            if not num_str1 in cache:
                res1 = _dfs(num_str1)
                cache[num_str1] = res1
            else:
                res1 = cache[num_str1]
            
            res2 = 0
            num_2 = int(num_str[:2])
            if len(num_str) >= 2 and num_2 <26 and num_2 > 9:
                if num_str2 in cache:
                    res2 += _dfs(num_str2)
                    cache[num_2] = res2
                else:
                    res2 = cache[num_str2]

            return res1 + res2
        
        # print(count)
        return _dfs(num_str)