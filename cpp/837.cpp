#include <algorithm>
using namespace std;
class Solution {
public:
    double new21Game(int N, int K, int W) {
        // vector<double> dp(K+W+1, 0.0);
        double dp[20000+1];
        fill(dp, dp+20000+1, 0.0);
        double _sum = N-K+1;
        for (int i = K; i <= N ; ++i) {
            dp[i] = 1.0;
            // _sum += 1.0;
        }
            

        for (int i = K-1; i >= 0; --i) {
            // 问题出在这
            // for (int j = i+1; j <= i+W; ++j) {
            //     _sum += dp[j];
            // }
            dp[i] = _sum * 1/W;
            // printf("%d-%f--dp[i]=%f\n", i+W, dp[i+W-1], _sum);
            _sum = _sum - dp[i+W] + dp[i];
        }
        return dp[0];
    }
};