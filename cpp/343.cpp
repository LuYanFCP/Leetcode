#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        if (n==2) return 1;  // 特殊情况
        if (n==3) return 2;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= i/2+1; ++j)
                dp[i] = max(dp[i-j]*dp[j], dp[i]);
        }
        
        ostream_iterator<int> out(cout, " ");
        std::copy(dp.begin(), dp.end(), out);
        return dp[n];
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.integerBreak(10);
    return 0;
}
