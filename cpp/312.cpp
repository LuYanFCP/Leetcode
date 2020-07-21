#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n+2, 1);  // 让开最后一个和第一个放1
        for (int i = 1; i <= n; ++i) vec[i] = nums[i-1];

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for (int i = n+1; i >= 0; --i) {
            for (int j = i; j <= n+1; ++j) {
                if (j - i < 2) dp[i][j] = 0;
                for (int k = i+1; k <= j-1; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + vec[i] * vec[k] * vec[j]);
                }
            }
        }
        return dp[0][n+1];
    }
};