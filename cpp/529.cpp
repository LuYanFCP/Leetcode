#include "tools.h"
#include <bits/stdc++.h>


using namespace std;

#define ADD(a, b) pair<int, int>(a.first + b.first, a.second + b.second)

class Solution
{
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        queue<pair<int, int>> q;
        int m = board.size(), n = board[0].size();
        vector<pair<int, int>> poss = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        q.push({x, y});
        flag[x][y] = true;
        int next_x, next_y, count;
        while (!q.empty())
        {
            pair<int, int> c = q.front();
            q.pop();
            x = c.first;
            y = c.second;
            count = 0;
            for (const pair<int, int> &p : poss)
            {
                next_x = p.first + x;
                next_y = p.second + y;
                if (check(next_x, next_y, m, n)) {
                    if (board[next_x][next_y] == 'M') ++count;
                }
            }
            // printf("%d, %d, %d\n", next_x, next_y, count);
            if (count==0) board[x][y] = 'B';
            else board[x][y] = static_cast<char>(count + '0');
            if (board[x][y] == 'B')
            {
                for (const pair<int, int> &p : poss)
                {
                    next_x = p.first + x;
                    next_y = p.second + y;

                    if (check(next_x, next_y, m, n) && board[next_x][next_y] == 'E' && flag[next_x][next_y]==false)
                    {
                        q.push({next_x, next_y});
                        flag[next_x][next_y] = true;
                    }
                }
            }
        }
        return board;
    }

    inline bool check(int x, int y, int m, int n)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


int main(int argc, char const *argv[])
{
    int m, n, x, y;
    char c;
    Solution s;
    freopen("test.in", "r", stdin);
    cin >> m >> n;
    vector<vector<char>> matrix(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c;
            matrix[i][j] = c;
        }
        // PRINT_VECTOR(matrix[i], char);        
    }
    cin >> x >> y;
    vector<int> begin = {x, y};
    auto res = s.updateBoard(matrix, begin);
    PRINT_MATRIX(res, char, cout);
    return 0;
}
