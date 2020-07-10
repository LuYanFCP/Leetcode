#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), k = 2;
        int dp[2*k+1];
        for(int i = 0; i < (2*k+1); ++i) {
            if (i%2)  dp[i] = -100000; // 奇数
            else  dp[i] = 0;
        }
        // int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 2*k; j > 0; --j) {
                if (j%2) dp[j] = max(dp[j],  dp[j-1] - prices[i]);
                else{
                    dp[j] = max(dp[j],  dp[j-1] + prices[i]);
                    // res = max(dp[j], res);
                } 
            }
            dp[0] = 0;
        }
        // 计算所有偶数位置的大小的最大值
        vector<int> res(k+1);
        for (int i = 0; i <=k; ++i) res[i] = dp[i*2];
        return *max_element(res.begin(), res.end()); 
        // return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vec = {3,3,5,0,0,3,1,4};
    printf("%d", s.maxProfit(vec));
    return 0;
}
