#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 2) return 1;
        if (n==3) return 2;
        vector<int> dp(n+1, 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; ++i) {
            for (int j = 1; j < i/2+1; ++j) {
                dp[i] = max(dp[i], dp[j]*dp[i-j]);
            }
        }
        return dp[n];

    }
};