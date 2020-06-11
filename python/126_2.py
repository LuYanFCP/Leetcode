import queue
class Solution:
    def findLadders(self, beginWord, endWord, wordList):
        if not beginWord in wordList:
            wordList.append(beginWord)
        if not endWord in wordList:
            return []
        
        n = len(wordList)
        A = [[0] * n for i in range(n)]
        for i in range(n):
            A[i][i] = 1
        
        def _diff_one(s1, s2):
            count = 0
            for c1, c2 in zip(s1, s2):
                if c1 != c2:
                    count+=1 
            return count == 1

        # 构图
        for i in range(len(wordList)):
            for j in range(i, len(wordList)):                
                if _diff_one(wordList[i], wordList[j]):
                    A[i][j] = 1
                    A[j][i] = 1

        # dfs+剪枝
        begin_index = wordList.index(beginWord)
        end_pos = wordList.index(endWord)

        max_way_len = 1000000
        temp_res = []
        view = [False for i in range(n)]
        res = []

        def _dfs(pos, way_len):
            nonlocal max_way_len
            if pos == end_pos:
                if way_len < max_way_len:
                    max_way_len = way_len
                    res.clear()
                res.append([beginWord] + temp_res[:])
                print(temp_res[:])
                return

            if way_len >= max_way_len:
                return # 剪枝
            
            for i in range(n):
                # 判断条件
                if A[pos][i] == 1 and (not view[i]):
                    view[i] = True
                    temp_res.append(wordList[i])
                    _dfs(i, way_len+1)
                    view[i] = False
                    temp_res.pop()

        _dfs(begin_index, 0)
        # -2 -> -1 BFS
        # pre = [[-1] for i in range(n)]
        # way_len = [100000 for i in range(n)]
        # flag = [True for i in range(n)]
        # begin_index = wordList.index(beginWord)
        # way_len[begin_index] = 0
        # q = queue.Queue()
        # q.put(begin_index)
        # flag[begin_index] = False
        # while not q.empty():
        #     i = q.get()
        #     flag[i] = False
        #     for j in range(n):
        #         if A[i][j] == 1 and flag[j]:
        #             if way_len[j] > way_len[i] + 1:
        #                 way_len[j] = way_len[i] + 1
        #                 pre[j] = [i]
        #             elif way_len[j] == way_len[i] + 1:     
        #                 if not i in pre[j]:
        #                     pre[j].append(i)
        #             q.put(j)

        # res = []
        # print('test')
        # k = wordList.index(endWord)
        # if way_len[k] == 100000:
        #     return res

        # if pre[k] == [-1]:
        #     return []
        
        # temp_res = []
        # def _dfs(lst, pos):
            
        #     if pos == -1:
        #         res.append(temp_res[::-1])
        #         return
        #     for node in lst:
        #         temp_res.append(wordList[pos])
        #         _dfs(pre[node], node)
        #         temp_res.pop()


        # _dfs(pre[k], k)
        return res

