#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(0, target, candidates, temp, res);
        return res;
    }

    void dfs(int idx, int _target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& res) {

        if (_target == 0) {
            res.emplace_back(temp);
            return;
        }

        int n = candidates.size();
        for (int i = idx; i < n; ++i) {
            int val = candidates[i];
            if (val <= _target) {
                temp.push_back(val);
                dfs(i, _target-val, candidates, temp, res);
                temp.pop_back();
            }
        }
        
    }
};