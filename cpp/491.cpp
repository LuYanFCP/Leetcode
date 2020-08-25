#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/**
 * dfs + set去重复
 * 
*/
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // unordered_map<int, vector<int>> cache;  /*第一个是int（pos）， 第二个是vector<int>, 存的缓存的结果*/
        vector<int> pre;
        set<vector<int>> res;
        dfs(nums, 0, pre, -101, res);
        return vector<vector<int>>(res.begin(), res.end());
    }

    void dfs(vector<int>& nums, int pos, vector<int> pre, int pre_value, set<vector<int>> &res) {
        int n = nums.size();

        if (pre.size()>1)
            res.insert(pre);
        for (int i = pos; i < n; ++i) {
            if (nums[i] >= pre_value) {
                pre.push_back(nums[i]);
                dfs(nums, i+1, pre, nums[i], res);
                pre.pop_back(); // 吐出去
            }
        }
    }
};