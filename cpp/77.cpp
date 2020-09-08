#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> res;
        dfs(1, n, k, temp, res);
        return res;
    }
    void dfs(int begin, int end, int depth, vector<int> &temp, vector<vector<int>> &res) {
        if (depth == 0) {
            res.emplace_back(temp);
            return;
        }
        for (int i = begin; i <= end; ++i) {
            temp.push_back(i);
            dfs(i+1, end, depth-1, temp, res);
            temp.pop_back();
        }
    }
};