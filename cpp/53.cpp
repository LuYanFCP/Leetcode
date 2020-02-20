#include <vector>
#include <cmath>
#include <cstdio>
using std::vector;
using std::printf;

#define MAX(a, b) (a) > (b) ? (a) : (b)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
         * 4 ms	
         * 9.4 MB
         */
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        /*
         * dp数组的含义：到i为结尾最大子序列和
         * 转移方程： dp[i] = MAX(nums[i], nums[i] + dp[i - 1]);
         * 解释，以i为结尾有两种情况 [nums[i]], [...nums[i-1], nums[i]]
         */
        vector<int> dp(n);  // 这个其实可以直接使用nums代替，这里使用dp是为了更好理解
        dp[0] = nums[0];
        int max_sum = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = MAX(nums[i], nums[i] + dp[i - 1]);
            max_sum = MAX(dp[i], max_sum); 
        }
        return max_sum;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {-2, -1};
    printf("%d", s.maxSubArray(vec));
}