#include <vector>
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /**
         * 1. Runtime: 12 ms, faster than 93.87% of C++ online submissions for Single Number.
         * 2. Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Single Number.
         */
         
        int res = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i)
            res ^= nums[i];
        return res;
    }
};