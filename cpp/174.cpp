#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        // 为了少写一个判断，增加一行一列
        vector<vector<int>> dp(m+1, vector<int>(n+1, 100000));
        dp[m][n-1] = dp[m-1][n] = 1; // 不能死
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                // 找到最少的路
                int min_pre = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(min_pre - dungeon[i][j], 1); //如果小于零证明血量够后面用了，改为0通过前面的路即可
            }
        }
        return dp[0][0];
    }
};
