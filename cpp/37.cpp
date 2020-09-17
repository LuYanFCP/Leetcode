#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     *  Leetcode题解【解数独】回溯 + 状态压缩（使用 bitset）
    */
    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<bitset<9>>(9, bitset<9>());  // 行的标记, 一行9个
        cols = vector<bitset<9>>(9, bitset<9>());  // 列的标记
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));  // cell 部分， 记录数字
        
        int cnt = 0;  // 计数单元，记录有多少个待填的数
        int n = board.size(), m = board[0].size();
        for (int i=0; i < n; ++i) {
            for (int j=0; j < m; ++j) {
                cnt += (board[i][j] == '.');
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';  // 1-9 => 0-8
                rows[i] |= (1<<n);  // 标记已经选择的数
                cols[j] |= (1<<n);  // 标记已经选择的数
                cells[i/3][j/3] |= (1<<n); // cells中标记已经选择的数
            }
        }
        dfs(board, cnt);   
    }
    bool dfs(vector<vector<char>>& board, int cnt) {
        if (cnt == 0) return true;

        auto next = getNext(board);
        auto bits = getPossibleStatus(next[0], next[1]);
        for (int n = 0; n < bits.size(); ++n) {
            if (!bits.test(n)) continue;            // continue
            fillNum(next[0], next[1], n, true);     // 标记
            board[next[0]][next[1]] = n+'1';
            if (dfs(board, cnt - 1)) return true;
            board[next[0]][next[1]] = '.';
            fillNum(next[0], next[1], n, false);    // 恢复
        }
        return false;
    }

    vector<int> getNext(vector<vector<char>>& board) {
        vector<int> ret;
        int minCnt = 10;  // 元素个数
        int n = board.size(), m = board[0].size();
        for (int i=0; i < n; ++i) {
            for (int j=0; j < m; ++j) {
                if (board[i][j] != '.') continue;
                auto cur = getPossibleStatus(i, j);  // 还没填的位置，获取其 可以填啥
                // 找到最小范围的位置
                if (cur.count() >= minCnt) continue; // 如果没有
                ret = {i, j};
                minCnt = cur.count(); // 或者set位置
            }
        }
        return ret;
    }

    bitset<9> getPossibleStatus(int x, int y) {
        return ~(rows[x] | cols[y] | cells[x/3][y/3]);  // get 未标记的
    }

    void fillNum(int x, int y, int n, bool fillFlag) {
        rows[x][n] = (fillFlag)? 1:0;
        cols[y][n] = (fillFlag)? 1:0;
        cells[x/3][y/3][n] = (fillFlag)? 1:0;
    }

private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;
};