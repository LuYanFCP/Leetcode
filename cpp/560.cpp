#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int presum[n+1];
        unordered_map<int, int> map;
        map[0] = 1;
        presum[0] = 0;
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            int next_sum = presum[i-1] + nums[i-1];
            presum[i] = next_sum;
            if (map.find(next_sum - k) != map.end()) count+=map[next_sum - k];
            if (map.find(next_sum) == map.end()) map[next_sum] = 0;
            ++map[next_sum];
        }
        return count;
    }
};


