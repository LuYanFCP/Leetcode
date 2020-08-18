#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // int minDays(int n) {
    //     // if (n < 3) n = 3;
    //     int *dp = new int[n+1];
    //     dp[1] = 1;
    //     for (int i = 2; i <= n; ++i) {  // 算了大量不需要计算的
    //         dp[i] = dp[i-1] + 1;
    //         if (i%3 == 0) {
    //             dp[i] = min(dp[i], dp[i/3] + 1);
    //         } else if (i%2 ==0) {
    //             dp[i] = min(dp[i], dp[i/2] + 1);
    //         }
    //     }
    //     return dp[n];
    // }

    int minDays(int n) {
        unordered_map<int, int> map;
        dfs(n, map);
    }

    int dfs(int n, unordered_map<int, int>& map) {
        if (n <= 1) return n;
        if (map.count(n)) return map[n];
        map[n] = min({1+n%2+dfs(n/2, map), 1+n%3+dfs(n/3, map), n});
        return map[n];
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    s.minDays(84806671);
    return 0;
}
