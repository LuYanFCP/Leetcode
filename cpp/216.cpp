#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(temp, res, 1, n, 9, k, 0);
        return res;
    }
    void dfs(vector<int> temp, vector<vector<int>> &res, int idx, int target, int n, int k, int depth)
    {

        if (depth == k) {
            if (target == 0) res.emplace_back(temp);
            return;
        }
        for (int i = idx; i <= n; ++i) {
                // printf("%d==%d, target-i:%d, i+1:%d \n", i, target, target-i, i+1);
            if (target-i >= 0) {  // 剪枝
                temp.push_back(i);
                dfs(temp, res, i+1, target-i, n, k, depth+1);
                temp.pop_back();
            }
        }
    }
};